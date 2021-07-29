#ifndef MAP_H
#define MAP_H

typedef struct _mapitem
{
	char* key;
	void* val;
	int type;
} mapItem;

typedef struct _map
{
	int size;
	mapItem* items;
} map;

map* mapNew();
void mapAdd(char* key, void* val, map* map);
void mapDynAdd(char* key, void* val, map* map);
void* mapGet(char* key, map* map);
void mapClose(map* map);

#endif