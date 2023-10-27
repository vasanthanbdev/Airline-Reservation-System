#include <iostream>
#include <string>
#include <vector>

class Flight {
private:
    static int id; // Flight ID
    int tickets;   // Available tickets 
    int price;     // Ticket price

public:
    std::vector<std::string> passengerDetails; // Passenger details
    std::vector<int> passengerIDs;             // Passenger IDs
    std::vector<int> bookedTickets;            // Booked tickets 
    std::vector<int> passengerCost;            // Passenger cost

    Flight() {
        tickets = 50;
        price = 5000;
        id++;
        flightID = id;
    }

    void addPassenger(std::string detail, int tickets, int ID) {
        // Add passenger details to lists
        // Update tickets, price, refund cost
        // ... 
    }

    void cancelTicket(int ID) {
        // Find passenger index
        // Update tickets, price
        // Calculate refund
        // Remove passenger from lists
        // ...
    }

    void flightSummary() {
        // Print flight summary 
    }

    void printDetails() {
        // Print passenger details
    }  
};

int Flight::id = 0;  // Initialize static variable