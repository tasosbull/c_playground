#ifndef D_RECORD
#define D_RECORD

typedef struct d_record
{
    char** data;
}d_record;

void d_record_assign(d_record* rec, char** data, int field_count);


#endif /* D_RECORD */
