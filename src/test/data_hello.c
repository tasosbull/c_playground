#include "test/data_hello.h"
#include "d_field.h"
#include "d_fields.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data_hello()
{
    d_fields* flds = d_fields_new(3);
    d_fields_set(flds, 0, "Name", FT_STRING, FK_DATA, 100);
    d_fields_set(flds, 1, "Address", FT_STRING, FK_DATA, 100);
    d_fields_set(flds, 2, "Vat", FT_STRING, FK_DATA, 100);

    int i;
    for(i = 0; i < 3; i++)
        printf("NAME:%s SIZE:%d\n", d_fields_get(flds, i)->name, d_fields_get(flds, i)->size);
    free(flds);
    return 0;
}