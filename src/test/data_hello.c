#include "test/data_hello.h"
#include "d_field.h"
#include "d_fields.h"
#include "d_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h> 

d_table* table;

int sqlcallback2(void *NotUsed, int argc, char **argv, char **azColName) {
    /*test null*/
    /*argv[2] = 0;*/
    d_table_add_record(table, argv);
    return 0;
}

void sqlite_select()
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
   rc = sqlite3_exec(db, sql, sqlcallback2, (void*)data, &zErrMsg);
   
   if(rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);

}


int data_hello()
{
    d_fields* flds = d_fields_new(3);
    d_fields_set(flds, 0, "Name", FT_STRING, FK_DATA, 100);
    d_fields_set(flds, 1, "Address", FT_STRING, FK_DATA, 100);
    d_fields_set(flds, 2, "Vat", FT_STRING, FK_DATA, 100);

    table = d_table_create(flds);

    sqlite_select();

    int i, j;
    for(i = 0; i < table->record_count - 1; i++)
    {
        for(j = 0; j < table->fields->size; j++)
        {
            d_fields * fields = table->fields;
            const char * field_name = fields->field[j].name;
            char * data = table->records[i].data[j];
            
            printf("rec %d: field %s value: %s\n", i, field_name, data);
        }
    }
    d_table_free(table);
    d_fields_free(flds);
    return 0;
}