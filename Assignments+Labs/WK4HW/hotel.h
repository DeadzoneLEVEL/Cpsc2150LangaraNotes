#include <iostream>
#include<cmath>
#ifndef HOTEL_H
#define HOTEL_H

class hotel{
    private:
        unsigned long long rooms;
    public:
        hotel();
        hotel(int val);
        bool CheckAvailability(int roomNumber);
        void BookRoom(int roomNumber);
        void CheckOut(int roomNumber);
        void ShowRooms();
        void ShowCurrent(unsigned long long);
};
hotel::hotel(){
    rooms=0;
}
hotel::hotel(int val){
    rooms=val;
}

bool hotel::CheckAvailability(int roomNumber){
    if(roomNumber>=1&&roomNumber<=60){
        unsigned long long x=rooms;
        x >>=roomNumber;
        return (x&1);
    }else{
        std::cerr<<"Room does not fall between 1-60 range\n";
        return false;
    }
}

void hotel::BookRoom(int roomNumber){
    if(roomNumber>=1&&roomNumber<=60){
        unsigned long long pows=1;
        rooms |= (pows<<(roomNumber));
        std::cout<<"Room "<<roomNumber<<" has been booked.\n";
    }else{
        std::cerr<<"Room does not fall between 1-60 range\n";
        return;
    }
}

void hotel::CheckOut(int roomNumber){
    if(roomNumber>=1&&roomNumber<=60){
        unsigned long long pows=1;
        rooms= rooms & ~(pows<<(roomNumber));
        std::cout<<"Room "<<roomNumber<<" has been unbooked.\n";
    }else{
        std::cerr<<"Room does not fall between 1-60 range\n";
        return;
    }
}

void hotel::ShowRooms(){
    unsigned long long x=rooms,y=1;
    int counter=60;
    for(unsigned long long i=(y<<59);i!=0;i>>=1){
        x>>=1;
        if((x&1)){
            counter-=1;
        }
    }
    x=rooms;
    std::cout<<"Amount of available rooms: "<<counter<<"\n";
    counter=1;
    y=1;
    for(unsigned long long i=(y<<59);i!=0;i>>=1){
        x>>=1;
        std::cout<<"Room "<<counter<<": ";
        std::cout<<(x&1)<<"\n";
        counter+=1;
    }
    
}

void hotel::ShowCurrent(unsigned long long t){
    unsigned long long x=t;
    std::cout<<"\n{ ";
    for(int i=0;i<60;i++){
        std::cout<<(x&1)<<" ";
        x>>=1;
    }
    std::cout<<"}\n";
}

#endif