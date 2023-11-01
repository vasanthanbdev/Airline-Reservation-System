#include <iostream>
#include <string>
#include <vector>

using namespace std;


class AirlineReservationSystem {
private:
    class Flight {
    friend class AirlineReservationSystem;
    friend class Ticket;
    private:
        string flightNumber;
        string departureCity;
        string arrivalCity;
        string departureTime;
        string arrivalTime;
        string numberOfSeats;
        string ticketFare;
    
    public:
        Flight(const string& flight_number, const string& departure_city, const string& arraival_city, const string& departure_time, const string& arraival_time, const string& number_of_seats, const string& ticket_fare) {
            flightNumber = flight_number;
            departureCity = departure_city;
            arrivalCity = arraival_city;
            departureTime = departure_time;
            arrivalTime = arraival_time;
            numberOfSeats = number_of_seats;
            ticketFare = ticket_fare;
        }
    };
    vector<Flight> flights;

    class Passenger {
    friend class AirlineReservationSystem;
    friend class Ticket;
    private:
        string passengerId;
        string name;
        string contact;
    
    public:
        Passenger() {
            cout << "\nEnter your passenger id:  "; cin >> passengerId;
            cout << "\nEnter your name:  "; cin >> name;
            cout << "\nEnter your contact:  "; cin >> contact;
        }
    };

    class Ticket {
    friend class AirlineReservationSystem;
    private:
        string passengerId;
        string name; 
        string contact;
        string flightNumber;
        string departureCity;
        string departureTime;
        string ticketFare;

    public:
        Ticket(const Passenger& passenger, const Flight& flight) {
            passengerId = passenger.passengerId;
            name = passenger.name;
            contact = passenger.contact;
            flightNumber = flight.flightNumber;
            departureCity = flight.departureCity;
            departureTime = flight.departureTime;
            ticketFare = flight.ticketFare;
        }
    };
    vector<Ticket> tickets;

public:
    AirlineReservationSystem() {
        // Add sample flights 
        Flight flight1("UA123", "San Francisco", "New York", "08:00", "12:00", "50", "$99");
        Flight flight2("BA456", "London", "Rome", "10:30", "14:00", "100", "$150");

        flights.push_back(flight1);
        flights.push_back(flight2);
    }

    void viewFlights() { 
        cout << "\nFlights:\n";
        
        for (int i = 0; i < flights.size(); i++) {
            cout << "\n" << i + 1 << "." << " " << flights[i].flightNumber << " " << flights[i].departureCity << " " << flights[i].arrivalCity << " " << flights[i].departureTime << " " << flights[i].arrivalTime << " " << flights[i].numberOfSeats << " " << flights[i].ticketFare << endl;
        }
    }


    void bookTicket() {
        cout << "\nSelect the flight you want to book: ";
        int flightIndex;
        cin >> flightIndex;
        
        // create the ticket object
        Flight flight = flights[flightIndex - 1];
        Passenger passenger;
        Ticket ticket(passenger, flight);

        // add ticket object to the vector
        tickets.push_back(ticket);
        cout << "Your Ticket is successfully Booked! view your ticket in the main menu" << endl;
    }

    void viewTicket() {
        // check if tickets are booked
        if (tickets.empty()) {
            cout << "No tickets booked yet" << endl;
            return;
        }

        // get the ticket object
        Ticket ticket = tickets[0];

        // Print the ticket details
        cout << "\nTicket details:" << endl;
        cout << "Passenger ID: " << ticket.passengerId << endl;
        cout << "Name: " << ticket.name << endl;
        cout << "Contact: " << ticket.contact << endl;
        cout << "Flight Number: " << ticket.flightNumber << endl;
        cout << "Departure City: " << ticket.departureCity << endl;
        cout << "Departure Time: " << ticket.departureTime << endl;
        cout << "Ticket Fare: " << ticket.ticketFare << endl;

    }

    void cancelTicket() {
        // check if tickets are booked
        if (tickets.empty()) {
            cout << "No tickets to cancel" << endl;
            return; 
        }

        // remove the ticket from the vector
        tickets.erase(tickets.begin());
        cout << "Your Ticket is cancelled successfully!" << endl;
    }

};


// mainmenu fuction
void mainMenu() {
    AirlineReservationSystem system;

    int choice;
    while (true) {
        cout << "\nMain Menu:" << endl;
        cout << "1. View Flights" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. View Ticket" << endl;
        cout << "4. Cancel Ticket" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // view flights
            system.viewFlights();
        }
        else if (choice == 2) {
            // book Ticket
            system.bookTicket();
        } 
        else if (choice == 3) {
            // view tickets
            system.viewTicket(); 
        }
        else if (choice == 4) {
            // cancel ticket
            system.cancelTicket();
        }
        else if (choice == 5) {
            cout << "\nTHANK YOU" << endl;
            break; 
        }
    }
}


int main() {
    mainMenu();

    return 0;
}