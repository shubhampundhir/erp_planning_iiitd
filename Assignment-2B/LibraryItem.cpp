#include <iostream>

class LibraryItem {
public:
    virtual void printDetails() const = 0;  // Pure virtual function
    virtual ~LibraryItem() = default;       // Virtual destructor to ensure proper cleanup
};
