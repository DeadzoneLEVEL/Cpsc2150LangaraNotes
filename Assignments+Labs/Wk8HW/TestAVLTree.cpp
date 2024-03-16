#include <iostream>
#include "liangAVLTree.h"
using namespace std;

int main()
{
  int numbers[] = {25, 20, 5};
  AVLTree tree(numbers, 3);

  cout << "After inserting 25, 20, 5:" << endl;
  //tree.LevelOrderDisplay();

  tree.insert(34);
  tree.insert(50);
  cout << "\nAfter inserting 34, 50:" << endl;
  //tree.LevelOrderDisplay();

  tree.insert(30);
  cout << "\nAfter inserting 30" << endl;
  //tree.LevelOrderDisplay();

  tree.insert(10);
  cout << "\nAfter inserting 10" << endl;
  
  //tree.LevelOrderDisplay();
  tree.DisplayTreeHorizontally();
  std::cout<<std::endl;
  tree.LevelOrderDisplay();
  int x=tree.Diameter();
  std::cout<<x<<"\n";
  x=tree.CountNodesAtLevel(2);
  std::cout<<x<<"\n";
  x=tree.Count(11,40);
  std::cout<<x<<"\n";
  // tree.remove(34);
  // tree.remove(30);
  // tree.remove(50);
  // cout << "\nAfter removing 34, 30, 50:" << endl;
  // tree.DisplayTreeHorizontally();
  // tree.LevelOrderDisplay();

  // tree.remove(5);
  // cout << "\nAfter removing 5:" << endl;
  // tree.DisplayTreeHorizontally();
  // tree.LevelOrderDisplay();

  return 0;
}
