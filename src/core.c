#include <stdlib.h>

#include "core.h"


core* core_new(void)
{
    core* m_core = malloc(sizeof(core));
    m_core->env = malloc(sizeof(map));
    return m_core;  
}

void core_free(core* m_core)
{
    if(m_core->env)
    {
        mapClose(m_core->env); 
    }
    free(m_core);
}

int core_execute_action(core* m_core, map* action_prms, int(*action_ptr)(core* , map*))
{
    return (*action_ptr)(m_core, action_prms);
}

