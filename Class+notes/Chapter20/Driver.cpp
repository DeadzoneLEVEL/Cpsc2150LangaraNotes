#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
void printList(LinkedList<string> list){
  for (int i = 0; i < list.getSize(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

int main(){
  // Create a list for strings
  LinkedList<string> list;
  cout << "Enter four strings: " << endl;
  string s;
  for (int i = 0; i < 4; i++) 
  {
    getline(cin, s);
    list.add(s);
  }

  cout << "Enter a string: ";
  getline(cin, s);
  list.remove(s);
  printList(list);

  return 0;
}