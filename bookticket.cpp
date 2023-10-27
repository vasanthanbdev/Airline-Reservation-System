#include <iostream>
#include <vector>

using namespace std;

class Flight;

class BookTicket {
public:
    static void book(Flight& currentFlight, int tickets, int passengerID) {
        // Create passenger detail string
        // Add to flight object
        // Print flight summary and details
    }

    static void cancel(Flight& currentFlight, int passengerID) {
        // Call cancelTicket()
        // Print flight summary and details
    }

    static void print(Flight& f) {
        // Print flight details and passenger details
    }
};

int main() {
    vector<Flight> flights;

    // Create flights
    for (int i = 0; i < 2; i++) {
        flights.push_back(Flight());
    }

    int passengerID = 1;

    while(true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Book ticket logic

        } else if (choice == 2) { 
            // Cancel ticket logic  
        } else if (choice == 3) {
            // Print ticket logic
        }
    }   
}