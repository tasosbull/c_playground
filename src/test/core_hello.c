
#include <stdio.h>
#include "test/core_hello.h"
#include "map.h"
#include "core.h"

int core_hello_action(core* m_core, map* prms)
{
    const char* str = (const char*)mapGet("test1", m_core->env);
    printf("env param test1:%s\n", str);
}

int core_hello()
{
    core* m_core = core_new();
    mapAdd( "test1", "hello", m_core->env);
    core_execute_action(m_core, 0, &core_hello_action);
  
  
    mapAdd("testAction", core_hello_action, m_core->actions);
    core_execute_action_by_name(m_core, 0, "testAction");
  
    core_free(m_core);
    return 0;

}
