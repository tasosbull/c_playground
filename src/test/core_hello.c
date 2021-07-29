
#include <stdio.h>
#include "test/core_hello.h"


int core_hello()
{
    core* m_core = core_new();

    mapAdd( "test1", "hello", m_core->env);
    const char* str = (const char*)mapGet("test1", m_core->env);
    printf("env param test1:%s\n", str);
    core_free(m_core);
    return 0;

}
