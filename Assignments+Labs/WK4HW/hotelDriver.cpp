#include<iostream>
#include "hotel.h"

void Menu(hotel htl){
    int control=0;
    int pickwheel=0;
    std::cout<<"\tMENU\t\n";
    std::cout<<"0:Exit program\n";
    std::cout<<"1:Show rooms\n";
    std::cout<<"2:Book rooms\n";
    std::cout<<"3:Check out\n";
    std::cout<<"Please pick a number: ";
    std::cin>>control;
    if(control==0){
        std::cout<<"End\n";
        return;
    }else if(control==1){
        htl.ShowRooms();
        Menu(htl);
    }else if(control==2){
        std::cout<<"Please pick a room to stay in: ";
        std::cin>>pickwheel;
        htl.BookRoom(pickwheel);
        Menu(htl);
    }else if(control==3){
        std::cout<<"Please pick a room to check out: ";
        std::cin>>pickwheel;
        htl.CheckOut(pickwheel);
        Menu(htl);
    }else{
        std::cout<<"Not an option!\n";
        Menu(htl);
    }

}

int main(){
    hotel trivago;
    Menu(trivago);
    return 0;
}