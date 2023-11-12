#include <iostream>
#include <vector>
#include <algorithm>

class Patient {
public:
    int id;
    int severity;

    Patient(int patientId, int patientSeverity) : id(patientId), severity(patientSeverity) {}
};

class EmergencyRoom {
private:
    std::vector<Patient> patients;

public:
    void addPatient(int id, int severity) {
        // Check if the patient with the given ID already exists
        auto it = std::find_if(patients.begin(), patients.end(), [id](const Patient& p) {
            return p.id == id;
        });

        if (it == patients.end()) {
            patients.emplace_back(id, severity);
            std::cout << "Patient with ID " << id << " and Severity " << severity << " added.\n";
        } else {
            std::cout << "Patient with ID " << id << " already exists. Please choose a different ID.\n";
        }
    }

    void treatPatient() {
        if (!patients.empty()) {
            // Find the patient with the highest severity
            auto maxSeverityPatient = std::max_element(patients.begin(), patients.end(),
                                                       [](const Patient& p1, const Patient& p2) {
                                                           return p1.severity < p2.severity;
                                                       });

            std::cout << "Treating Patient ID: " << maxSeverityPatient->id
                      << " with Severity: " << maxSeverityPatient->severity << "\n";

            // Remove the treated patient from the vector
            patients.erase(maxSeverityPatient);
        } else {
            std::cout << "No patients to treat.\n";
        }
    }

    void checkStatus() {
        if (!patients.empty()) {
            // Find the patient with the highest severity
            auto maxSeverityPatient = std::max_element(patients.begin(), patients.end(),
                                                       [](const Patient& p1, const Patient& p2) {
                                                           return p1.severity < p2.severity;
                                                       });

            std::cout << "Current Patient with Highest Severity: ID " << maxSeverityPatient->id
                      << " (Severity " << maxSeverityPatient->severity << ")\n";
        } else {
            std::cout << "No patients in the emergency room.\n";
        }
    }
};

int main() {
    EmergencyRoom emergencyRoom;
    int choice, id, severity;

    do {
        std::cout << "Emergency Room Menu:\n";
        std::cout << "1. Add Patient\n";
        std::cout << "2. Treat Patient\n";
        std::cout << "3. Check Current Patient\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Patient ID: ";
                std::cin >> id;
                std::cout << "Enter Severity: ";
                std::cin >> severity;
                emergencyRoom.addPatient(id, severity);
                break;
            case 2:
                emergencyRoom.treatPatient();
                break;
            case 3:
                emergencyRoom.checkStatus();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
