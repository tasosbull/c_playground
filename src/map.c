#include <stdlib.h>
#include <string.h>

#include "map.h"

#define MAP_BY_VAL 0
#define MAP_BY_REF 1



Map* mapNew()
{
	Map* map;

	map = malloc(sizeof(Map));
	map->size = 0;
	map->items = NULL;

	return map;
}

void mapAdd(char* key, void* val, Map* map)
{
	char* newkey;

	newkey = malloc(strlen(key) + 1);
	strcpy(newkey, key);

	if (map->size == 0)
	{
		map->items = malloc(sizeof(MapItem));
	}
	else
	{
		map->items = realloc(map->items, sizeof(MapItem) * (map->size + 1));
	}

	(map->items + map->size)->key = newkey;
	(map->items + map->size)->val = val;
	(map->items + map->size++)->type = MAP_BY_VAL;
}

void mapDynAdd(char* key, void* val, Map* map)
{
	mapAdd(key, val, map);
	(map->items + map->size - 1)->type = MAP_BY_REF;
}

void* mapGet(char* key, Map* map)
{
	int i;

	for (i = 0; i < map->size; i++)
	{
		if (strcmp((map->items + i)->key, key) == 0)
		{
			return (map->items + i)->val;
		}
	}

	return NULL;
}

void mapClose(Map* map)
{
	int i = 0;

	for(; i < map->size; i++)
	{
		free((map->items + i)->key);

		if ((map->items + i)->type == MAP_BY_REF)
		{
			free((map->items + i)->val);
		}
	}

	free(map->items);
	free(map);
}