#include<mysql.h>
#include"connection.h"
#include<iostream>

MYSQL* createConnection() {
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        std::cerr << "mysql_init() failed" << std::endl;
        return NULL;
    }

    // --- !! EDIT THESE DETAILS !! ---
    const char* server = "localhost";
    const char* user = "librarian";
    const char* password = "librarian"; // <-- IMPORTANT: REPLACE THIS
    const char* database = "lmsdb";
    // ---------------------------------

    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
        std::cerr << "mysql_real_connect() failed: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return NULL;
    }
    
    std::cout << "Successfully connected to the database." << std::endl;
    return conn;
}