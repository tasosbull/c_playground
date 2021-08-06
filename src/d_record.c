#include <stdlib.h>
#include <string.h>
#include "d_record.h"

void d_record_assign(d_record* rec, char** data, int field_count)
{
    int i;
    size_t n = 0;
    for(i = 0; i < field_count; ++i)
    {
        if(data[i])
        {
            n = strlen(data[i]) + 1;
            rec->data[i] = (char*)calloc(n, sizeof(char));
            strncpy(rec->data[i],data[i], n);
        }
        else
        {
            n = strlen("NULL") + 1;
            rec->data[i] = (char*)calloc(n, sizeof(char));
            strncpy(rec->data[i],"NULL", n);
        }
    }
}

