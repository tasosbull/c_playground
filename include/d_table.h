#ifndef D_TABLE
#define D_TABLE

#include "d_fields.h"
#include "d_record.h"



typedef struct d_table
{
    int record_count;
    d_fields* fields;
    d_record* records;
}d_table;

d_table* d_table_create(d_fields* _fields);
void d_table_add_record(d_table* _table, char** data);
void d_table_free(d_table* _table);

#endif /* D_TABLE */
