#include "test/ini_hello.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handler(void* user, const char* section, const char* name,
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

int ini_hello()
{
    configuration config;
    config.version = 0;  /* set defaults */
    config.name = NULL;
    config.email = NULL;

    if (ini_parse("test.ini", handler, &config) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }
    printf("Config loaded from 'test.ini': version=%d, name=%s, email=%s\n",
        config.version, config.name, config.email);

    if (config.name)
        free((void*)config.name);
    if (config.email)
        free((void*)config.email);
    return 0;
        
}