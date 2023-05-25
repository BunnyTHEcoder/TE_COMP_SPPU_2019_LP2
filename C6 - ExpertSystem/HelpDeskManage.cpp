#include <iostream>
#include <unordered_map>
using namespace std;

// Define the knowledge base
unordered_map<string, unordered_map<string, string>> knowledge_base = {
    {"HELPDESK1", {{"location", "Floor 1"}, {"capacity", "10"}, {"staff", "5"}, {"availability", "Open"}}},
    {"HELPDESK2", {{"location", "Floor 2"}, {"capacity", "8"}, {"staff", "4"}, {"availability", "Closed"}}},
    {"HELPDESK3", {{"location", "Floor 3"}, {"capacity", "12"}, {"staff", "6"}, {"availability", "Open"}}}
};

// Define the inference engine
void evaluateHelpDesk(const string& helpdesk) {
    if (knowledge_base.find(helpdesk) != knowledge_base.end()) {
        cout << "Help Desk Information: " << endl;
        cout << "Help Desk: " << helpdesk << endl;
        cout << "Location: " << knowledge_base[helpdesk]["location"] << endl;
        cout << "Capacity: " << knowledge_base[helpdesk]["capacity"] << endl;
        cout << "Staff Count: " << knowledge_base[helpdesk]["staff"] << endl;
        cout << "Availability: " << knowledge_base[helpdesk]["availability"] << endl;
    } else {
        cout << "Help Desk not found in the knowledge base." << endl;
    }
}

int main() {
    while (true) {
        // Get user input
        string helpdesk_name;
        cout << "Enter a help desk name: ";
        getline(cin, helpdesk_name);

        // Test the system
        evaluateHelpDesk(helpdesk_name);

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
