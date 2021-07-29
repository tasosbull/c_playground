#include "test/gtk_hello.h"
#include "test/sqlite_hello.h"
#include "test/ini_hello.h"
#include "test/log_hello.h"
#include "test/map_hello.h"
#include "test/core_hello.h"

static int b_gtk_hello = 0;
static int b_sqlite_hello = 0;
static int b_sqlite_hello_create = 0;
static int b_sqlite_hello_update = 0;
static int b_ini_hello = 0;
static int b_log_hello = 0;
static int b_map_hello = 0;
static int b_core_hello = 1;


int main (int argc, char **argv)
{  
   if(b_gtk_hello)
      return gtk_hello(argc, argv);
   else if(b_sqlite_hello)
      return sqlite_hello(b_sqlite_hello_create, b_sqlite_hello_update);
   else if(b_ini_hello)
      return ini_hello();
   else if(b_log_hello)
         return log_hello();
   else if(b_map_hello)
      return map_hello();
   else if(b_core_hello)
      return core_hello();
   else
      return 0;
}