#include <iostream>
#include <cmath>

enum SET{
    some=2,
    smth=4
};

enum SETTINGS{
    mouseInverted=1,
    antiAliasing =2,
    fullScreen=4,
    vSync=8
};

bool IsInFullScreenMode(unsigned char settings){

}

bool isEven(int x){
    return ~x&1;
}

int main(){
    // unsigned char c=6;
    // c=c|SET::some;
    // std::cout<<"1st:"<<c<<std::endl;
    // c=c|SET::smth;
    // std::cout<<"2nd:"<<c<<std::endl;
    // c=c&~SET::smth;
    // std::cout<<"3rd:"<<c<<std::endl;
    std::cout<<std::boolalpha<<isEven(12)<<std::endl;
    std::cout<<std::boolalpha<<isEven(13)<<std::endl;
    for(unsigned char c=1;c;c<<=1){
        std::cout<<"hello"<<std::endl;
    }

    return 0;
}