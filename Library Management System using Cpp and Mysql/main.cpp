#include "connection.h"
#include "books.h"
//#include "loans.h"
//#include "members.h"

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Enum for menu choices
enum MenuChoice { MENU_ADD = 1, MENU_LIST, MENU_UPDATE, MENU_REMOVE, MENU_EXIT };

// Display menu
void showMenu() {
    cout << "\n--- Library Management System ---\n";
    cout << "1. Add a new book\n";
    cout << "2. List all books\n";
    cout << "3. Update a book's information\n";
    cout << "4. Remove a book from the library\n";
    cout << "5. Exit\n";
    cout << "---------------------------------\n";
    cout << "Enter your choice: ";
}

// Safe integer input helper
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

int main() {
    // 1. Establish database connection
    MYSQL* conn = createConnection();
    if (!conn) {
        cerr << "Fatal Error: Database connection failed.\n";
        return 1;
    }

    while (true) {
        showMenu();
        int choice = getIntInput("");

        switch (choice) {
            case MENU_ADD: {
                string isbn, title, author, genre, publisher, year;
                cout << "Enter ISBN: "; getline(cin, isbn);
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Genre: "; getline(cin, genre);
                cout << "Enter Publisher: "; getline(cin, publisher);
                cout << "Enter Publication Year: "; getline(cin, year);

                add_book(conn, isbn, title, author, genre, publisher, year);
                break;
            }

            case MENU_LIST:
                book_list(conn);
                break;

            case MENU_UPDATE: {
                int book_id = getIntInput("Enter the ID of the book to update: ");

                string isbn, title, author, genre, publisher, year;
                cout << "Enter new ISBN (leave blank to keep current): "; getline(cin, isbn);
                cout << "Enter new Title (leave blank to keep current): "; getline(cin, title);
                cout << "Enter new Author (leave blank to keep current): "; getline(cin, author);
                cout << "Enter new Genre (leave blank to keep current): "; getline(cin, genre);
                cout << "Enter new Publisher (leave blank to keep current): "; getline(cin, publisher);
                cout << "Enter new Publication Year (leave blank to keep current): "; getline(cin, year);

                update_book(conn, book_id, isbn, title, author, genre, publisher, year);
                break;
            }

            case MENU_REMOVE: {
                int book_id = getIntInput("Enter the ID of the book to remove: ");
                remove_book(conn, book_id);
                break;
            }

            case MENU_EXIT:
                cout << "Exiting the program. Goodbye!\n";
                mysql_close(conn);
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
