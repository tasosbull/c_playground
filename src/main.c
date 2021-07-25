

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "log.h"
#include "ini.h"



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

void test_log()
{
  log_set_quiet(false);
  log_set_level(LOG_TRACE);
  log_trace("Size of map %d", sizeof(Map));

}

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


int
main (int    argc,
      char **argv)
{
  test_log();
  test_map();
  test_ini();

  return 0;
}