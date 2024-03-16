#ifndef HASHINGCHAIN_H
#define HASHINGCHAIN_H
#include <iostream>
#include <vector>
#include "SkipList.h"
#include "Node.h"

class  HashingLinearProbingDemo{
    private:
        SkipList* hashTable;
        int hashTableSize;
        int numberOfKeys;
        int maximumlvl;
        double loadFactorThreshold;
    public:
        HashingLinearProbingDemo();
        HashingLinearProbingDemo(int,double,int);
        void ReHash();
        void Delete(int value);
        bool search(int value);
        void Insert(int value);
        void display();

        ~HashingLinearProbingDemo();
        // HashingLinearProbingDemo(const HashingLinearProbingDemo &rhs);
        // const HashingLinearProbingDemo& operator =(const HashingLinearProbingDemo &rhs);
};

HashingLinearProbingDemo::HashingLinearProbingDemo(){
    hashTable=nullptr;
    numberOfKeys=0;
    hashTableSize=0;
    loadFactorThreshold=1.0;
    maximumlvl=0;
}

HashingLinearProbingDemo::HashingLinearProbingDemo(int initialTableSize,double initialloadFactor,int maxlvl){
    hashTableSize=initialTableSize;
    maximumlvl=maxlvl;
    hashTable=new SkipList[hashTableSize];
    for(int i=0;i<hashTableSize;i++){
        hashTable[i]=SkipList(maxlvl);
    }
    loadFactorThreshold=initialloadFactor;
    numberOfKeys=0;
}

void HashingLinearProbingDemo::ReHash(){
    int previousSize=hashTableSize;
    hashTableSize=hashTableSize*2;
    SkipList *temp=new SkipList[hashTableSize];
    for(int i=0;i<hashTableSize;i++){
        temp[i]=SkipList(maximumlvl);
    }
    for(int i=0;i<previousSize;i++){
        if(hashTable[i].head->next[0]!=hashTable[i].tail){
             Node *current=hashTable[i].head;
            while(current != nullptr && current->next[0] != hashTable[i].tail){
                current = current->next[0];
                std::hash<int> builtInHash;
                int hashCode=builtInHash(current->value);
                int hashIndex=hashCode%(hashTableSize-1);
                temp[hashIndex].InsertElement(current->value);
            }
        }
    }
    this->hashTable=temp;
    return;
}

void HashingLinearProbingDemo::Delete(int value){
    std::hash<int> builtInHash;
    int hashCode=builtInHash(value);
    int hashIndex=hashCode%(hashTableSize-1);
    for(int i=0;i<hashTableSize;i++){
        if(hashTable[hashIndex].Search(value)){
            hashTable[hashIndex].Delete(value);
            numberOfKeys-=1;
            return;
        }
        hashIndex+=1;
        hashIndex=hashIndex%(hashTableSize-1);
    }
    std::cerr<<"ERROR: hashtable does not contain "<<value<<".\n";
}

bool HashingLinearProbingDemo::search(int value){
    std::hash<int> builtInHash;
    int hashCode=builtInHash(value);
    int hashIndex=hashCode%(hashTableSize-1);
    for(int i=0;i<hashTableSize;i++){
        if(hashTable[hashIndex].Search(value)){
            return true;
        }
        hashIndex+=1;
        hashIndex=hashIndex%(hashTableSize-1);
    }
    return false;
}

void HashingLinearProbingDemo::Insert(int value){
    if(search(value)){
        std::cerr<<"ERROR: value already exists\n";
    }else{
        double currentLoadFactor= ((double)(numberOfKeys+1)/hashTableSize);
        if(currentLoadFactor>loadFactorThreshold){
            ReHash();
        }
        std::string str="f";
        std::hash<int> builtInHash;
        int hashCode=builtInHash(value);
        int hashIndex=hashCode%(hashTableSize-1);
        hashTable[hashIndex].InsertElement(value);
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
        if(hashTable[i].head->next[0]!=hashTable->tail){
            std::cout<<"[Index:"<<i<<" Value:";
            Node *current=hashTable[i].head;
            while(current != nullptr && current->next[0] != hashTable[i].tail){
                current = current->next[0];
                cout << current->value << " -> ";
            }
            std::cout<<".] ";
        }
    }
    std::cout<<" }\n";
}

HashingLinearProbingDemo::~HashingLinearProbingDemo(){
    for(int i=0;i<this->hashTableSize;i++){
        hashTable[i].deleteAll();
    }
    delete[] hashTable;
    std::cerr<<"DELETE\n";  
}

#endif