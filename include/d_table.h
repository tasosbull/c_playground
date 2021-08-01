#ifndef D_TABLE
#define D_TABLE

#define REC_CAPACITY 10
#include "d_fields.h"

typedef struct d_table
{
    const char* name;
    int record_count;
    int current_capacity;
    d_fields* fields;
    char** data;



}d_table;

d_table* d_table_create(d_fields* _fields);


#endif /* D_TABLE */
