# OOPD Assignment- 2: 
C++ Programs for Department Management System and Hierarchy.

This assignment contains three C++ programs that solve different problems using object-oriented programming. Each program demonstrates the application of classes, encapsulation, and logic to solve real-world scenarios such as a complaint escalation system, data processing, and input/output handling.

## Q1- IIITD Department Management System

## Description
This program models IIIT Delhi institutional setup by organizing personnel (like Deans, Associate Deans, Registrars) and their respective departments. It allows users to:
- Store and display information about personnel.
- Associate personnel with specific departments.
- Search for a person by name and view their details along with their department.

## Features
- **Person Class**: A base class for storing information such as name, room number, phone number, and email.
- **Dean, Associate Dean, Registrar Classes**: Inherit from `Person` and represent specific roles in the institution.
- **Department Class**: Models a department with a head and staff members.
- **Search Functionality**: Allows searching for a person by name and shows which department they belong to.

## How to Run
1. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp -o question1.cpp
   ./question1.exe

## Q2 - IIITD Organization Structure

## Overview
This C++ program models the hierarchy of a IIITD university's organizational structure, consisting of a **Registrar**, multiple **Heads of Department (HODs)**, and their respective **Faculty members**. It showcases object-oriented programming concepts like inheritance and class composition.

The program allows you to:
- Create and manage faculty members under each HOD.
- Manage HODs under the Registrar.
- Display detailed information about all departments and their faculty.

## Classes
The program is designed using the following classes:

1. **Person**: The base class for all people, holding general information (name, room number, phone number).
2. **Faculty**: Inherits from `Person` and represents a faculty member.
3. **HOD**: Inherits from `Person` and manages up to 4 faculty members.
4. **Registrar**: Inherits from `Person` and manages up to 6 departments (HODs).

## Features
- Display the details of the registrar.
- Display departments (HODs) under the registrar.
- Display faculty members under each department.
- Organize and display information in a readable format.


## How to Run

1. Clone the repository or download the source files.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o academic question2.cpp
   ./academic
   
## Sample Output
```bash
Departments under Registrar Dr. Deepika Bhaskar:
HOD: Sambuddho Chakravarty
Room: C-101
Phone: 91-11-26907420
Department: Computer Science
Faculty under Sambuddho Chakravarty:
Name: Faculty 1
Room: C-102
Phone: 91-11-26907421
...
```

## Q3- IIITD Complaint Escalation System

## Overview
This C++ program implements a **Complaint Escalation System** that manages and escalates complaints based on how many days they have been unresolved. The system follows a hierarchical escalation process, where complaints are first handled by a junior faculty member and then escalate to higher authorities (Head of Department, Registrar) if not resolved within a certain time frame.

## Program Structure

### Classes
1. **Complaint**:
   - Stores information about individual complaints, including the description, handler, number of days open, and escalation level.
   - Automatically escalates complaints based on the number of days unresolved:
     - Day 1-3: **Level 1** handled by **Junior Faculty**.
     - Day 4: **Level 2** escalated to **Head of Department (HOD)**.
     - After Day 4: **Level 3** escalated to the **Registrar**.
   
2. **EscalationMatrix**:
   - Manages a collection of complaints and processes them day by day.
   - Simulates the escalation of unresolved complaints and outputs their current status.

## Escalation Process
- Complaints are automatically escalated through the following levels:
  1. **Level 1**: Handled by Junior Faculty.
  2. **Level 2**: Escalates to Head of Department (HOD) if unresolved after 3 days.
  3. **Level 3**: Escalates to Registrar if unresolved after 4 days.

### Key Functions
- **setDescription**: Set the description of a complaint.
- **setHandler**: Assign the complaint handler.
- **incrementDays**: Simulate the passage of days.
- **escalate**: Escalate a complaint based on how long it has been unresolved.
- **processComplaints**: Process all complaints and escalate as necessary.
- **displayStatus**: Display the current status of a complaint.

## How to Run

1. Clone the repository or download the source files.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o escalation_system question3.cpp
