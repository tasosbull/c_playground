#ifndef D_TABLE
#define D_TABLE

#include "d_fields.h"
#include "d_record.h"



typedef struct d_table
{
    int idx;
    int record_count;
    d_fields* fields;
    d_record* records;
}d_table;

d_table* d_table_create(d_fields* _fields);
void d_table_add_record(d_table* table, char** data);
void d_table_free(d_table* table);
int d_table_record_count(d_table* table);
int d_table_first(d_table* table);
int d_table_eof(d_table* table);
void d_table_next(d_table* table);
d_record* d_table_get_record(d_table* table);

#endif /* D_TABLE */
