#include "d_table.h"
#include <stdlib.h>

d_table* d_table_create(d_fields* _fields)
{
    d_table* tbl = malloc(sizeof(d_table));
    tbl->fields = _fields;
    tbl->data = malloc(sizeof(char*) * REC_CAPACITY * _fields->size);
    tbl->current_capacity = REC_CAPACITY;
    tbl->record_count = 0;
}