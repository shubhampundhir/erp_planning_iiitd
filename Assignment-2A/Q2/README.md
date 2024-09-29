# IIITD Organization Structure

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
