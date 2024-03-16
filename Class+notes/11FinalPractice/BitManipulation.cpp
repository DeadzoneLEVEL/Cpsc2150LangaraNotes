#include <vector>
#include <iostream>
#include <cmath>

void ShowCurrent(int t){
    std::cout<<"\n{ ";
    unsigned y=1;
    // for(int i=0;i<sizeof(int)*8;i++){
    for(unsigned i=(y<<31);i!=0;i>>=1){
        std::cout<<(t&1)<<" ";
        t>>=1;
    }
    std::cout<<"}\n";
}

int bitmanipulation(int val){
    unsigned int evenBits = val & 0xAAAAAAAA;
    unsigned int oddBits = val & 0x55555555;
    evenBits >>= 1;
    oddBits <<= 1;
    return evenBits | oddBits;
}

int toggleEvenBits(int val){
    return val &~(0xAAAAAAAA);
}
int toggleOddBits(int val){
    return val &~(0x55555555);
}
int turnOnEvenBits(int val){
    return val |(0xAAAAAAAA);
}
int switchEvenBits(int val){
    return val^(0xAAAAAAAA);
}
int switchAllBits(int val){
    val ^=(0xAAAAAAAA);//even
    val ^=(0x55555555);//odd
    return val;
}

int SetBits(int t){
    int ret=0;
    unsigned y=1;
    for(unsigned i=(y<<31);i!=0;i>>=1){
        if(t&1){
            ret++;
        }
        t>>=1;
    }
    return ret;
}

int countBits(int number) {
    int bits = static_cast<int>(log2(number)) + 1;
    return bits;
}

bool isPalindrome(int val){
    int m=static_cast<int>(log2(val)) + 1;
    std::vector<int>results;
    for(int i=0;i<m;i++){
        results.push_back(val&1);
        val>>=1;
    }
    for(unsigned i=0, j=results.size()-1;i<results.size();i++,j--){
        if(results[i]!=results[j]){
            return false;
        }
    }
    return true;
}

int toggleBit(int val,int pos){
    return val ^(1<<pos);
}

int main(){
    // int x=bitmanipulation(60);
    ShowCurrent(60);
    int x=switchAllBits(60);
    ShowCurrent(x);
    x=SetBits(x);
    std::cout<<x<<std::endl;
    x=countBits(16);
    std::cout<<x<<std::endl;
    ShowCurrent(9);
    bool control= isPalindrome(9);
    std::cout<<std::boolalpha<<control<<std::endl;
    ShowCurrent(2);
    control= isPalindrome(2);
    std::cout<<std::boolalpha<<control<<std::endl;
    x=toggleBit(13,2);
    std::cout<<x<<std::endl;
    return 0;
}



