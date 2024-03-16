#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
// using namespace std;

template <typename T>
class Node
{
public:
  T element;     // Element contained in the node
  Node<T> *next; // Pointer to the next node

  Node() // No-arg constructor
  {
    next = NULL;
  }

  Node(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }
};

template <typename T>
class LinkedList
{
public:
  LinkedList()
  {
    head = tail = NULL;
    size = 0;
  }
  void addFirst(T element)
  {
    Node<T> *newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
      tail = head;
  }
  void addLast(T element)
  {
    if (tail == NULL)
    {
      head = tail = new Node<T>(element);
    }
    else
    {
      tail->next = new Node<T>(element);
      tail = tail->next;
    }

    size++;
  }
  T getFirst() const
  {
    if (size == 0){
      std::cout << ("Index out of range");
    }
    else
      return head->element;
  }

  T getLast() const
  {
    if (size == 0)
      std::cout << ("Index out of range");
    else
      return tail->element;
  }
  T removeFirst() 
  {
    if (size == 0)
      std::cout << ("No elements in the list");
    else
    {
      Node<T> *temp = head;
      head = head->next;
      size--;
      T element = temp->element;
      delete temp;
      return element;
    }
  }

  /**
   * @brief A method which removes the last node in the linked list
   * Time complexity: {O(n)}. O(1) for this specific function because 
   * assignment operators are O(1), but turns into O(n) once recursive 
   * helper function is called
   * @return T 
   */
  T removeLast()
  {
    // write a recursive version of this method
    if (size == 0)
      std::cout << ("No elements in the list");
    else if (size == 1)
    {
      Node<T> *temp = head;
      head = tail = NULL;
      size = 0;
      T element = temp->element;
      delete temp;
      return element;
    }
    else
    {

      Node<T> *current = head;

      // for (int i = 0; i < size - 2; i++)
      //   current = current->next;
      // GetCurrRec(Node<T> *current);

      //This is the recursive helper function
      GetCurrRec(current);

      Node<T> *temp = tail;
      tail = current;
      tail->next = NULL;
      size--;
      T element = temp->element;
      delete temp;
      return element;
    }
  }

  /**
   * @brief Get the Current object, by looping through list until pointer finds
   * the last node(the node which "next" is pointing to a nullptr)
   * Time complexity: O(n) because it recursively loops through the list of n size
   * @param current 
   */
  void GetCurrRec(Node<T> *&current){
    if (current->next->next == nullptr){
      return;
    }
    current = current->next;
    GetCurrRec(current);
  }

  void add(T element)
  {
    addLast(element);
  }

  /**
   * @brief A method to add a node to any position in the list
   * Time complexity: {O(n)}. O(1) for this specific function because 
   * assignment and dot operators are O(1), but turns into O(n) once recursive 
   * helper function is called
   * @param index 
   * @param element 
   */
  void add(int index, T element)
  {
    if (index == 0)
      addFirst(element);
    else if (index >= size)
      addLast(element);
    else
    {
      Node<T> *current = head;
      // for (int i = 1; i < index; i++)
      //   current = current->next;

      //Same recursive helper function as remove last
      GetCurrRec(current);
      Node<T> *temp = current->next;
      current->next = new Node<T>(element);
      (current->next)->next = temp;
      size++;
    }
  }

  /**
   * @brief clears all data located in the lists nodes.
   * Time complexity: {O(n)}. O(1) for this specific function because 
   * assignment operators are O(1), but turns into O(n) once recursive 
   * helper function is called
   */
  void clear()
  {
    // while (head != NULL)
    // {
    //   Node<T> *temp = head;
    //   delete temp;
    //   head = head->next;
    // }
    clear(head);
    head = tail = NULL;
    size=0;
  }

  /**
   * @brief deletes all nodes located in the lists.
   * Time complexity: O(n) since it recursively loops through the list
   * of n size
   * @param head 
   */
  void clear(Node<T> *&head){
    if(head==nullptr){
      return;
    }
    Node<T> *temp=head;
    delete temp;
    clear(head->next);
  }

  /**
   * @brief Checks lists nodes and finds out if any node in the list
   * contains data equivalent to the parameter "element",returns true 
   * is element is found, returns false otherwise
   * Time complexity:{O(n)}. O(1) for this specific function because 
   * assignment operators are O(1), but turns into O(n) once recursive 
   * helper function is called
   * @param element 
   * @return true 
   * @return false 
   */
  bool contains(T element)
  {
    // Implement it in this exercise
    Node<T> *current = head;
    bool result=false;
    result=containsRecursive(current,element,result);
    // for (int i = 0; i < size; i++)
    // {
    //   if (current->element == element)
    //     return true;
    //   current = current->next;
    // }

    return result;
  }

  /**
   * @brief Loops through the lists nodes and checks if any of the nodes data is
   * equivalent until it reaches nullptr, returns true if element is found,
   * returns false if element isn't found
   * Time complexity: O(n) since it recursively loops through the list
   * of n size
   * @param head 
   * @param element 
   * @param result 
   * @return true 
   * @return false 
   */
  bool containsRecursive(Node<T> *&head,T element,bool result){
    if(head==nullptr){
      return result;
    }
    if(head->element==element){
      result=true;
    }
    containsRecursive(head->next,element,result);
  }


  T get(int index) const
  {
    if (index < 0 || index > size - 1)
      std::cout << ("Index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; i++)
      current = current->next;

    return current->element;
  }
  int indexOf(T element) const
  {
    // Implement it in this exercise
    Node<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        return i;
      current = current->next;
    }

    return -1;
  }
  bool isEmpty() const
  {
    return head == NULL;
  }
  int lastIndexOf(T element) const
  {
    int lastIndex = -1;
    Node<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        lastIndex = i;
      current = current->next;
    }

    return lastIndex;
  }

  int getSize() const
  {
    return size;
  }
  T remove(int index)
  {
    if (index < 0 || index >= size)
      std::cout << ("Index out of range");
    else if (index == 0)
      return removeFirst();
    else if (index == size - 1)
      return removeLast();
    else
    {
      Node<T> *previous = head;

      for (int i = 1; i < index; i++)
      {
        previous = previous->next;
      }

      Node<T> *current = previous->next;
      previous->next = current->next;
      size--;
      T element = current->element;
      delete current;
      return element;
    }
  }
  T set(int index, T element)
  {
    if (index < 0 || index >= size)
      std::cout << ("Index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }

    T oldElement = current->element;
    current->element = element;
    return oldElement;
  }
  /**
   * @brief A method to display linked list on console/terminal
   * Time complexity:{O(n)}. O(1) for this specific function because 
   * assignment operators and "cout" are O(1), but turns into O(n) once recursive 
   * helper function is called
   */
  void Show()
  {
    Node<T> *current = head;
    // for (int i = 0; i < size; i++)
    // {
    //   cout << current->element << " -> ";
    //   current = current->next;
    // }
    std::cout<<"{ ";
    print(current);
    std::cout <<"}"<< std::endl;
  }

  /**
   * @brief A method to loop through linked list while printing each node
   * to terminal every iteration
   * Time complexity: O(n) since it recursively loops through the list
   * of n size
   * @param h 
   */
  void print(Node<T> *h){
    if(h==nullptr){
      return;
    }
    if(h){
        std::cout<<h->element;
        std::cout<<" ";
    }
    print(h->next);
  }

private:
  Node<T> *head, *tail;
  int size;
};

#endif
