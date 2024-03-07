#include <iostream>
#include <ctime>
using namespace std;
struct Node {
    char data;
    Node* next = nullptr;
};

class LinkedList {
private:

    Node* head = nullptr;
public:

    void insert(char data) {
     Node* newNode = new Node();
     newNode->data = data;
     newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << "|"<<(current->data == 'f' ? 'B' : '_') << "|  ";
            current = current->next;
        }
        cout << endl;
    }

 

void availableSeats(int pSize) {
        Node* current = head;

          int c=0;

        while (current != nullptr) {
            if(current->data == 'n' ) //check Available seats
            {
                c++;
                current = current->next;
            }

             else{
                 current = current->next;
               }
        }

      cout<<c<<endl;
      cout<<"Booked seats:"<<pSize-c<<endl; //display booked seats
    }

 

     void calIncome(int pNumber,int pPrize)
     {
          Node* current = head;

        int c=0;

        while (current != nullptr) {
            if(current->data == 'f' ) //check Available seats //f==bookSeat
            {
                c++;
                current = current->next;
            }

             else{
                 current = current->next;
               }
        }

         cout<<"Total Income: \n";
         int total=c* pPrize;
         cout<<"Rs "<<total<<endl;
     }

    Node* getHead() {
        return head;
    }
};

class Bus {
private:

    LinkedList seats;

public:
    void createSeats(int n) {
        for (int i = 0; i < n; i++) {
            seats.insert('n'); // 'n' represents an empty seat
        }
    }

    void bookSeat(int index) {
        Node* current = seats.getHead();
        int count = 1;

        while (current != nullptr) {
            if (count == index && current->data == 'n') {
                current->data = 'f'; // 'f' represents a booked seat
                cout << "\n-------- Seat booking successful --------\n";
                return;

            } else if (count == index && current->data == 'f') {
                cout << "\n***** Alert: Seat is already booked *****\n";
                return;
            }

            current = current->next;
            count++;
        }
        cout << "\n***** Error: Invalid seat number *****\n";
    }

    void cancelSeat(int index) {
        Node* current = seats.getHead();

        int count = 1;

        while (current != nullptr) {
            if (count == index && current->data == 'f') {
                current->data = 'n'; // 'n' represents an empty seat (canceled)
                cout << "\n-------- Seat cancellation successful --------\n";
                return;

            } else if (count == index && current->data == 'n') {
                cout << "\n***** Error: Seat is not booked *****\n";

                return;

            }

            current = current->next;
            count++;
        }

        cout << "\n***** Error: Invalid seat number *****\n";
    }

    void displaySeats() {
        seats.display();
    }

    void availableSeats(int pSize)
     {
        seats.availableSeats(pSize);
     }

     void calIncome(int pNumber,int pPrize)
     {
         seats.calIncome(pNumber,pPrize);
     }

};

//Bus   Registration classes

class BusInfo {
private:

    string busNumber;
    string route;
    string time;
    string seatNumber;

public:
    BusInfo(string _busNumber, string _route,string _time,string _seatNumber)
        : busNumber(_busNumber), route(_route),time(_time),seatNumber(_seatNumber){}

    void display() {

     cout<<"Bus Number     |    Route      |       Time       |        No Of Seats" << "\n";
     cout<< "   "+busNumber+"          |     "+route+"        |        "+time+"        |           "+seatNumber<< "\n";

      /*cout << "Bus Number: " << busNumber << "\n";

        cout << "Route: " << route << "\n";

        cout << "Time: " << time<< "\n";

        cout << "Number Of Seats: " << seatNumber<< "\n"; */

    }

};

class QueueNode {

public:

    BusInfo bus;
    QueueNode* next;
    QueueNode(BusInfo _bus) : bus(_bus), next(nullptr) {}

};

 

 

class BusRegistration {

private:

    QueueNode* front;
    QueueNode* rear;

public:

     BusRegistration() {
        front = rear = nullptr;

    }

    ~ BusRegistration() {

        while (!isEmpty()) {
            dequeue();

        }

    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(BusInfo busInfo) {

        QueueNode* newNode = new QueueNode(busInfo);
        if (rear == nullptr) {
            front = rear = newNode;

        } else {

            rear->next = newNode;
            rear = newNode;
        }

        cout << "Bus registered successfully.\n";

    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Bus queue is empty.\n";
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }

    void displayBusQueue() {

        if (isEmpty()) {

            cout << "Bus queue is empty.\n";
            return;
        }

        cout << "Bus Details:\n";
        int busCount = 1;
        QueueNode* current = front;

        while (current != nullptr) {
            cout << "Bus " << busCount << ":\n";
            current->bus.display();
            current = current->next;
            busCount++;

        }
    }
};

class Menue

{

public:

