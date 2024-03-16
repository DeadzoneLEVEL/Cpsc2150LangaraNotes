#ifndef HASHINGLINEAR_H
#define HASHINGLINEAR_H
#include <iostream>

class  HashingLinearProbingDemo{
    private:
        int* hashTable;
        int hashTableSize;
        int numberOfKeys;
        double loadFactorThreshold;
    public:
        HashingLinearProbingDemo();
        HashingLinearProbingDemo(int,double);
        void ReHash();
        void Delete(int value);
        bool search(int value);
        void Insert(int value);
        void display();

        ~HashingLinearProbingDemo();
        HashingLinearProbingDemo(const HashingLinearProbingDemo &rhs);
        const HashingLinearProbingDemo& operator =(const HashingLinearProbingDemo &rhs);
};

HashingLinearProbingDemo::HashingLinearProbingDemo(){
    hashTable=nullptr;
    numberOfKeys=0;
    hashTableSize=0;
    loadFactorThreshold=1.0;
}

HashingLinearProbingDemo::HashingLinearProbingDemo(int initialTableSize,double initialloadFactor){
    hashTableSize=initialTableSize;
    hashTable=new int[hashTableSize];
    for(int i=0;i<hashTableSize;i++){
        hashTable[i]=0;
    }
    loadFactorThreshold=initialloadFactor;
    numberOfKeys=0;
}

void HashingLinearProbingDemo::ReHash(){
    int previousSize=hashTableSize;
    hashTableSize=hashTableSize*2;
    int *temp=new int[hashTableSize];
    for(int i=0;i<hashTableSize;i++){
        temp[i]=0;
    }
    for(int i=0;i<previousSize;i++){
        if(hashTable[i]!=0){
            std::hash<int> builtInHash;
            int hashCode=builtInHash(hashTable[i]);
            int hashIndex=hashCode%(hashTableSize-1);
            //linear probing
            while(temp[hashIndex]!=0){
                hashIndex+=1;
                hashIndex=hashIndex%(hashTableSize-1);
            }
            temp[hashIndex]=hashTable[i];
        }
    }
    this->hashTable=temp;
    temp=nullptr;
    delete temp;
    return;
}

void HashingLinearProbingDemo::Delete(int value){
    std::hash<int> builtInHash;
    int hashCode=builtInHash(value);
    int hashIndex=hashCode%(hashTableSize-1);
    int counter=hashTableSize;
    while(hashTable[hashIndex]!=value&&counter>=0){
        hashIndex+=1;
        hashIndex=hashIndex%(hashTableSize-1);
        counter-=1;
    }
    if(hashTable[hashIndex]==value){
        hashTable[hashIndex]=0;
        numberOfKeys-=1;
    }else{
        std::cerr<<"ERROR: hashtable does not contain "<<value<<".\n";
    }
}

bool HashingLinearProbingDemo::search(int value){
    std::hash<int> builtInHash;
    int hashCode=builtInHash(value);
    int hashIndex=hashCode%(hashTableSize-1);
    int counter=hashTableSize;
    while(hashTable[hashIndex]!=value&&counter>=0){
        hashIndex+=1;
        hashIndex=hashIndex%(hashTableSize-1);
        counter-=1;
    }
    if(hashTable[hashIndex]==value){
        return true;
    }else{
        return false;
    }
}

void HashingLinearProbingDemo::Insert(int value){
    if(value==0){
        std::cerr<<"ERROR: value is invalid\n";
        return;
    }
    if(search(value)){
        std::cerr<<"ERROR: value already exists\n";
    }else{
        double currentLoadFactor= ((double)(numberOfKeys+1)/hashTableSize);
        if(currentLoadFactor>loadFactorThreshold){
            ReHash();
        }
        std::hash<int> builtInHash;
        int hashCode=builtInHash(value);
        int hashIndex=hashCode%(hashTableSize-1);
        //linear probing
        while(hashTable[hashIndex]!=0){
            hashIndex+=1;
            hashIndex=hashIndex%(hashTableSize-1);
        }
        hashTable[hashIndex]=value;
        numberOfKeys+=1;
    }
}

void HashingLinearProbingDemo::display(){
    std::cout<<"\tHashTable\n";
    std::cout<<"Current table size: "<<hashTableSize<<std::endl;
    std::cout<<"Number of Keys: "<<numberOfKeys<<std::endl;
    std::cout<<"Current Factor threshold: "<<((double)(numberOfKeys+1)/hashTableSize)<<std::endl;
    std::cout<<"Load Factor threshold: "<<loadFactorThreshold<<std::endl;
    std::cout<<"{ ";
    for(int i=0;i<hashTableSize;i++){
        if(hashTable[i]!=0){
            std::cout<<"[Index:"<<i<<" Value:";
            std::cout<<hashTable[i];
            std::cout<<"] ";
        }
    }
    std::cout<<" }\n";
}

HashingLinearProbingDemo::~HashingLinearProbingDemo(){
    delete[] hashTable;
    std::cerr<<"DELETE\n";  
}
HashingLinearProbingDemo::HashingLinearProbingDemo(const HashingLinearProbingDemo &rhs){
    int *temp=new int[rhs.hashTableSize];
    for(int i=0;i<rhs.hashTableSize;i++){
        temp[i]=0;
    }
    for(int i=0;i<rhs.hashTableSize;i++){
        temp[i]=rhs.hashTable[i];
    }
    this->hashTable=temp;
    temp=nullptr;
    delete temp;
    this->numberOfKeys=rhs.numberOfKeys;
    this->hashTableSize=rhs.hashTableSize;
    this->loadFactorThreshold=rhs.loadFactorThreshold;
    std::cerr<<"COPY\n";
}
const HashingLinearProbingDemo& HashingLinearProbingDemo::operator =(const HashingLinearProbingDemo &rhs){
    if(this==&rhs){
        return *this;
    }
    delete[] hashTable;
    int *temp=new int[rhs.hashTableSize];
    for(int i=0;i<rhs.hashTableSize;i++){
        temp[i]=0;
    }
    for(int i=0;i<rhs.hashTableSize;i++){
        temp[i]=rhs.hashTable[i];
    }
    this->hashTable=temp;
    temp=nullptr;
    delete temp;
    this->numberOfKeys=rhs.numberOfKeys;
    this->hashTableSize=rhs.hashTableSize;
    this->loadFactorThreshold=rhs.loadFactorThreshold;
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}
#endif