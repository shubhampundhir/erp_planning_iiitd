#include "LibraryItem.h"  // Ensure that the LibraryItem base class is included
#include <iostream>
#include <string>  // Include <string> since you're using the string type

using namespace std;

class PublicationRank : public LibraryItem
{
private:
    int ID;
    string publication;
    int rank;
    double totalPaid;
    bool borrowed;

public:
    // Constructor
    PublicationRank(int ID, const string &publication, int rank, double totalPaid)
        : ID(ID), publication(publication), rank(rank), totalPaid(totalPaid), borrowed(false) {}

    // Getter functions
    int getID() const { return ID; }
    string getPublication() const { return publication; }
    int getRank() const { return rank; }
    double getTotalPaid() const { return totalPaid; }
    bool isBorrowed() const { return borrowed; }

    // Setter for the borrowed status
    void setBorrowed(bool status) { borrowed = status; }

    // Overriding the pure virtual function from LibraryItem
    void printDetails() const override {
        cout << "ID: " << ID << "\nPublication Name: " << publication << "\nRank: " << rank << "\nTotal Paid: " << totalPaid << "\n";
    }
};