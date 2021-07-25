

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h> 
#include "map.h"
#include "log.h"
#include "ini.h"
#include "tgc.h"



/***************   tcg    *************************/
static tgc_t gc;

static void test_tgc() {
  void *memory = tgc_alloc(&gc, 1024);
}

/***************   ini    *************************/

typedef struct
{
    int version;
    const char* name;
    const char* email;
} configuration;

static int handler(void* user, const char* section, const char* name,
                   const char* value)
{
    configuration* pconfig = (configuration*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("protocol", "version")) {
        pconfig->version = atoi(value);
    } else if (MATCH("user", "name")) {
        pconfig->name = strdup(value);
    } else if (MATCH("user", "email")) {
        pconfig->email = strdup(value);
    } else {
        return 0;  /* unknown section/name, error */
    }
    return 1;
}

void test_ini()
{
configuration config;
    config.version = 0;  /* set defaults */
    config.name = NULL;
    config.email = NULL;

    if (ini_parse("test.ini", handler, &config) < 0) {
        printf("Can't load 'test.ini'\n");
        return;
    }
    printf("Config loaded from 'test.ini': version=%d, name=%s, email=%s\n",
        config.version, config.name, config.email);

    if (config.name)
        free((void*)config.name);
    if (config.email)
        free((void*)config.email);

    

}

/***************   log    *************************/

void test_log()
{
  log_set_quiet(false);
  log_set_level(LOG_TRACE);
  log_trace("Size of map %d", sizeof(Map));

}


/***************   map    *************************/

void callback()
{
	printf("Hello World !\n");
}


void test_map()
{
	Map* m;

	char *strval;
	int intval;
	void (*funcval)();
	char* dynval = malloc(7);

  double* dblval = malloc(sizeof(double));
  *dblval = 232.555;
	m = mapNew();
	strcpy(dynval, "dynval");

	mapAdd("key 1", "value", m);
	mapDynAdd("key 2", dynval, m);
	mapAdd("key 3", (int*) 21, m); // Casted to avoid warning
	mapAdd("key 4", callback, m);
	mapAdd("key 5", dblval, m);

	strval = mapGet("key 1", m);
	intval = (long) mapGet("key 3", m); // Casted to avoid warning
	funcval = mapGet("key 4", m);
  
	printf("%s\n", strval);
	printf("%d\n", intval);
  printf("%f\n", *((double* )mapGet("key 5", m)));
	funcval();

	mapClose(m);  
}


/***************   sqlite    *************************/
static int sqlcallback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void test_sqlite_create()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, sqlcallback, 0, &zErrMsg);
   
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);

}

void test_sqlite_insert()
{
sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, sqlcallback, 0, &zErrMsg);
   
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);    
}

void test_sqlite_select()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from COMPANY";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, sqlcallback, (void*)data, &zErrMsg);
   
   if(rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);

}

void test_sqlite_update(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create merged SQL statement */
   sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, sqlcallback, (void*)data, &zErrMsg);
   
   if(rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);    
}

int main (int    argc,  char **argv)
{

  tgc_start(&gc, &argc);

  test_tgc();
  

  test_log();
  test_map();
  test_ini();

  //test_sqlite_create();
  //test_sqlite_insert();
  test_sqlite_select();
  //test_sqlite_update();

  tgc_stop(&gc);

  return 0;
}