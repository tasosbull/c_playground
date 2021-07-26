#ifndef __SQLITE_HELLO_H__
#define __SQLITE_HELLO_H__


int sqlcallback(void *NotUsed, int argc, char **argv, char **azColName);
void test_sqlite_create();
void test_sqlite_insert();
void test_sqlite_select();
void test_sqlite_update();
int sqlite_hello(int create, int update);

#endif // __SQLITE_HELLO_H__