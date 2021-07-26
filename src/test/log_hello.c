#include "log.h"

int log_hello()
{

    log_set_quiet(false);
    log_set_level(LOG_TRACE);
    log_trace("Hello from %s", "logger");
    return 0;

}