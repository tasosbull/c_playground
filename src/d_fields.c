
#include "d_fields.h"

#include <stdlib.h>

d_fields* d_fields_new(size_t _size)
{
    d_fields* flds = (d_fields*)malloc(sizeof(d_fields) );
    flds->field = (d_field*)malloc(sizeof(d_field) * _size);
    flds->size = _size;
    return flds;
}

d_field* d_fields_get(d_fields* _fields, int _pos)
{
    return _fields->field + (_pos);
}

d_field* d_fields_set(d_fields* _fields,  
                        int _pos, 
                        const char* _name, 
                        d_field_type _type, 
                        d_field_kind _kind, 
                        size_t _size)
{
    d_field* fld = &_fields->field[_pos];
    fld->name = _name;
    fld->type = _type;
    fld->kind = _kind;
    fld->size = _size;
}

void d_fields_free(d_fields* _fields)
{
    int i;
    for(i = _fields->size - 1; i >= 0; i--)
    {
        d_field* field = &_fields->field[i];
        
        free(field);
    }
    free(_fields);
    
}