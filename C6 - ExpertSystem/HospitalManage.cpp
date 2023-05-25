#include <iostream>
#include <unordered_map>
using namespace std;

// Define the knowledge base
unordered_map<string, unordered_map<string, string>> knowledge_base = {
    {"HOSPITAL1", {{"location", "City A"}, {"capacity", "100"}, {"services", "General, Surgery"}, {"emergency", "Yes"}}},
    {"HOSPITAL2", {{"location", "City B"}, {"capacity", "200"}, {"services", "Pediatrics, Orthopedics"}, {"emergency", "No"}}},
    {"HOSPITAL3", {{"location", "City C"}, {"capacity", "150"}, {"services", "Cardiology, Neurology"}, {"emergency", "Yes"}}}
};

// Define the inference engine
void evaluateHospital(const string& hospital) {
    if (knowledge_base.find(hospital) != knowledge_base.end()) {
        cout << "Hospital Information: " << endl;
        cout << "Hospital: " << hospital << endl;
        cout << "Location: " << knowledge_base[hospital]["location"] << endl;
        cout << "Capacity: " << knowledge_base[hospital]["capacity"] << endl;
        cout << "Services: " << knowledge_base[hospital]["services"] << endl;
        cout << "Emergency Services: " << knowledge_base[hospital]["emergency"] << endl;
    } else {
        cout << "Hospital not found in the knowledge base." << endl;
    }
}

int main() {
    while (true) {
        // Get user input
        string hospital_name;
        cout << "Enter a hospital name: ";
        getline(cin, hospital_name);

        // Test the system
        evaluateHospital(hospital_name);

        string x;
        cout << "Do you want to continue? (Y or N): ";
        cin >> x;
        cin.ignore(); // Ignore the newline character after cin
        if (x == "Y" || x == "y")
            continue;
        else if (x == "N" || x == "n")
            break;
        else
            cout << "Please enter valid input." << endl;
    }

    return 0;
}
