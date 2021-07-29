#include "test/map_hello.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void callback(int x, int y)
{
	printf("Hello World !%d  %d\n", x, y);
	
}

int map_hello()
{
	map* m;

	char *strval;
	int intval;
	void (*funcval)(int, int);
	char* dynval = malloc(7);

    double* dblval = malloc(sizeof(double));
    *dblval = 232.555;
	m = mapNew();
	strcpy(dynval, "dynval");

	mapAdd("key 1", "value", m);
	mapDynAdd("key 2", dynval, m);
	mapAdd("key 3", (int*) 21, m); // Casted to avoid warning
	mapAdd("key 4", callback, m);
	mapAdd("key 5", dblval, m);

	strval = mapGet("key 1", m);
	intval = (long) mapGet("key 3", m); // Casted to avoid warning
	funcval = mapGet("key 4", m);
  
	printf("%s\n", strval);
	printf("%d\n", intval);
    printf("%f\n", *((double* )mapGet("key 5", m)));
	funcval(4, 14);

	mapClose(m);  
    return 0;
}