#include <stdlib.h>
#include "d_field.h"

d_field* d_field_new(const char* _name, d_field_type _type, d_field_kind _kind, size_t _size)
{
    d_field* df = malloc(sizeof(d_field));
    df->name = _name;
    df->kind = _kind;
    df->type = _type;
    df->size = _size;
    return df;
}


