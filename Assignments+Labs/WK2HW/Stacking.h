#ifndef STACKING_H
#define STACKING_H

#include <iostream>
#include <vector>
/**
 * @author Gregory bennett 
 */

class ss{
    public:
        ss();
        int peek();
        void push(int x);
        int pop();
        bool isEmpty();
        int length();
        void print();

        ~ss();
        ss(ss &rhs);
        const ss& operator=(ss &rhs);
    private:
        std::vector<int> data;
        int size;
};
/**
 * @brief Construct a new ss::ss object
 * Creates a default stack object with nothing in it
 * Time complexity: O(1) because were only allocating memory for a variable
 */
ss::ss(){
    this->size=0;
}

/**
 * @brief Checks if stack is empty, then if not, it returns the variable located at
 * the top of the stack(end of data vec)
 * @param none
 * 
 * Time Complexity: O(1), accessing the variable is a one step process because we know
 * the location and don't care about what information is stored
 * @return int which was at the top of the stack
 */
int ss::peek(){
    if(isEmpty()){
        std::cerr<<"Error, Stack empty\n";
        return 0;
    }
    int num=this->data[this->size-1];
    return num;
}

/**
 * @brief Pushes a new variable into the data vector and then increases the size of 
 * the stack 
 * Time Complexity: O(1), adding the variable is a one step process because we don't 
 * care about the location of where we place the variable
 * @param x variable which will be inserted into stack
 */
void ss::push(int x){
    this->data.push_back(x);
    this->size+=1;
}

/**
 * @brief Checks if stack is empty, then if not, it returns the variable which
 * was at the top of the stack and removes it from data vector
 * Time Complexity: O(1) because accessing using the dot operator is O(1) and there is 
 * no loops in the function 
 * @return int 
 */
int ss::pop(){
    if(isEmpty()){
        std::cerr<<"Error, Stack empty\n";
        return 0;
    }else{
        int num=this->data[this->size-1];
        this->data.pop_back();
        this->size-=1;
        return num;
    }
}

/**
 * @brief Checks to see if the size of the stack is equal to zero
 * Time Complexity: O(1) because accessing using the dot operator is O(1) and there is 
 * no loops in the function 
 * @return true 
 * @return false 
 */
bool ss::isEmpty(){
    return this->size==0;
}

/**
 * @brief Returns the size of the stack
 * Time Complexity: O(1) because accessing using the dot operator is O(1) and there is 
 * no loops in the function
 * @return int 
 */
int ss::length(){
    return this->size;
}

/**
 * @brief displays the stack to the console/terminal
 * Time complexity: O(n) since there is a single loop traveling through 
 * a stack which would have n items in it
 */
void ss::print(){
    std::cout<<"{ ";
    for(int i=0;i<this->size;i++){
        std::cout<<this->data[i]<<" ";
    }
    std::cout<<"}\n";
}

/**
 * @brief Destroy the ss::ss object
 * Instructor mentioned Big three was not a part of the assignment
 */
ss::~ss(){
    this->data.clear();
    this->size=0;
    std::cerr<<"DELETE\n";
}

/**
 * @brief Construct a new ss::ss object
 * Instructor mentioned Big three was not a part of the assignment
 * @param rhs 
 */
ss::ss(ss &rhs){
    this->size=rhs.length();
    for(int i=0;i<rhs.length();i++){
        this->data.push_back(rhs.data[i]);
    }
    std::cerr<<"COPY\n";
}

/**
 * @brief 
 * Instructor mentioned Big three was not a part of the assignment
 * @param rhs 
 * @return const ss& 
 */
const ss& ss::operator=(ss &rhs){
    if(this==&rhs){
        return *this;
    }
    this->data.clear();
    this->size=rhs.length();
    for(int i=0;i<rhs.length();i++){
        this->data.push_back(rhs.data[i]);
    }
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif