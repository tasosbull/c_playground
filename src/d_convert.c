#include <stdlib.h>
#include <string.h>
#include "d_convert.h"

int to_int(char* str)
{
    return atoi(str);
}

long to_long(char* str)
{
    return atol(str);
}

double to_double(char* str)
{
    char *ptr;
    return strtod(str, &ptr);
}

float to_float(char* str)
{
    return atof(str);
}