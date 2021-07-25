#ifndef MAP_H
#define MAP_H

typedef struct mapitem
{
	char* key;
	void* val;
	int type;
} MapItem;

typedef struct map
{
	int size;
	MapItem* items;
} Map;

Map* mapNew();
void mapAdd(char* key, void* val, Map* map);
void mapDynAdd(char* key, void* val, Map* map);
void* mapGet(char* key, Map* map);
void mapClose(Map* map);

#endif