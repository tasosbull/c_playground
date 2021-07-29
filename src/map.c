#include <stdlib.h>
#include <string.h>

#include "map.h"

#define MAP_BY_VAL 0
#define MAP_BY_REF 1



map* mapNew()
{
	map* m_map;

	m_map = malloc(sizeof(map));
	m_map->size = 0;
	m_map->items = NULL;

	return m_map;
}

void mapAdd(char* key, void* val, map* m_map)
{
	char* newkey;

	newkey = malloc(strlen(key) + 1);
	strcpy(newkey, key);

	if (m_map->size == 0)
	{
		m_map->items = malloc(sizeof(mapItem));
	}
	else
	{
		m_map->items = realloc(m_map->items, sizeof(mapItem) * (m_map->size + 1));
	}

	(m_map->items + m_map->size)->key = newkey;
	(m_map->items + m_map->size)->val = val;
	(m_map->items + m_map->size++)->type = MAP_BY_VAL;
}

void mapDynAdd(char* key, void* val, map* m_map)
{
	mapAdd(key, val, m_map);
	(m_map->items + m_map->size - 1)->type = MAP_BY_REF;
}

void* mapGet(char* key, map* m_map)
{
	int i;

	for (i = 0; i < m_map->size; i++)
	{
		if (strcmp((m_map->items + i)->key, key) == 0)
		{
			return (m_map->items + i)->val;
		}
	}

	return NULL;
}

void mapClose(map* m_map)
{
	int i = 0;

	for(; i < m_map->size; i++)
	{
		free((m_map->items + i)->key);

		if ((m_map->items + i)->type == MAP_BY_REF)
		{
			free((m_map->items + i)->val);
		}
	}

	free(m_map->items);
	free(m_map);
}