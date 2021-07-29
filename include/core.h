#ifndef CORE
#define CORE

#include "map.h"

typedef struct _core{
    map* env;
    map* actions;
    const char* lastError;
}core;

core* core_new(void);
void core_execute_action(core* m_core, map* action_prms, int(*action_ptr)(core* , map*));
void core_execute_action_by_name(core* m_core, map* action_prms, char* action_name);
void core_free(core* m_core);


#endif /* CORE */
