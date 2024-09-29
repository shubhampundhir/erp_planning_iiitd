# IIITD Complaint Escalation System

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

### Escalation Process
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
