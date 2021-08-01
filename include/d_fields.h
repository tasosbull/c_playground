#ifndef D_FIELDS
#define D_FIELDS

#include "d_field.h"

typedef struct d_fields
{
    int size;
    d_field* fields; 
}d_fields;

d_fields* d_fields_new(int _size);
d_field* d_fields_get(d_fields* _fields, int _pos);
d_field* d_fields_set(d_fields* _fields,  int _pos, const char* _name, d_field_type _type, d_field_kind _kind, int _size);
void d_fields_free(d_fields* _fields);

#endif /* D_FIELDS */
