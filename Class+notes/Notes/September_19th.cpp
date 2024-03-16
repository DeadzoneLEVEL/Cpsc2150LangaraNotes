#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::cout<<"penis\n";
    std::vector<int> vec;
    for(int i=0;i<10;i++){
        vec.push_back(i+1);
    }
    std::cout<<"{ ";
    for(int i=0;i<vec.size();i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<"}\n";
    return 0;
}