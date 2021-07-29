#include <stdlib.h>

#include "core.h"


core* core_new(void)
{
    core* m_core = malloc(sizeof(core));
    m_core->env = malloc(sizeof(map));
    m_core->actions = malloc(sizeof(map));
    return m_core;  
}

void core_free(core* m_core)
{
    if(m_core->env)
    {
        mapClose(m_core->env); 
    }
    if(m_core->actions)
    {
        mapClose(m_core->actions); 
    }
    free(m_core);
}

void core_execute_action(core* m_core, map* action_prms, int(*action_ptr)(core* , map*))
{
    (*action_ptr)(m_core, action_prms);
}
void core_execute_action_by_name(core* m_core, map* action_prms, char* action_name)
{
    void (*func_action)(core*, map*);
    func_action = mapGet(action_name, m_core->actions);
    if(func_action)
    {
        func_action(m_core, action_prms);
    }
}

