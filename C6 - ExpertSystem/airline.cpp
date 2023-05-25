#include <iostream>
#include <unordered_map>
using namespace std;

// Define the knowledge base for airline scheduling
unordered_map<string, unordered_map<string, string>> airline_schedule = {
    {"FLIGHT1", {{"origin", "New York"}, {"destination", "Los Angeles"}, {"departure_time", "10:00 AM"}, {"arrival_time", "1:00 PM"}}},
    {"FLIGHT2", {{"origin", "Chicago"}, {"destination", "Miami"}, {"departure_time", "12:30 PM"}, {"arrival_time", "4:30 PM"}}},
    {"FLIGHT3", {{"origin", "Houston"}, {"destination", "Denver"}, {"departure_time", "3:45 PM"}, {"arrival_time", "5:30 PM"}}}
};

// Define the knowledge base for cargo schedules
unordered_map<string, unordered_map<string, string>> cargo_schedule = {
    {"CARGO1", {{"origin", "New York"}, {"destination", "Los Angeles"}, {"departure_time", "8:00 AM"}, {"arrival_time", "10:30 AM"}}},
    {"CARGO2", {{"origin", "Chicago"}, {"destination", "Miami"}, {"departure_time", "10:30 AM"}, {"arrival_time", "1:00 PM"}}},
    {"CARGO3", {{"origin", "Houston"}, {"destination", "Denver"}, {"departure_time", "2:00 PM"}, {"arrival_time", "3:30 PM"}}}
};

// Define the inference engine for airline scheduling
void evaluateAirlineSchedule(const string& flight) {
    if (airline_schedule.find(flight) != airline_schedule.end()) {
        cout << "Flight Schedule Information: " << endl;
        cout << "Flight: " << flight << endl;
        cout << "Origin: " << airline_schedule[flight]["origin"] << endl;
        cout << "Destination: " << airline_schedule[flight]["destination"] << endl;
        cout << "Departure Time: " << airline_schedule[flight]["departure_time"] << endl;
        cout << "Arrival Time: " << airline_schedule[flight]["arrival_time"] << endl;
    } else {
        cout << "Flight not found in the schedule." << endl;
    }
}

// Define the inference engine for cargo schedules
void evaluateCargoSchedule(const string& cargo) {
    if (cargo_schedule.find(cargo) != cargo_schedule.end()) {
        cout << "Cargo Schedule Information: " << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Origin: " << cargo_schedule[cargo]["origin"] << endl;
        cout << "Destination: " << cargo_schedule[cargo]["destination"] << endl;
        cout << "Departure Time: " << cargo_schedule[cargo]["departure_time"] << endl;
        cout << "Arrival Time: " << cargo_schedule[cargo]["arrival_time"] << endl;
    } else {
        cout << "Cargo not found in the schedule." << endl;
    }
}

int main() {
    while (true) {
        // Get user input
        string type;
        cout << "Enter 'A' for airline schedule or 'C' for cargo schedule: ";
        getline(cin, type);

        if (type == "A" || type == "a") {
            string flight_name;
            cout << "Enter a flight name: ";
            getline(cin, flight_name);
            evaluateAirlineSchedule(flight_name);
        } else if (type == "C" || type == "c") {
            string cargo_name;
            cout << "Enter a cargo name: ";
            getline(cin, cargo_name);
            evaluateCargoSchedule(cargo_name);
        } else {
            cout << "Invalid input. Please enter 'A' or 'C'." << endl;
            continue;
        }

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
