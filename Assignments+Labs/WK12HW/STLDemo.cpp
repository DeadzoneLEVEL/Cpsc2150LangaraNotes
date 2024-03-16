#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <algorithm>

// using namespace std;

int main() {

    //////////////////// LISTS

    std::list<int> myList = {1, 2, 3};
    
    // Display
    for (int n : myList)
        std::cout << n << " ";
    std::cout << "\n";

    // Insert
    myList.push_back(4);

    // Delete
    myList.pop_front(); // Removes the first element

    // Access (Lists do not support direct access)
    auto it = next(myList.begin(), 1); // Accessing the second element
    std::cout << "Second element: " << *it << "\n";

    // Search
    auto findIt = find(myList.begin(), myList.end(), 3);
    if (findIt != myList.end()) 
        std::cout << "Element found: " << *findIt << "\n";
    else 
        std::cout << "Element not found\n";



    //////////////////// PRIOIRITY QUEUES

    std::priority_queue<int> myPQ;

    // Insert
    myPQ.push(10);
    myPQ.push(5);
    myPQ.push(15);

    // Display and Delete
    std::cout << "Priority Queue: ";
    while (!myPQ.empty()) {
        std::cout << myPQ.top() << " ";
        myPQ.pop(); // Popping also deletes the element
    }
    std::cout << "\n";

    // Priority queues do not support search and direct access operations in a straightforward manner.
    // Custom comparator lambda function
    auto comp = [](int left, int right) { 
        return left > right; 
    };
    std::cout<<"This is important!!!\n";
    // Declare a priority queue with the custom comparator
    std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);

    // Insert elements into the priority queue
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);

    // Display and remove elements from the priority queue
    std::cout << "Priority Queue with custom comparator (descending order):" << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";


    //////////////// MAPS

    std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}};

    // Display
    for (auto& pair : myMap) std::cout << pair.first << ": " << pair.second << "\n";

    // Insert
    myMap["three"] = 3;

    // Delete
    myMap.erase("one");

    // Access
    std::cout << "Value associated with 'two': " << myMap["two"] << "\n";

    // Search
    auto mapIt = myMap.find("three");
    if (mapIt != myMap.end()) 
        std::cout << "Element found: " << mapIt->first << "->" << mapIt->second << "\n";
    else 
        std::cout << "Element not found\n";


    //////////////// SETS

    std::set<int> mySet = {1, 2, 3};

    // Display
    for (int n : mySet) 
        std::cout << n << " ";
    std::cout << "\n";

    // Insert
    mySet.insert(4);

    // Delete
    mySet.erase(1);

    // Search
    auto setIt = mySet.find(2);
    if (setIt != mySet.end()) 
        std::cout << "Element found: " << *setIt << "\n";
    else 
        std::cout << "Element not found\n";

    // Sets do not support direct access by index.


    //////////////// UNORDERED SETS
    
    std::unordered_set<int> myUSet = {1, 2, 3};

    // Display
    for (int n : myUSet) 
        std::cout << n << " ";
    std::cout << "\n";

    // Insert
    myUSet.insert(4);

    // Delete
    myUSet.erase(1);

    // Search
    auto uSetIt = myUSet.find(2);
    if (uSetIt != myUSet.end()) 
        std::cout << "Element found: " << *uSetIt << "\n";
    else 
        std::cout << "Element not found\n";

    // Unordered sets do not support direct access by index.


    return 0;
}

    
