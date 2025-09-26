#ifndef BOOKS_H
#define BOOKS_H

#include <mysql.h>
#include <string>
#include <sstream>

// Function to add a new book into the table
void add_book(MYSQL* conn, const std::string &isbn, const std::string &title,
              const std::string &author, const std::string &genre,
              const std::string &publisher, const std::string &publication_year);

// Function to list all books
void book_list(MYSQL* conn);

// Function to update book info
void update_book(MYSQL* conn, int book_id, const std::string &isbn,
                 const std::string &title, const std::string &author,
                 const std::string &genre, const std::string &publisher,
                 const std::string &publication_year);

// Function to delete a book from library
void remove_book(MYSQL* conn, int book_id);

// Optional: Function to search books from main library
// void search_main(MYSQL* conn, const std::string &title);

#endif // BOOKS_H

//#ifndef BOOKS_H
//#define BOOKS_H
//
//#include<mysql.h>
//#include<string>
//
//
////function to add new book into table
//void addbooks(MYSQL* conn, const std::string &isbn, const std::string &title, const std::string &author, const std::string &genre, const std::string &publisher, const std::string &publication_year);
//
////function to see all books info
//void book_list(MYSQL* conn);
//
////function to update books info
//void update_book(MYSQL* conn, int book_id,const std::string &isbn, const std::string &title, const std::string &author, const std::string &genre, const std::string &publisher, const std::string &publication_year);
//
////funtion to delete books from library
//void remove_book(MYSQL *conn, int id);
//
////search books from main library
////void search_main(MYSQL *conn, const std::string &title);
//
//#endif //BOOKS_H