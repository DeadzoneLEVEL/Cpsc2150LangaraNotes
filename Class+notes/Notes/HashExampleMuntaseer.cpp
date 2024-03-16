#include<iostream>
#include <string>



int hashfunc(std::string s){
    if(s.size()==0){
        return 0;
    }
    return s[0];
}

// int hashfunc(std::string s){
//     if(s.size()< 2){
//         return 0;
//     }
//     return s[0] +s[1];
// }

struct pair{
    std::string key;
    double value;
};

void display(pair *hashtable, int size){
    for(int i=0;i<size;i++){
        std::cout<<"index: "<<i<<":"<<hashtable[i].key<<","<<hashtable[i].value<<"\n";
    }
}
void linearProbing(pair *hashtable,int size,pair p){

}

int main(){
    int size=10;
    pair hashtable[size];
    pair p;
    // for(int i=0;i<2;i++){
    //     std::cout<< "enter name and a value\n: ";
    //     std::cin>>p.key>>p.value;

    //     int hashcode=hashfunc(p.key);//O(1)
    //     std::cout<<"hash code:"<<hashcode<<std::endl;

    //     int hashtableindex= hashcode%(size);//O(1)
    //     std::cout<<hashtableindex<<std::endl;
    //     if(hashtable[hashtableindex].key!=""){
    //         hashtable[hashtableindex]=p;//O(1)
    //     }else{
    //         linearProbing(hashtable,size,p);
    //     }
    // }
    // display(hashtable,size);
    std::hash<std::string> builtInHash;
    for(int i=0;i<2;i++){
        std::cout<< "enter name and a value\n: ";
        std::cin>>p.key>>p.value;

        int hashcode=builtInHash(p.key);//O(1)
        std::cout<<"hash code:"<<hashcode<<std::endl;

        int hashtableindex= hashcode%(size);//O(1)
        std::cout<<hashtableindex<<std::endl;
        if(hashtable[hashtableindex].key!=""){
            hashtable[hashtableindex]=p;//O(1)
        }else{
            // linearProbing(hashtable,size,p);
        }
    }
    return 0;
}

