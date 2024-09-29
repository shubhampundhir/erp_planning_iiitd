#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

// This file contains only the LibraryItem class declaration

class LibraryItem {
public:
    virtual void printDetails() const = 0;  // Pure virtual function
    virtual ~LibraryItem() = default;       // Virtual destructor to ensure proper cleanup
};

#endif  // LIBRARYITEM_H
