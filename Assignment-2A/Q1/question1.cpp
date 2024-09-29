#include <cstdio>
#include <cstring>

const int MAX_PEOPLE = 100; // Max number of people
const int MAX_STAFF = 10;   // Max staff per department
const int MAX_NAME_LENGTH = 100; // Max length for strings like name, room, etc.
const int MAX_DEPARTMENTS = 10;  // Max number of departments

class Person {
protected:
    char name[MAX_NAME_LENGTH];
    char roomNumber[MAX_NAME_LENGTH];
    char phoneNumber[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];

public:
    Person() {
        strcpy(name, "");
        strcpy(roomNumber, "");
        strcpy(phoneNumber, "");
        strcpy(email, "");
    }

    Person(const char* pname, const char* room, const char* phone, const char* mail) {
        strcpy(name, pname);
        strcpy(roomNumber, room);
        strcpy(phoneNumber, phone);
        strcpy(email, mail);
    }

    const char* getName() const { return name; }
    const char* getRoomNumber() const { return roomNumber; }
    const char* getPhoneNumber() const { return phoneNumber; }
    const char* getEmail() const { return email; }

    virtual void displayDetails() const {
        printf("Name: %s\nRoom: %s\nPhone: %s\nEmail: %s\n", name, roomNumber, phoneNumber, email);
    }
};

class Dean : public Person {
public:
    Dean() : Person() {}
    Dean(const char* pname, const char* room, const char* phone, const char* mail)
        : Person(pname, room, phone, mail) {}
};

class AssociateDean : public Person {
public:
    AssociateDean() : Person() {}
    AssociateDean(const char* pname, const char* room, const char* phone, const char* mail)
        : Person(pname, room, phone, mail) {}
};

class Registrar : public Person {
public:
    Registrar() : Person() {}
    Registrar(const char* pname, const char* room, const char* phone, const char* mail)
        : Person(pname, room, phone, mail) {}
};

class Department {
private:
    char deptName[MAX_NAME_LENGTH];
    Person* head;
    Person* staff[MAX_STAFF];
    int staffCount;

public:
    Department() : head(nullptr), staffCount(0) {
        strcpy(deptName, "");
    }

    Department(const char* name, Person* head) : head(head), staffCount(0) {
        strcpy(deptName, name);
    }

    void addStaff(Person* person) {
        if (staffCount < MAX_STAFF) {
            staff[staffCount++] = person;
        } else {
            printf("Cannot add more staff to %s. Max capacity reached.\n", deptName);
        }
    }

    void displayDepartment() const {
        printf("Department: %s\nHead: %s\n", deptName, head->getName());
        for (int i = 0; i < staffCount; ++i) {
            staff[i]->displayDetails();
        }
    }

    const char* getDeptName() const {
        return deptName;
    }

    Person* getHead() const { return head; }

    bool isPersonInDepartment(Person* person) const {
        if (head == person) {
            return true;
        }
        for (int i = 0; i < staffCount; ++i) {
            if (staff[i] == person) {
                return true;
            }
        }
        return false;
    }
};

// Function to search for a person by name in a fixed-size array and also display their department
void searchPerson(const char* name, Person* people[], int peopleCount, Department* departments[], int deptCount) {
    Person* foundPerson = nullptr;

    // First, find the person
    for (int i = 0; i < peopleCount; ++i) {
        if (strcmp(people[i]->getName(), name) == 0) {
            foundPerson = people[i];
            people[i]->displayDetails();
            break;
        }
    }

    if (foundPerson) {
        // Now search in which department the person is
        for (int i = 0; i < deptCount; ++i) {
            if (departments[i]->isPersonInDepartment(foundPerson)) {
                printf("Department: %s\n", departments[i]->getDeptName());
                break;
            }
        }
    } else {
        printf("Person not found!\n");
    }
}

int main() {
    // Create a fixed-size array to store people
    Person* people[MAX_PEOPLE];
    int personCount = 0;

    // Create some sample people
    Registrar reg("Dr.Deepika Bhaskar", "B-204", "91-11-26907419", "registrar@iiitd.ac.in");
    Dean deanIRD("Dr.Vivek Ashok Bohara", "A-102", "91-11-26907454", "dird@iiitd.ac.in");
    Dean deanAcademics("Dr.Sumit J Darak", "A-202", "91-11-26907427", "doaa@iiitd.ac.in");
    Dean deanStudentAffairs("Dr.Shobha Sundar Ram", "A-302", "91-11-26907454", "dosa@iiitd.ac.in");
    AssociateDean assocDeanIRD("Dr.Debarka Sengupta", "A-103", "91-11-26907446", "adird@iiitd.ac.in");

    // Add people to the array
    people[personCount++] = &reg;
    people[personCount++] = &deanIRD;
    people[personCount++] = &deanAcademics;
    people[personCount++] = &deanStudentAffairs;
    people[personCount++] = &assocDeanIRD;

    // Create departments
    Department regOffice("Registrar Office", &reg);  // Create Registrar Office and set reg as head
    Department IRD("IRD", &deanIRD);
    IRD.addStaff(&assocDeanIRD);

    Department Academics("Academics", &deanAcademics);
    Department StudentAffairs("Student Affairs", &deanStudentAffairs);

    // Create an array to store departments
    Department* departments[MAX_DEPARTMENTS];
    int deptCount = 0;
    departments[deptCount++] = &regOffice; // Add the Registrar Office to the departments array
    departments[deptCount++] = &IRD;
    departments[deptCount++] = &Academics;
    departments[deptCount++] = &StudentAffairs;

    // Simple search functionality
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the person: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);

    // Remove newline character from fgets
    searchName[strcspn(searchName, "\n")] = '\0';

    searchPerson(searchName, people, personCount, departments, deptCount);

    return 0;
}
