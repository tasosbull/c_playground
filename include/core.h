#ifndef __CORE_H__
#define __CORE_H__

#include "map.h"

typedef struct _core{
    map* env;
    const char* lastError;
}core;

core* core_new(void);
int core_execute_action(core* m_core, map* action_prms, int(*action_ptr)(core* , map*));
void core_free(core* m_core);


#endif // __CORE_H__