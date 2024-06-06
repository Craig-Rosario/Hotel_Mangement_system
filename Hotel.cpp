#include<bits/stdc++.h>
using namespace std;

const int floors=5;
const int rooms=7;
const int total=floors*rooms;
class Hotel
{
    public:
        int floor_no;
        int room_no;
        int type;
        int avail;

    void room()
    {
        floor_no=0;
        room_no=0;
        type=0;
        avail=0;
    }
    void diplay_room()
    {
        cout<<"The floor number is: "<<floor_no<<endl;
        cout<<"The room number is: "<<room_no<<endl;
        if(type==0)
        {
            cout<<"Room type is NORMAL"<<endl;
        }
        else if(type==1)
        {
            cout<<"Room type is SUITE"<<endl;
        }

        if(avail==0)
        {
            cout<<"Room is EMPTY"<<endl;
        }
        else if(avail==1)
        {
            cout<<"Room is OCCUPIED"<<endl;
        }
    }
};

class Customer
{
    cout<<"HELLO";
};
