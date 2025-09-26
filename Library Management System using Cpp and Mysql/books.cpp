#include "books.h"
//#include "connection.h"
#include <iostream>
#include <sstream>
#include <string>
#include <mysql.h>
#include <iomanip>

// Function to add a new book into the table
void add_book(MYSQL* conn, const std::string &isbn, const std::string &title, const std::string &author,
              const std::string &genre, const std::string &publisher, const std::string &publication_year) {
    std::string query = "INSERT INTO books (isbn, title, author, genre, publisher, publication_year) VALUES ('" 
                      + isbn + "', '" + title + "', '" + author + "', '" + genre + "', '" 
                      + publisher + "', '" + publication_year + "')";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "MySQL Query Error: " << mysql_error(conn) << std::endl;
    } else {
        std::cout << "Book '" << title << "' added successfully!" << std::endl;
    }
}

// Function to list all books
void book_list(MYSQL* conn) {
    if (mysql_query(conn, "SELECT * FROM books")) {
        std::cerr << "SELECT query failed: " << mysql_error(conn) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        std::cerr << "mysql_store_result failed: " << mysql_error(conn) << std::endl;
        return;
    }

    const int ID_WIDTH        = 10;
    const int ISBN_WIDTH      = 15;
    const int TITLE_WIDTH     = 25;
    const int AUTHOR_WIDTH    = 15;
    const int GENRE_WIDTH     = 15;
    const int PUBLISHER_WIDTH = 20;
    const int YEAR_WIDTH      = 10;

    std::cout << std::left
              << std::setw(ID_WIDTH) << "book_id"
              << std::setw(ISBN_WIDTH) << "isbn"
              << std::setw(TITLE_WIDTH) << "title"
              << std::setw(AUTHOR_WIDTH) << "author"
              << std::setw(GENRE_WIDTH) << "genre"
              << std::setw(PUBLISHER_WIDTH) << "publisher"
              << std::setw(YEAR_WIDTH) << "publication_year" << std::endl;

    std::cout << std::string(ID_WIDTH + ISBN_WIDTH + TITLE_WIDTH + AUTHOR_WIDTH + GENRE_WIDTH + PUBLISHER_WIDTH + YEAR_WIDTH, '-') << std::endl;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        std::cout << std::left
                  << std::setw(ID_WIDTH) << (row[0] ? row[0] : "NULL")
                  << std::setw(ISBN_WIDTH) << (row[1] ? row[1] : "NULL")
                  << std::setw(TITLE_WIDTH) << (row[2] ? row[2] : "NULL")
                  << std::setw(AUTHOR_WIDTH) << (row[3] ? row[3] : "NULL")
                  << std::setw(GENRE_WIDTH) << (row[4] ? row[4] : "NULL")
                  << std::setw(PUBLISHER_WIDTH) << (row[5] ? row[5] : "NULL")
                  << std::setw(YEAR_WIDTH) << (row[6] ? row[6] : "NULL") << std::endl;
    }

    mysql_free_result(result);
}

// Function to update book info
void update_book(MYSQL* conn, int book_id, const std::string &isbn, const std::string &title, const std::string &author,
                 const std::string &genre, const std::string &publisher, const std::string &publication_year) {
    std::string query = "UPDATE books SET "
                      + std::string("isbn = '") + isbn + "', "
                      + "title = '" + title + "', "
                      + "author = '" + author + "', "
                      + "genre = '" + genre + "', "
                      + "publisher = '" + publisher + "', "
                      + "publication_year = '" + publication_year + "' "
                      + "WHERE book_id = " + std::to_string(book_id);

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "UPDATE query failed: " << mysql_error(conn) << std::endl;
        return;
    }

    if (mysql_affected_rows(conn) > 0) {
        std::cout << "Book with ID " << book_id << " updated successfully." << std::endl;
    } else {
        std::cout << "No book found with ID " << book_id << ". Nothing updated." << std::endl;
    }
}

// Function to delete a book from library
void remove_book(MYSQL *conn, int book_id) {
    std::stringstream query;
    query << "DELETE FROM books WHERE book_id = " << book_id;

    if (mysql_query(conn, query.str().c_str())) {
        std::cerr << "DELETE failed: " << mysql_error(conn) << std::endl;
    } else if (mysql_affected_rows(conn) > 0) {
        std::cout << "Book with ID " << book_id << " deleted successfully." << std::endl;
    } else {
        std::cout << "No book found with ID " << book_id << ". Nothing deleted." << std::endl;
    }
}

