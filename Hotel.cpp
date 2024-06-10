#include <bits/stdc++.h>

using namespace std;

class User
{
public:
    string user_name;
    string user_phone_num;
    string user_id;
    int days;

    void input()
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << "Enter your name: ";
        getline(cin, user_name);

        cout << "Enter your phone number: ";
        getline(cin, user_phone_num);

        cout << "Enter your ID number: ";
        getline(cin, user_id);

        cout << "Enter number of days: ";
        cin >> days;
    }

    void display()
    {
        cout << "Name: " << user_name << endl;
        cout << "Phone Number: " << user_phone_num << endl;
        cout << "ID Number: " << user_id << endl;
        cout << "Number of days: " << days << endl;
    }
};

class Room
{
public:
    User user;
    bool isBooked;
    int roomNumber;

    Room()
    {
        isBooked = false;
        roomNumber = 0;
    }

    void book(const User &info)
    {
        user = info;
        isBooked = true;
    }

    void display()
    {
        cout << "Room Number: " << roomNumber << endl;

        if (isBooked)
        {
            cout << "Room is booked by: " << user.user_name << endl;
            cout << "Days: " << user.days << endl;
            cout << "Price: " << (user.days * 1000) << endl;
        }

        else
        {
            cout << "Room is vacant" << endl;
        }
    }
};

class Floor
{
public:
    vector<Room> rooms;

    Floor()
    {

        for (int i = 0; i < 3; ++i)
        {
            rooms.push_back(Room());
            rooms.back().roomNumber = i + 1;
        }
    }

    bool bookRoom(const User &user)
    {
        for (Room &room : rooms)
        {
            if (!room.isBooked)
            {
                room.book(user);
                return true;
            }
        }
        return false;
    }

    void displayRoomInfo(int roomNum)
    {
        for (Room &room : rooms)
        {
            if (room.roomNumber == roomNum)
            {
                room.display();
                return;
            }
        }

        cout << "Room not found" << endl;
    }
};


class Hotel
{
public:
    vector<Floor> floors;

    
    Hotel(int numFloors)
    {
        
        for (int i = 0; i < numFloors; ++i)
        {
            floors.push_back(Floor());
        }
    }

    
    bool bookRoom(const User &user)
    {
        for (Floor &floor : floors)
        {
            if (floor.bookRoom(user))
            {
                cout << "Room booked successfully!\n";
                for (Room &room : floor.rooms)
                {
                    if (room.isBooked && room.user.user_name == user.user_name)
                    {
                        cout << "Room Number: " << room.roomNumber << endl;
                        cout << "Total Price: " << (user.days * 1000) << endl;
                        return true;
                    }
                }
            }
        }

        cout << "All rooms are filled!" << endl;
        return false;
    }

    
    void displayRoomInfo(int roomNum)
    {
        for (Floor &floor : floors)
        {
            for (Room &room : floor.rooms)
            {
                if (room.roomNumber == roomNum)
                {
                    room.display();
                    return;
                }
            }
        }
        cout << "Room not found!" << endl;
    }
};

int main()
{
    Hotel hotel(3);

    while (true)
    {
        cout << "\nOptions:\n1. Booking System\n2. Info System\nEnter your choice (-1 to exit): ";
        int choice;
        cin >> choice;

        if (choice == -1)
            break;

        if (choice == 1)
        {
            User user;
            user.input();

            hotel.bookRoom(user);
        }
        else if (choice == 2)
        {
            int roomNum;
            cout << "Enter room number to get information: ";
            cin >> roomNum;

            hotel.displayRoomInfo(roomNum);
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
