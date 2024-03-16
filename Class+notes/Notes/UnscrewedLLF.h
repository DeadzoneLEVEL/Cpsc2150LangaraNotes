#ifndef UNSCREWEDLLF_H
#define UNSCREWEDLLF_H
#include <iostream>
using namespace std;

template <typename T>
class NodeUF
{
public:
  T element;     // Element contained in the node
  NodeUF<T> *next; // Pointer to the next node

  NodeUF() // No-arg constructor
  {
    next = NULL;
  }

  NodeUF(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }
};

template <typename T>
class LinkedListUF
{
public:
  LinkedListUF()
  {
    head = tail = NULL;
    size = 0;
  }
  void addFirstUF(T element)
  {
    NodeUF<T> *newNode = new NodeUF<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
      tail = head;
  }
  void addLastUF(T element)
  {
    if (tail == NULL)
    {
      head = tail = new NodeUF<T>(element);
    }
    else
    {
      tail->next = new NodeUF<T>(element);
      tail = tail->next;
    }

    size++;
  }
  T getFirstUF() const
  {
    if (size == 0)
      cout << ("Index out of range");
    else
      return head->element;
  }
  T getLastUF() const
  {
    if (size == 0)
      cout << ("Index out of range");
    else
      return tail->element;
  }
  T removeFirstUF() 
  {
    if (size == 0)
      cout << ("No elements in the list");
    else
    {
      NodeUF<T> *temp = head;
      head = head->next;
      size--;
      T element = temp->element;
      delete temp;
      return element;
    }
  }
  T removeLastUF()
  {
    // write a recursive version of this method
    if (size == 0)
      cout << ("No elements in the list");
    else if (size == 1)
    {
      NodeUF<T> *temp = head;
      head = tail = NULL;
      size = 0;
      T element = temp->element;
      delete temp;
      return element;
    }
    else
    {

      NodeUF<T> *current = head;

      for (int i = 0; i < size - 2; i++)
        current = current->next;

      NodeUF<T> *temp = tail;
      tail = current;
      tail->next = NULL;
      size--;
      T element = temp->element;
      delete temp;
      return element;
    }
  }
  void addUF(T element)
  {
    addLastUF(element);
  }

  void addUF(int index, T element)
  {
    if (index == 0)
      addFirstUF(element);
    else if (index >= size)
      addLastUF(element);
    else
    {
      NodeUF<T> *current = head;
      for (int i = 1; i < index; i++)
        current = current->next;
      NodeUF<T> *temp = current->next;
      current->next = new NodeUF<T>(element);
      (current->next)->next = temp;
      size++;
    }
  }
  void clearUF()
  {
    while (head != NULL)
    {
      NodeUF<T> *temp = head;
      delete temp;
      head = head->next;
    }

    tail = NULL;
  }
  bool containsUF(T element)
  {
    // Implement it in this exercise
    NodeUF<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        return true;
      current = current->next;
    }

    return false;
  }
  T getUF(int index) const
  {
    if (index < 0 || index > size - 1)
      cout << ("Index out of range");

    NodeUF<T> *current = head;
    for (int i = 0; i < index; i++)
      current = current->next;

    return current->element;
  }
  int indexOfUF(T element) const
  {
    // Implement it in this exercise
    NodeUF<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        return i;
      current = current->next;
    }

    return -1;
  }
  bool isEmptyUF() const
  {
    return head == NULL;
  }
  int lastIndexOfUF(T element) const
  {
    int lastIndex = -1;
    NodeUF<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        lastIndex = i;
      current = current->next;
    }

    return lastIndex;
  }

  int getSizeUF() const
  {
    return size;
  }
  T removeUF(int index)
  {
    if (index < 0 || index >= size)
      cout << ("Index out of range");
    else if (index == 0)
      return removeFirstUF();
    else if (index == size - 1)
      return removeLastUF();
    else
    {
      NodeUF<T> *previous = head;

      for (int i = 1; i < index; i++)
      {
        previous = previous->next;
      }

      NodeUF<T> *current = previous->next;
      previous->next = current->next;
      size--;
      T element = current->element;
      delete current;
      return element;
    }
  }
  T setUF(int index, T element)
  {
    if (index < 0 || index >= size)
      cout << ("Index out of range");

    NodeUF<T> *current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }

    T oldElement = current->element;
    current->element = element;
    return oldElement;
  }
  void ShowUF()
  {
    NodeUF<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      cout << current->element << " -> ";
      current = current->next;
    }
    cout << endl;
  }

private:
  NodeUF<T> *head, *tail;
  int size;
};

#endif