    int menue()
    {
    int choice;

    cout<<"----Bus Management System-----"<<endl;

    cout<<"1..Bus Registration....\n";

    cout<<"2..Tickets Booking....\n";

    cout<<"Enter Your Choice\n";

    cin>>choice;

    return choice;

    }

};


int main() {

Menue m;

    int choice;
    int n;
    BusRegistration busr;

    while (true) {  // Loop indefinitely until the user chooses to exit

        choice = m.menue();

        if (choice == 1) {

                //BusRegistration busr;

    char ch = 'y';

    while (ch == 'y') {

        cout << "\n------1. Register a bus\n";
        cout << "\n------2. Display bus Details\n";
        cout << "\n------3. Return Main Menu\n";
        cout << "Enter your choice: ";

        int x;

        cin >> x;

        cin.ignore(); // Clear the input buffer

        switch (x) {

            case 1: {
                string busNumber, route,time,seats;
                cout << "Enter bus number: ";
                getline(cin, busNumber);
                cout << "Enter bus route: ";
                getline(cin, route);
                cout << "Enter Bus Start Time: ";
                getline(cin, time);
                cout << "Enter Number Of Seats: ";
                getline(cin, seats);
               busr.enqueue(BusInfo(busNumber, route,time,seats));

                break;

            }

            case 2:

               busr.displayBusQueue();

                break;

            case 3:

                break;

            default:

                cout << "Invalid choice\n";

        }

        cout << "Do you want to continue or not? (y/n)\n";

        cin >> ch;

        cin.ignore(); // Clear the input buffer
        if (ch == 'n') {

                    break; // Exit the loop if 'n' is entered

        }

    }

    cout << "-------Thank You--------"<<endl;

 

        } else if (choice == 2) {

 

           //Display Register bus details

           busr.displayBusQueue();

            //Bus Number

            string bNo,bRoute;

            cout<<"Select Bus Number:";

            cin>>bNo;

 

            //Route

             cout<<"Select  Route:";

             cin>>bRoute;

            // Code for handling choice 1

            cout << "-----Enter the number of seats in the bus-----\n";

            cin >> n;

            Bus bus; //create object

            bus.createSeats(n);

            char ch = 'y';

            while (ch == 'y') {

                // Get the current time

                time_t currentTime = time(nullptr);

                // Convert the current time to a string

                string timeString = ctime(&currentTime);

                // Display the current date and time

                cout << "***" << timeString << "***" << endl;

                cout << "\n-----1. Book a seat-----\n";

                cout << "\n-----2. Available seats or Booked seats-----\n";

                cout << "\n-----3. Cancellation of booked seats-----\n";

                cout << "\n-----4. Display the status of seats-----\n";

                cout << "\n-----5. Display Total Income -----\n";

                cout << "\n-----6. Return Main Menu -----\n";

                int x;

                cout << "\n====Enter your choice====\n";

                cin >> x;

                switch (x) {

                    case 1:

                        int index;
                        cout << "---- Enter the seat number you want to book ----\n";
                        cin >> index;
                        bus.bookSeat(index);
                        break;

                    case 2:

                        cout << "Available seats:\n ";
                        bus.availableSeats(n);
                        break;

                    case 3:

                        int number;
                        cout << "Enter the seat number you want to cancel:\n";
                        cin >> number;
                        bus.cancelSeat(number);
                        break;

                    case 4:

                        cout << "Bus seat status:\n";
                        bus.displaySeats();
                        break;

                    case 5:

                        int prize;
                        cout << "Enter Bus Ticket Prize:\n";
                        cin >> prize;
                        bus.calIncome(n, prize);

                        break;

                    case 6:

                        break;
                    default:
                        cout << "Invalid choice\n";
                }

                cout << "Do you want to continue or not? (y/n)\n";
                cin >> ch;
                if (ch == 'n') {
                    break; // Exit the loop if 'n' is entered
                }
            }
           // cout << "-------Thank You--------";

        } else {
            cout << "....Invalid Choice...." << endl;
            break;  // Exit the loop if an invalid choice is made
        }
    }

    cout << "-------Thank You--------";
    return 0;
}
