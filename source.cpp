#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


// flight details class
class Flight {
friend class Ticket;

private:
    string flight_no, destination, date, departure_time, fare;
    
public:
    Flight (string flight_no = NULL, string destination = NULL, string date = NULL, string depature_time = NULL, string fare = NULL) {
        this->flight_no = flight_no;
        this->destination = destination;
        this->date = date;
        this->departure_time = departure_time;
        this->fare = fare;
    }
    
};


// Passenger details class
class Passenger {
friend class Ticket;

private:
    string id, name, gender, age, address;

public:
    Passenger () {
        cout << "\nEnter your passenger id:  "; cin >> this->id;
        cout << "\nEnter your name:  "; cin >> this->name;
        cout << "\nEnter your gender:  "; cin >> this->gender;
        cout << "\nEnter your age:  "; cin >> this->age;
        cout << "\nEnter your address:  "; cin >> this->address;
    }
};


// Ticket details class 
class Ticket {
private:
    string flight_no, destination, date, departure_time, fare;
    string passenger_id, passenger_name, passenger_gender, passenger_age, passenger_address;
    int no_of_tickets, total_fare;

public:
    Ticket (Flight flight, Passenger passenger, int no_of_tickets) {
        this->flight_no = flight.flight_no;
        this->destination = flight.destination;
        this->date = flight.date;
        this->departure_time = flight.departure_time;
        this->fare = flight.fare;

        this->passenger_id = passenger.id;
        this->passenger_name = passenger.name;
        this->passenger_gender = passenger.gender;
        this->passenger_age = passenger.age;
        this->passenger_address = passenger.address;

        this->no_of_tickets = no_of_tickets;
        this->total_fare = no_of_tickets * std::stoi(flight.fare);
    }

};

void Ticket::printTicket() {
    stringstream ss;
    ss << "Ticket Details:\n" 
    << "Flight Number: " << flight_no << "\n"
    << "Destination: " << destination << "\n"
    << "Date: " << date << "\n" 
    << "Departure Time: " << departure_time << "\n"
    << "Passenger Name: " << passenger_name << "\n"
    << "Number of Tickets: " << to_string(no_of_tickets) << "\n"
    << "Total Fare: " << to_string(total_fare) << "Rupees" << "\n";  
    cout << ss.str();    
}


// book tickets
void bookTicket () {
    cout << "\nWelcome to VASA Airlines!";
    cout << "\n Flights are available for the below mentioned countries " << endl;
    vector<string> countries = {"USA", "UK", "CANADA", "GERMANY", "DUBAI"};
    for (int i = 0; i < 5; i++) {
        cout << i+1 << ". " << countries[i] << endl;
    }
    cout << "\nchoose a country to book a flight: ";
    int choice1; cin >> choice1;

    if (choice1 == 1) {
        cout << "These are the following flights available right now to USA" << endl;
        cout << "1. ARA-007" << "\t22/10/2023 \t8:00AM \tRS.14000 \t Available tickets - 120" << endl;
        cout << "2. ARA-010" << "\t22/10/2023 \t12:00PM \tRS.14500 \t Available tickets - 120" << endl;
        cout << "3. ARA-011" << "\t22/10/2023 \t4:00PM \tRS.14800 \t Available tickets - 120" << endl;
        cout << "\nchoose the flight you want to book:  ";
        int choice2; cin >> choice2;

        if (choice2 == 1) {
            Flight flight("ARA-007", "USA", "22/10/2023", "8:00AM", "14000");
            Passenger passenger;
            int no_of_tickets;
            cout << "Select the number of tickets you want to book: "; cin >> no_of_tickets; 

            Ticket ticket(flight, passenger, no_of_tickets);
            cout << "your ticket is successfully booked!" << endl;
            ticket.printTicket();
        }
    }


}


// Main Menu function
void mainMenu () {
    cout << "\t               VASA FLIGHTS                 " << endl;
    cout << "\t_______________MAIN MENU_______________" << endl;
    cout << "\t________________________________________\t" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\t  1. book a Flight              |\t" << endl;
    cout << "\t|\t  2. View your Ticket           |\t" << endl;
    cout << "\t|\t  3. Exit                       |\t" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t________________________________________\t" << endl;
    cout << "\n\n\n Enter your choice:  ";
    int choice; cin >> choice;

    switch (choice) {
    case 1:
        bookTicket();
        break;
    
    case 2:
        
        break;
    
    case 3:
        
        break;
    
    case 4:
        cout << "_________THANK YOU_________";
        break;

    default:
        cout << "Enter a valid choice, try again:   ";
        mainMenu();
        break;
    }

}


int main () {
    mainMenu();

    return 0;
}