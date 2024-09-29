#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"  
#include <iostream>
#include <string>

class Library {       
private:    
    static const int MAX_ITEMS = 100; // Maximum items in the library
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;
    
    User students[100]; // Assuming a maximum of 100 students
    int studentCount;
    
    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount;
    
    int ID; // To track the next book ID

public: 
    void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const string &bookTitle, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const string &publicationName, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const string &journalName, Journals *matchingBooks[], int &matchingCount);
    bool borrowBook(const string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool isEqualIgnoreCase(const string &str1, const string &str2);
    bool borrowJournal(const string &userName, int title);
    
    Library() : itemCount(0), studentCount(0), teacherCount(0), ID(0) {       
        nextBookId = 100;
        totalCopies = 1;
    }

    int getStudentCount() const { return studentCount; }
    int getTeacherCount() const { return teacherCount; }
    int getTotalUsers() const { return studentCount + teacherCount; }
    int getTotalItems() const { return itemCount; }

    void addItem(LibraryItem *item) {
        if (itemCount < MAX_ITEMS) {
            libraryItems[itemCount] = item;
            itemCount++;
        } else {
            std::cout << "Library is full. Cannot add more items." << std::endl;
        }
    }

    void printAllItems() const {
        for (int i = 0; i < itemCount; ++i) {
            if (libraryItems[i]) {
                libraryItems[i]->printDetails();
                std::cout << "------------------------\n";
            }
        }
    }

    Book *getBookByID(int bookID) const {
        for (int i = 0; i < itemCount; i++) {
            Book *book = dynamic_cast<Book *>(libraryItems[i]);
            if (book && book->getBookID() == bookID) {
                return book; // Found the book with the specified ID
            }
        }
        return nullptr; // Book with the specified ID not found
    }

    Book *getBookByIsbn(int bookIsbn) const {
        for (int i = 0; i < itemCount; i++) {
            Book *book = dynamic_cast<Book *>(libraryItems[i]);
            if (book && book->getISBN() == bookIsbn) {
                return book; // Found the book with the specified ISBN
            }
        }
        return nullptr; // Book with the specified ISBN not found
    }

    void registerUser(const std::string &name, bool isTeacher) {
        if (isTeacher) {
            teachers[teacherCount++] = User(name, true);
            std::cout << "Registered as a Teacher." << std::endl;
        } else {
            students[studentCount++] = User(name, false);
            std::cout << "Registered as a Student." << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }

    void showAllRegisteredUsers() {
        std::cout << "Registered Students:" << std::endl;
        for (int i = 0; i < studentCount; ++i) {
            std::cout << students[i].getName() << std::endl;
        }

        std::cout << "Registered Teachers:" << std::endl;
        for (int i = 0; i < teacherCount; ++i) {
            std::cout << teachers[i].getName() << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }

    void addBook(int isbn, const std::string &author, const std::string &title, int originalPublicationYear) {
        if (itemCount >= MAX_ITEMS) {
            std::cout << "The library is full. Cannot add more books." << std::endl;
            return;
        }

        // Create a new Book object with the next available book ID
        Book *newBook = new Book();
        newBook->setID(ID++);
        newBook->setBookID(nextBookId++);
        newBook->setISBN(isbn);
        newBook->setAuthors(author);
        newBook->setTitle(title);
        newBook->setPublicationYear(originalPublicationYear);

        // Add the new book to the library
        addItem(newBook);

        std::cout << "Added book with ID " << newBook->getBookID() << " to the library." << std::endl;
    }

    virtual ~Library() {} // Virtual destructor
};

#endif //LIBRARY_H
