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


void d_record_free(d_table* table, d_record* rec)
{
    int i;
    for(i = table->fields->size - 1; i >= 0; --i)
    {
        free(rec->data[i]);
    }
    free(rec->data);
}

void d_table_free(d_table* table)
{
    int i;
    for(i = table->record_count - 1; i >= 0 ; --i)
        d_record_free(table, &table->records[i]);
    free(table->records);
    free(table);
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
    rec->data = (char**)malloc((table->fields->size ) * sizeof(char*));
    int i;
    size_t n = 0;
    for(i = 0; i < table->fields->size; ++i)
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
    table->record_count ++;
}