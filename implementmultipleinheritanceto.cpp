/*4. Implement Multiple Inheritance to Simulate a Library System
Objective
Create a C++ program using multiple inheritance to simulate a library system. Design two base classes:
-	Book to store book details (title, author, and ISBN).
-	Borrower to store borrower details (name, ID, and borrowed book).
Create a derived class Library that inherits from both Book and Borrower. Use this class to track the borrowing and returning of books.*/
)#include <iostream>
#include <string>
using namespace std;

// Base class for storing book details
class Book {
protected:
    string title;
    string author;
    string ISBN;

public:
    void setBookDetails(const string& t, const string& a, const string& i) {
        title = t;
        author = a;
        ISBN = i;
    }

    void displayBookDetails() const {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

// Base class for storing borrower details
class Borrower {
protected:
    string name;
    string ID;
    string borrowedBook;

public:
    void setBorrowerDetails(const string& n, const string& id) {
        name = n;
        ID = id;
        borrowedBook = "";
    }

    void displayBorrowerDetails() const {
        cout << "Borrower Name: " << name << endl;
        cout << "Borrower ID: " << ID << endl;
        if (!borrowedBook.empty())
            cout << "Borrowed Book: " << borrowedBook << endl;
        else
            cout << "No book currently borrowed.\n";
    }
};

// Derived class inheriting from both Book and Borrower
class Library : public Book, public Borrower {
public:
    void borrowBook() {
        if (!borrowedBook.empty()) {
            cout << "Borrower already has a borrowed book: " << borrowedBook << endl;
            return;
        }
        borrowedBook = title;
        cout << "Book '" << title << "' borrowed successfully by " << name << ".\n";
    }

    void returnBook() {
        if (borrowedBook.empty()) {
            cout << "No book to return.\n";
            return;
        }
        cout << "Book '" << borrowedBook << "' returned successfully by " << name << ".\n";
        borrowedBook = "";
    }
};

int main() {
    Library lib;

    // Set book details
    lib.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");

    // Set borrower details
    lib.setBorrowerDetails("Pranjal", "22bcs50036");

    // Display initial details
    cout << "Initial Details:\n";
    lib.displayBookDetails();
    lib.displayBorrowerDetails();

    // Borrow book
    cout << "\nBorrowing Book:\n";
    lib.borrowBook();
    lib.displayBorrowerDetails();

    // Return book
    cout << "\nReturning Book:\n";
    lib.returnBook();
    lib.displayBorrowerDetails();

    return 0;
}
