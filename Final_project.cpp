#include <bits/stdc++.h>
using namespace std;

class Room {
private:
    int roomNumber;
    int capacity;
    bool isAvailable;

public:
    Room(int number, int cap) : roomNumber(number), capacity(cap), isAvailable(true) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    int getCapacity() const {
        return capacity;
    }

    bool isRoomAvailable() const {
        return isAvailable;
    }

    void setRoomAvailability(bool availability) {
        isAvailable = availability;
    }
};

class RoomBookingSystem {
private:
    vector<Room> rooms;

public:
    RoomBookingSystem() {
        // Initialize rooms
        rooms.push_back(Room(101,2));
        rooms.push_back(Room(102,3));
        rooms.push_back(Room(103,2));
        rooms.push_back(Room(104,4));
        rooms.push_back(Room(105,6));
        rooms.push_back(Room(106,5));
        rooms.push_back(Room(107,2));
    }


    //Find if rooms are available
    Room* findAvailableRoom(int capacity) {
        for (auto& room : rooms) {
            if (room.isRoomAvailable() && room.getCapacity() >= capacity) {
                cout << "Rooms available are : " << endl;
                for(auto& room:rooms)
                {
                    if(room.getCapacity()==capacity)
                    cout << room.getRoomNumber() << endl;
                }
                return &room;
            }
        }
        return nullptr;
    }


    //Book Room
    void bookRoom(int capacity) {
        Room* room = findAvailableRoom(capacity);
        if (room != nullptr) {
            room->setRoomAvailability(false);
            cout << "Room " << room->getRoomNumber() << " booked successfully." << endl;
        } else {
            cout << "No available room matching the capacity." << endl;
        }
    }


    // Cancel the booking
    void cancelBooking(int roomNumber) {
        for (auto& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                room.setRoomAvailability(true);
                cout << "Booking for room " << roomNumber << " canceled successfully." << endl;
                return;
            }
        }
        cout << "No booking found for room " << roomNumber << "." << endl;
    }


    // Confirm Room Status
    void printRoomStatus() const {
        cout << "Room Status:" << endl;
        for (const auto& room : rooms) {
            cout << "Room " << room.getRoomNumber() << ": ";
            if (room.isRoomAvailable()) {
                cout << "Available with capacity : " <<room.getCapacity() ;
            } else {
                cout << "Booked";
            }
            cout << endl;
        }
    }
};

int main() {
    RoomBookingSystem bookingSystem;

    int choice;
    int capacity;
    int roomNumber;

    do {
        cout << "Menu:" << endl;
        cout << "1. Check Room Availability" << endl;
        cout << "2. Book a Room" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Print Room Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the required capacity: ";
                cin >> capacity;
                if (bookingSystem.findAvailableRoom(capacity) != nullptr) 
                {
                    cout << "Room is available." << endl;
                } 
                else 
                {
                    cout << "No available room matching the capacity." << endl;
                }
                break;
            case 2:
                cout << "Enter the required capacity: ";
                cin >> capacity;
                bookingSystem.bookRoom(capacity);
                break;
            case 3:
                cout << "Enter the room number to cancel booking: ";
                cin >> roomNumber;
                bookingSystem.cancelBooking(roomNumber);
                break;
            case 4:
                bookingSystem.printRoomStatus();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
