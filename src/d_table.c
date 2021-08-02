#include "d_table.h"
#include <stdlib.h>
#include <string.h>

d_table* d_table_create(d_fields* _fields)
{
    d_table* tbl = malloc(sizeof(d_table));
    tbl->fields = _fields;
    tbl->records = 0;
    tbl->record_count = 0;
}

void d_table_free(d_table* _table)
{
    
    free(_table);

}

void d_record_free(d_record* record)
{

    
}

void d_table_add_record(d_table* table, char** data)
{
    if(table->records)
    {
        table->records = realloc(table->records, sizeof(d_record) * (table->record_count + 1));
    }
    else{
        table->records = malloc(sizeof(d_record));
    }
    d_record* rec = &(table->records[table->record_count]);
    char** new_data = rec->data;
    new_data = (char**)malloc((table->fields->size + 1) * sizeof(char*));
    new_data[table->fields->size] = NULL; 
    int i;
    size_t n = 0;
    for(i = 0; i < table->fields->size; ++i)
    {
        n = strlen(data[i]) + 1;
        new_data[i] = (char*)malloc(n);
        strcpy(new_data[i],data[i]);
    }
    table->record_count ++;
}