#include <stdio.h>
#include <string.h>

const int MAX_NAME_LENGTH = 100; // Max length for strings like name, room, etc.
const int MAX_FACULTY = 4;        // Max faculty members per HOD
const int MAX_HODS = 6;           // Max HODs under registrar

// Base class for all people in the organization
class Person {
protected:
    char name[MAX_NAME_LENGTH];
    char roomNumber[MAX_NAME_LENGTH];
    char phoneNumber[MAX_NAME_LENGTH];

public:
    // Default constructor
    Person() {
        strncpy(name, "Unknown", MAX_NAME_LENGTH);
        strncpy(roomNumber, "Unknown", MAX_NAME_LENGTH);
        strncpy(phoneNumber, "Unknown", MAX_NAME_LENGTH);
    }

    // Parameterized constructor
    Person(const char* pname, const char* room, const char* phone) {
        strncpy(name, pname, MAX_NAME_LENGTH);
        strncpy(roomNumber, room, MAX_NAME_LENGTH);
        strncpy(phoneNumber, phone, MAX_NAME_LENGTH);
    }

    const char* getName() const { return name; }
    const char* getRoomNumber() const { return roomNumber; }
    const char* getPhoneNumber() const { return phoneNumber; }

    void displayDetails() const {
        printf("Name: %s\nRoom: %s\nPhone: %s\n", name, roomNumber, phoneNumber);
    }
};

// Class representing a faculty member
class Faculty : public Person {
public:
    // Default constructor
    Faculty() : Person() {}

    // Parameterized constructor
    Faculty(const char* pname, const char* room, const char* phone)
        : Person(pname, room, phone) {}
};

// Class representing a Head of Department (HOD)
class HOD : public Person {
private:
    Faculty facultyMembers[MAX_FACULTY];
    int facultyCount;
    const char* departmentName;  // Store the department name

public:
    // Default constructor
    HOD() : Person(), facultyCount(0), departmentName("Unknown") {}

    // Parameterized constructor
    HOD(const char* pname, const char* room, const char* phone, const char* deptName)
        : Person(pname, room, phone), facultyCount(0), departmentName(deptName) {}

    void addFaculty(const Faculty& faculty) {
        if (facultyCount < MAX_FACULTY) {
            facultyMembers[facultyCount++] = faculty;
        }
    }

    void displayFacultyContacts() const {
        for (int i = 0; i < facultyCount; ++i) {
            facultyMembers[i].displayDetails();
        }
    }

    void displayDetails() const {
        printf("HOD: %s\nRoom: %s\nPhone: %s\nDepartment: %s\n", name, roomNumber, phoneNumber, departmentName);
        printf("Faculty under %s:\n", name);
        displayFacultyContacts();
    }
};

// Class representing the Registrar
class Registrar : public Person {
private:
    HOD departments[MAX_HODS];
    int departmentCount;

public:
    // Default constructor
    Registrar() : Person(), departmentCount(0) {}

    // Parameterized constructor
    Registrar(const char* pname, const char* room, const char* phone)
        : Person(pname, room, phone), departmentCount(0) {}

    void addHOD(const HOD& hod) {
        if (departmentCount < MAX_HODS) {
            departments[departmentCount++] = hod;
        }
    }

    void displayDepartments() const {
        printf("Departments under Registrar %s:\n", name);
        for (int i = 0; i < departmentCount; ++i) {
            departments[i].displayDetails();
            printf("\n"); // Add space between different HODs
        }
    }
};

int main() {
    // Create the Registrar
    Registrar registrar("Dr. Deepika Bhaskar", "B-204", "91-11-26907419");

    // Create HODs and their faculty members
    HOD hodCSE("Sambuddho Chakravarty", "C-101", "91-11-26907420", "Computer Science");
    hodCSE.addFaculty(Faculty("Faculty 1", "C-102", "91-11-26907421"));
    hodCSE.addFaculty(Faculty("Faculty 2", "C-103", "91-11-26907422"));
    hodCSE.addFaculty(Faculty("Faculty 3", "C-104", "91-11-26907423"));
    hodCSE.addFaculty(Faculty("Faculty 4", "C-105", "91-11-26907424"));

    HOD hodECE("A V Subramanyam", "E-101", "91-11-26907425", "Electronics");
    hodECE.addFaculty(Faculty("Faculty 1", "E-102", "91-11-26907426"));
    hodECE.addFaculty(Faculty("Faculty 2", "E-103", "91-11-26907427"));
    hodECE.addFaculty(Faculty("Faculty 3", "E-104", "91-11-26907428"));
    hodECE.addFaculty(Faculty("Faculty 4", "E-105", "91-11-26907429"));

    HOD hodMath("Kaushik Kalyanaraman", "M-101", "91-11-26907430", "Mathematics");
    hodMath.addFaculty(Faculty("Faculty 1", "M-102", "91-11-26907431"));
    hodMath.addFaculty(Faculty("Faculty 2", "M-103", "91-11-26907432"));
    hodMath.addFaculty(Faculty("Faculty 3", "M-104", "91-11-26907433"));
    hodMath.addFaculty(Faculty("Faculty 4", "M-105", "91-11-26907434"));

    HOD hodSSH("Kiriti Kanjilal", "S-101", "91-11-26907435", "Social Science & Humanity");
    hodSSH.addFaculty(Faculty("Faculty 1", "S-102", "91-11-26907436"));
    hodSSH.addFaculty(Faculty("Faculty 2", "S-103", "91-11-26907437"));
    hodSSH.addFaculty(Faculty("Faculty 3", "S-104", "91-11-26907438"));
    hodSSH.addFaculty(Faculty("Faculty 4", "S-105", "91-11-26907439"));

    HOD hodCB("G P S Raghava", "CB-101", "91-11-26907440", "Computational Biology");
    hodCB.addFaculty(Faculty("Faculty 1", "CB-102", "91-11-26907441"));
    hodCB.addFaculty(Faculty("Faculty 2", "CB-103", "91-11-26907442"));
    hodCB.addFaculty(Faculty("Faculty 3", "CB-104", "91-11-26907443"));
    hodCB.addFaculty(Faculty("Faculty 4", "CB-105", "91-11-26907444"));

    HOD hodHCD("Richa Gupta", "HCD-101", "91-11-26907445", "Human Computer Design");
    hodHCD.addFaculty(Faculty("Faculty 1", "HCD-102", "91-11-26907446"));
    hodHCD.addFaculty(Faculty("Faculty 2", "HCD-103", "91-11-26907447"));
    hodHCD.addFaculty(Faculty("Faculty 3", "HCD-104", "91-11-26907448"));
    hodHCD.addFaculty(Faculty("Faculty 4", "HCD-105", "91-11-26907449"));

    // Add HODs to the registrar
    registrar.addHOD(hodCSE);
    registrar.addHOD(hodECE);
    registrar.addHOD(hodMath);
    registrar.addHOD(hodSSH);
    registrar.addHOD(hodCB);
    registrar.addHOD(hodHCD);

    // Display all departments and their faculty
    registrar.displayDepartments();

    return 0;
}
