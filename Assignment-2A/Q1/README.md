# IIITD Department Management System

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
