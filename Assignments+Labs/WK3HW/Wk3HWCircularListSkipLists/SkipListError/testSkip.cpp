#include <iostream>
#include <cstdlib>
#include <ctime>
// #include "SkipList.h"
#include "DoublySkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    DoublySkipList lst(3); 
    // SkipList lst(3);
 
    lst.InsertElement(13);
    lst.InsertElement(7);
    lst.InsertElement(11);
    lst.InsertElement(1);
    lst.InsertElement(5);
    lst.InsertElement(19);

    lst.InsertElement(313);
    lst.InsertElement(37);
    lst.InsertElement(311);
    lst.InsertElement(31);
    lst.InsertElement(35);
    lst.InsertElement(319);

    lst.Show();
    // lst.ShowForwardBackwards();
    lst.Delete(319);
    lst.ShowBackward();
    // lst.ShowForwardBackwards();

    // std::cout<<std::boolalpha<<lst.Search(35)<<std::endl;

    // // lst.Delete(35);
    // // lst.Delete(319);
    // lst.Delete(1);
    // lst.Show();
    // lst.ShowForwardBackwards();

    return 0;
}