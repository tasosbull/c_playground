#ifndef SQLITEHELPER
#define SQLITEHELPER

#define CALL_SQLITE(f)                                          \
    {                                                           \
        int i;                                                  \
        i = sqlite3_ ## f;                                      \
        if (i != SQLITE_OK) {                                   \
            fprintf (stderr, "%s failed with status %d: %s\n",  \
                     #f, i, sqlite3_errmsg (db));               \
            exit (1);                                           \
        }                                                       \
    }                                                           \

#define CALL_SQLITE_EXPECT(f,x)                                 \
    {                                                           \
        int i;                                                  \
        i = sqlite3_ ## f;                                      \
        if (i != SQLITE_ ## x) {                                \
            fprintf (stderr, "%s failed with status %d: %s\n",  \
                     #f, i, sqlite3_errmsg (db));               \
            exit (1);                                           \
        }                                                       \
    }                                                           \


#endif /* SQLITEHELPER */

/*
sqlite3 * db;
    char * sql;
    sqlite3_stmt * stmt;
    int i;

    CALL_SQLITE (open ("test.db", & db));
    sql = "INSERT INTO t (xyz) VALUES (?)";
    CALL_SQLITE (prepare_v2 (db, sql, strlen (sql) + 1, & stmt, NULL));
    CALL_SQLITE (bind_text (stmt, 1, "fruit", 6, SQLITE_STATIC));
    CALL_SQLITE_EXPECT (step (stmt), DONE);
    printf ("row id was %d\n", (int) sqlite3_last_insert_rowid (db));
    return 0;
}

*/
