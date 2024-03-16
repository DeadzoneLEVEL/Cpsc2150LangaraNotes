#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int element; // Element contained in the node
  TreeNode* left; // Pointer to the left child
  TreeNode* right; // Pointer to the right child

  TreeNode() // default constructor
  {
    element = 0;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(const int& e) // defined constructor
  {
    this->element = e;
    left = nullptr;
    right = nullptr;
  }
};

class MAXHEAP
{
public:
  MAXHEAP() // default constructor
  {
    root = nullptr;
    size = 0;
  }

  MAXHEAP(int *elements, int arraySize) // defined constructor
  {
    root = nullptr;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
  }

  
  
  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  TreeNode* search(const int& e) const
  {
    
  }

  TreeNode* createNewNode(const int& e)
  {
    return new TreeNode(e);
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool insert(const int& e)
  {
    if (root == nullptr){
      root = createNewNode(e); // Create a new root
      return true;
    }
    else
    {
      queue<TreeNode*> q;
      q.push(root);

      while(!q.empty()){
          TreeNode* temp = q.front();
          q.pop();

          if(temp->left != nullptr){
              q.push(temp->left);
          }
          else{
            temp->left = createNewNode(e);
            heapify(temp->left);
            size++;
            return true;
          }
          if(temp->right != nullptr){
              q.push(temp->right);
          }
          else{
            temp->right = createNewNode(e);
            heapify(temp->right);
            size++;
            return true;
          }
      }   
    }

    
    return false;
  }

  void heapify(TreeNode* someNode){
    
  }
  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const TreeNode* someNode) const
  {
    if (someNode == nullptr) return;

    inorder(someNode->left); // process all nodes in left sub-tree of someNode
    cout << someNode->element << " "; // process someNode
    inorder(someNode->right); // process all nodes in right sub-tree of someNode
  }

  

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }



  /* Return a path from the root leading to the specified element.
  If specified element does not exist in the tree then add a nullptr 
  to the end.*/
  vector<TreeNode*>* path(const int& e) const
  {
    
  }

    // display tree like a tree horizontally
    void DisplayTreeHorizontally(){
        DisplayTreeHorizontally(root, 0);
    }

    // display the tree rooted at someNode like a tree, horizontally
    void DisplayTreeHorizontally(TreeNode* someNode, int space){
        if(someNode == nullptr){
            return;
        }
        else{
            space += 10;

            DisplayTreeHorizontally(someNode->right, space);

            cout << endl;
            for(int i = 10; i < space; i++){
                cout << " ";
            }
            cout << someNode->element << endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }
    


private:
  TreeNode* root;
  int size;
};

#endif
