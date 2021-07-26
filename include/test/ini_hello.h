#ifndef __INI_HELLO_H__
#define __INI_HELLO_H__

#include "ini.h"

typedef struct
{
    int version;
    const char* name;
    const char* email;
} configuration;

int handler(void* user, const char* section, const char* name,
                   const char* value);
            
int ini_hello();


#endif // __INI_HELLO_H__