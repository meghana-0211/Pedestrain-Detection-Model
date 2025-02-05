#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;

    Book(int id, string title, string author, int year) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->year = year;
    }

    void display() {
        cout << "Book ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nYear: " << year << "\n";
        cout << "----------------------------\n";
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, string title, string author, int year) {
        books.push_back(Book(id, title, author, year));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        for (const auto& book : books) {
            book.display();
        }
    }

    void searchBook(int id) {
        for (const auto& book : books) {
            if (book.id == id) {
                cout << "Book found:\n";
                book.display();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice, id, year;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Delete Book";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Year: "; cin >> year;
                lib.addBook(id, title, author, year);
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                cout << "Enter Book ID to search: "; cin >> id;
                lib.searchBook(id);
                break;
            case 4:
                cout << "Enter Book ID to delete: "; cin >> id;
                lib.deleteBook(id);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
