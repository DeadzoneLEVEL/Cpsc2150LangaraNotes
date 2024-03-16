#include <iostream>

using namespace std;

enum SETTINGS {
    mouseInverted = 1, 
    antiAliasing = 2, 
    fullScreen = 4, 
    vSync = 8
};

bool IsInFullscreenMode(unsigned char settings){
    // returns true if fullscreen mode is on; false otherwise.
    if(settings&SETTINGS::fullScreen){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    unsigned char c = 4;
    cout << (int)c << endl;
    c = c | 8; // we could say c = 12 but then we have to think about all possible bit combos
    cout << (int)c << endl;
    int x = 120;
    x >>= 2 ;
    cout << x << endl;
    unsigned char settings = 0;
    cout << (int)settings << endl; // 0
    settings = settings | SETTINGS::antiAliasing;
    cout << (int)settings << endl; // 2 base-10 10-base-2
    settings |= SETTINGS::fullScreen; // 010 base-2 | 100 base-2 = 110 base-2 = 6 base-10
    cout << (int) settings << endl; // 6
    cout << std::boolalpha<<IsInFullscreenMode(settings) << endl; // 1
    settings = settings & ~SETTINGS::fullScreen;
    cout << std::boolalpha<<IsInFullscreenMode(settings) << endl; // 0
    cout << (int) settings << endl; // 2
    settings |= fullScreen;
    cout << (int)settings << endl; //6
    settings = settings ^ antiAliasing;
    cout << (int)settings << endl; // 4?
    settings = settings ^ fullScreen;
    cout << (int)settings << endl;
    int f = -10;
    int i = 0;
    while(i < 3){
        f = f >> 1;
        i++;
    }

    cout << f << endl;


    return 0;
}