#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_COMPLAINTS 10   // Maximum number of complaints
#define MAX_DESCRIPTION 100  // Maximum length of the complaint description
#define MAX_HANDLER 30       // Maximum length of handler name
#define MAX_LEVEL 20         // Maximum length of escalation level

class Complaint {
private:
    char description[MAX_DESCRIPTION];
    char handler[MAX_HANDLER];
    int daysOpen; // Number of days the complaint has been open
    char escalationLevel[MAX_LEVEL];

public:
    Complaint() {
        description[0] = '\0'; // Initialize to an empty string
        handler[0] = '\0';
        daysOpen = 0;
        escalationLevel[0] = '\0';
        snprintf(escalationLevel, sizeof(escalationLevel), "Level 1");
        setHandler("Junior Faculty"); // Initial handler
    }

    void setDescription(const char* desc) {
        snprintf(description, sizeof(description), "%s", desc);
    }

    void setHandler(const char* initHandler) {
        snprintf(handler, sizeof(handler), "%s", initHandler);
    }

    void incrementDays() {
        daysOpen++;
    }

    void escalate() {
        if (daysOpen >= 3 && strcmp(escalationLevel, "Level 1") == 0) {
            snprintf(escalationLevel, sizeof(escalationLevel), "Level 2");
            setHandler("Head of Department"); // Escalate to HOD
        } else if (daysOpen >= 4 && strcmp(escalationLevel, "Level 2") == 0) {
            snprintf(escalationLevel, sizeof(escalationLevel), "Level 3");
            setHandler("Registrar"); // Escalate to Registrar
        }
    }

    void displayStatus(char output[256]) const {
        // Prepare the output for the complaint status
        snprintf(output, 256,
                 "Complaint: %s\n"
                 "Current Handler: %s\n"
                 "Days Open: %d\n"
                 "Escalation Level: %s\n"
                 "--------------------------\n",
                 description, handler, daysOpen, escalationLevel);
    }

    int getDaysOpen() const {
        return daysOpen;
    }
};

class EscalationMatrix {
private:
    Complaint complaints[MAX_COMPLAINTS];
    int complaintCount;

public:
    EscalationMatrix() : complaintCount(0) {}

    void addComplaint(const Complaint& complaint) {
        if (complaintCount < MAX_COMPLAINTS) {
            complaints[complaintCount] = complaint;
            complaintCount++;
        }
    }

    void processComplaints(char output[256]) {
        for (int i = 0; i < complaintCount; i++) {
            complaints[i].incrementDays();  // Simulate the passing of a day
            complaints[i].escalate();       // Check if escalation is needed
            complaints[i].displayStatus(output);  // Prepare current status
            
            // Output the status
            printf("%s", output); // Replace with your own output function if needed
        }
    }
};

int main() {
    EscalationMatrix matrix;
    char output[256];  // Buffer to hold output strings

    // Adding complaints
    Complaint complaint1;
    complaint1.setDescription("Complaint about grading");
    matrix.addComplaint(complaint1);

    Complaint complaint2;
    complaint2.setDescription("Complaint about lab equipment");
    matrix.addComplaint(complaint2);

    // Simulate 4 days to see escalation
    for (int day = 1; day <= 4; day++) {
        // For each day, output the status
        matrix.processComplaints(output);
    }

    return 0;
}
