#ifndef D_FIELD
#define D_FIELD



typedef enum d_field_kind
{
    FK_DATA,
    FK_CALC
}d_field_kind;

typedef enum d_field_type
{
    FT_STRING,
    FT_INT,
    FT_FLOAT,
    FT_DOUBLE,
    FT_BLOB
}d_field_type;


typedef struct d_field
{
    const char* name;
    d_field_type type;
    d_field_kind kind;
    int size;

}d_field;

d_field* d_field_new(const char* _name, d_field_type _type, d_field_kind _kind, int _size);

#endif /* D_FIELD */
