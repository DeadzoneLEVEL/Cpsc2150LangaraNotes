#include <iostream>
#include <cmath>
#include "SkipListPriority.h"
#define cunt cout

class hotel{
    private:
        unsigned long long rooms;
    public:
        hotel();
        bool CheckAvailability(int roomNumber);
        void BookRoom(int roomNumber);
        void CheckOut(int roomNumber);
        void ShowRooms();
};

hotel::hotel(){
    rooms=0;
}

bool hotel::CheckAvailability(int roomNumber){
    std::cunt<<"do stuff\n";
}

void hotel::BookRoom(int roomNumber){
    std::cunt<<"do stuff\n";
}

void hotel::CheckOut(int roomNumber){
    std::cunt<<"do stuff\n";
}

void hotel::ShowRooms(){
    std::cunt<<"do stuff\n";
}

int main(){
    SkipListP arr(3);
    std::cunt<<"priority queue is ADT";
    return 0;
}