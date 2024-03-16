#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedListFull.h"
/**
 * @author Gregory bennett 
 */

class qq{
    public:
        qq();
        int dequeue();
        void enqueue(int);
        int peekfront();
        int peekrear();
        
    private:
        LinkedList<int> data;
        int size;




};

/**
 * @brief Construct a new qq::qq object
 * Creates a default stack object with nothing in it
 * Time complexity: O(1) because were only allocating memory for a variable
 */
qq::qq(){
    size=0;
}

/**
 * @brief A method to grab value from front of queue(linked list head) and 
 * then remove that data from the front
 * Time complexity: O(1) since methods isEmpty(),getFirst(), and removeFirst()
 * all have a time complexity of O(1). Assignment and dot operators are also O(1)
 * and there are no loops in the method 
 * @return int 
 */
int qq::dequeue(){
    if(data.isEmpty()){
        std::cerr<<"Empty queue, Returning zero";
        return 0;
    }
    int ret=data.getFirst();
    data.removeFirst();
    return ret;
}

/**
 * @brief A method to insert value to back of queue(linked list tail) 
 * Time complexity: O(1) since methods isEmpty(),add(), and addLast()
 * are all O(1) and because there are no loops in this method
 * @param x 
 */
void qq::enqueue(int x){
    if(data.isEmpty()){
        data.add(x);
    }else{
        data.addLast(x);
    }
    
}

/**
 * @brief A method to access the data at the front of the queue(Linked list Head)
 * and then return that value
 * Time complexity: O(1) since methods isEmpty() and getFirst() have a time 
 * complexity of O(1). Assignment operators are also O(1)
 * and there are no loops in the method
 * @return int 
 */
int qq::peekfront(){
    int ret;
    if(data.isEmpty()){
        std::cerr<<"Empty queue";
        ret=0;
        return ret;
    }else{
        ret=data.getFirst();
        return ret;
    }
    
}

/**
 * @brief A method to access the data at the back of the queue(Linked list tail)
 * and then return that value
 * Time complexity: O(1) since methods isEmpty() and getLast() have a time 
 * complexity of O(1). Assignment operators are also O(1)
 * and there are no loops in the method
 * @return int 
 */
int qq::peekrear(){
    int ret;
    if(data.isEmpty()){
        std::cerr<<"Empty queue";
        return 0;
    }else{
        ret=data.getLast();
        return ret;
    }
}



#endif