//#include "books.h"
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <mysql.h>
//#include <iomanip>
//#include <vector>
//
//using namespace std;
//
//// Helper: Escape strings for SQL
//string escape_string(MYSQL* conn, const string& input) {
//    vector<char> buffer(input.length() * 2 + 1);
//    mysql_real_escape_string(conn, buffer.data(), input.c_str(), input.length());
//    return string(buffer.data());
//}
//
//// Add a new book
//void add_book(MYSQL* conn, const string& isbn, const string& title,
//              const string& author, const string& genre,
//              const string& publisher, const string& publication_year) {
//    
//    stringstream query;
//    query << "INSERT INTO books (isbn, title, author, genre, publisher, publication_year) VALUES ('"
//          << escape_string(conn, isbn) << "', '"
//          << escape_string(conn, title) << "', '"
//          << escape_string(conn, author) << "', '"
//          << escape_string(conn, genre) << "', '"
//          << escape_string(conn, publisher) << "', '"
//          << escape_string(conn, publication_year) << "')";
//
//    if (mysql_query(conn, query.str().c_str())) {
//        cerr << "[ERROR] Failed to insert book: " << mysql_error(conn) << endl;
//    } else {
//        cout << "[OK] Book '" << title << "' added successfully.\n";
//    }
//}
//
//// List all books
//void list_books(MYSQL* conn) {
//    if (mysql_query(conn, "SELECT * FROM books")) {
//        cerr << "[ERROR] SELECT query failed: " << mysql_error(conn) << endl;
//        return;
//    }
//
//    MYSQL_RES* result = mysql_store_result(conn);
//    if (!result) {
//        cerr << "[ERROR] mysql_store_result failed: " << mysql_error(conn) << endl;
//        return;
//    }
//
//    const int NUM_COLS = 7;
//    const int WIDTHS[NUM_COLS] = {10, 15, 25, 20, 15, 20, 12};
//    const char* HEADERS[NUM_COLS] = {"book_id", "isbn", "title", "author", "genre", "publisher", "year"};
//
//    for (int i = 0; i < NUM_COLS; i++)
//        cout << left << setw(WIDTHS[i]) << HEADERS[i];
//    cout << "\n" << string(117, '-') << "\n";
//
//    MYSQL_ROW row;
//    while ((row = mysql_fetch_row(result))) {
//        for (int i = 0; i < NUM_COLS; i++)
//            cout << left << setw(WIDTHS[i]) << (row[i] ? row[i] : "NULL");
//        cout << "\n";
//    }
//
//    mysql_free_result(result);
//}
//
//// Update a book (ignore empty fields)
//void update_book(MYSQL* conn, int book_id, const string& isbn, const string& title,
//                 const string& author, const string& genre,
//                 const string& publisher, const string& publication_year) {
//    
//    stringstream query;
//    query << "UPDATE books SET ";
//    bool first = true;
//
//    auto add_field = [&](const string& name, const string& value) {
//        if (!value.empty()) {
//            if (!first) query << ", ";
//            query << name << "='" << escape_string(conn, value) << "'";
//            first = false;
//        }
//    };
//
//    add_field("isbn", isbn);
//    add_field("title", title);
//    add_field("author", author);
//    add_field("genre", genre);
//    add_field("publisher", publisher);
//    add_field("publication_year", publication_year);
//
//    query << " WHERE book_id=" << book_id;
//
//    if (mysql_query(conn, query.str().c_str())) {
//        cerr << "[ERROR] UPDATE failed: " << mysql_error(conn) << endl;
//    } else if (mysql_affected_rows(conn) > 0) {
//        cout << "[OK] Book ID " << book_id << " updated successfully.\n";
//    } else {
//        cout << "[INFO] No book found with ID " << book_id << ".\n";
//    }
//}
//
//// Remove a book
//void remove_book(MYSQL* conn, int book_id) {
//    stringstream query;
//    query << "DELETE FROM books WHERE book_id=" << book_id;
//
//    if (mysql_query(conn, query.str().c_str())) {
//        cerr << "[ERROR] DELETE failed: " << mysql_error(conn) << endl;
//    } else if (mysql_affected_rows(conn) > 0) {
//        cout << "[OK] Book ID " << book_id << " deleted successfully.\n";
//    } else {
//        cout << "[INFO] No book found with ID " << book_id << ".\n";
//    }
//}
//
//
////#include "books.h"
////#include <iostream>
////#include <sstream>
////#include <string>
////#include <mysql.h>
////#include <iomanip>
////
////using namespace std;
////
////// Helper: escape strings before inserting into SQL
////string escape_string(MYSQL* conn, const string& input) {
////    char* buffer = new char[input.length() * 2 + 1]; // max expansion
////    mysql_real_escape_string(conn, buffer, input.c_str(), input.length());
////    string escaped(buffer);
////    delete[] buffer;
////    return escaped;
////}
////
////// Add a new book
////void add_book(MYSQL* conn, const string& isbn, const string& title,
////              const string& author, const string& genre,
////              const string& publisher, const string& publication_year) {
////    
////    stringstream query;
////    query << "INSERT INTO books (isbn, title, author, genre, publisher, publication_year) VALUES ('"
////          << escape_string(conn, isbn) << "', '"
////          << escape_string(conn, title) << "', '"
////          << escape_string(conn, author) << "', '"
////          << escape_string(conn, genre) << "', '"
////          << escape_string(conn, publisher) << "', '"
////          << escape_string(conn, publication_year) << "')";
////
////    if (mysql_query(conn, query.str().c_str())) {
////        cerr << "[ERROR] Failed to insert book: " << mysql_error(conn) << endl;
////    } else {
////        cout << "[OK] Book '" << title << "' added successfully.\n";
////    }
////}
////
////// List all books
////void list_books(MYSQL* conn) {
////    if (mysql_query(conn, "SELECT * FROM books")) {
////        cerr << "[ERROR] SELECT query failed: " << mysql_error(conn) << endl;
////        return;
////    }
////
////    MYSQL_RES* result = mysql_store_result(conn);
////    if (!result) {
////        cerr << "[ERROR] mysql_store_result failed: " << mysql_error(conn) << endl;
////        return;
////    }
////
////    const int WIDTHS[]   = {10, 15, 25, 20, 15, 20, 12};
////    const char* HEADERS[] = {"book_id", "isbn", "title", "author", "genre", "publisher", "year"};
////
////    // Print header
////    for (int i = 0; i < 7; i++)
////        cout << left << setw(WIDTHS[i]) << HEADERS[i];
////    cout << "\n" << string(117, '-') << "\n";
////
////    MYSQL_ROW row;
////    while ((row = mysql_fetch_row(result))) {
////        for (int i = 0; i < 7; i++)
////            cout << left << setw(WIDTHS[i]) << (row[i] ? row[i] : "NULL");
////        cout << "\n";
////    }
////
////    mysql_free_result(result);
////}
////
////// Update a book
////void update_book(MYSQL* conn, int book_id, const string& isbn, const string& title,
////                 const string& author, const string& genre,
////                 const string& publisher, const string& publication_year) {
////    
////    stringstream query;
////    query << "UPDATE books SET "
////          << "isbn='" << escape_string(conn, isbn) << "', "
////          << "title='" << escape_string(conn, title) << "', "
////          << "author='" << escape_string(conn, author) << "', "
////          << "genre='" << escape_string(conn, genre) << "', "
////          << "publisher='" << escape_string(conn, publisher) << "', "
////          << "publication_year='" << escape_string(conn, publication_year) << "' "
////          << "WHERE book_id=" << book_id;
////
////    if (mysql_query(conn, query.str().c_str())) {
////        cerr << "[ERROR] UPDATE failed: " << mysql_error(conn) << endl;
////    } else if (mysql_affected_rows(conn) > 0) {
////        cout << "[OK] Book ID " << book_id << " updated successfully.\n";
////    } else {
////        cout << "[INFO] No book found with ID " << book_id << ".\n";
////    }
////}
////
////// Delete a book
////void remove_book(MYSQL* conn, int book_id) {
////    stringstream query;
////    query << "DELETE FROM books WHERE book_id=" << book_id;
////
////    if (mysql_query(conn, query.str().c_str())) {
////        cerr << "[ERROR] DELETE failed: " << mysql_error(conn) << endl;
////    } else if (mysql_affected_rows(conn) > 0) {
////        cout << "[OK] Book ID " << book_id << " deleted successfully.\n";
////    } else {
////        cout << "[INFO] No book found with ID " << book_id << ".\n";
////    }
////}
