#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class AVLTreeNode
{
public:
  int element;        // Element contained in the node
  int height;         // height of the node
  AVLTreeNode *left;  // Pointer to the left child
  AVLTreeNode *right; // Pointer to the right child

  AVLTreeNode(int element)
  {
    this->element = element;
    height = 0;
    left = nullptr;
    right = nullptr;
  }
};

class AVLTree
{
public:
  AVLTree()
  {
    root = nullptr;
    size = 0;
    height = 0;
  }

  AVLTree(int elements[], int arraySize)
  {
    root = nullptr;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
  }

  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const AVLTreeNode *root) const
  {
    if (root == nullptr)
      return;
    inorder(root->left);
    cout << root->element << " ";
    inorder(root->right);
  }

///////EXERCISE////////
  // return a queue of nodes in level order
  queue<AVLTreeNode *> LevelOrderNodes(AVLTreeNode *someNode){
    queue<AVLTreeNode*> q,results;
    int lvl=0;
    someNode->height=0;
    q.push(someNode);
    results.push(someNode);
    LevelOrderNodes(q,results,lvl);
    return results;
  }
  void LevelOrderNodes(queue<AVLTreeNode*> &q,queue<AVLTreeNode*> &results,int lvl){
    if(q.empty()){
      return;
    }else{
      AVLTreeNode *temp=q.front();
      if(temp->left!=nullptr){
        temp->left->height=lvl;
        q.push(temp->left);
        results.push(temp->left);  
      }
      if(temp->right!=nullptr){
        temp->right->height=lvl;
        q.push(temp->right);
        results.push(temp->right);
      }
      q.pop();
      LevelOrderNodes(q,results,lvl);
    }
  }
  

///////EXERCISE////////
  // display tree with level indices
  void DisplayTreeWithLevelIndices(queue<AVLTreeNode *> q){
    int nodesOnLvl=1,lacking=0,currNode=0,level=0;
    AVLTreeNode *tmp;
    std::cout<<"\nLevel "<<level<<": ";
    while(!q.empty()){
      if(currNode==nodesOnLvl){
        currNode=0;
        level+=1;
        nodesOnLvl=(nodesOnLvl*2)-lacking;
        lacking=0;
        std::cout<<"\nLevel "<<level<<": ";
      }
      tmp=q.front();
      currNode+=1;
      if(!tmp->left){
        lacking+=1;
      }
      if(!tmp->right){
        lacking+=1;
      }
      std::cout<<tmp->element<<": ";
      q.pop();
    }
    std::cout<<std::endl;
  }

  // level order display
  void LevelOrderDisplay()
  {
    if (root == nullptr)
    {
      cout << "Tree is empty." << endl;
    }
    else
    {
      queue<AVLTreeNode *> q = LevelOrderNodes(root);
      DisplayTreeWithLevelIndices(q);
    }

    /** SAMPLE OUTPUT
After inserting 25, 20, 5:
level 0: 20
level 1: 5 25

After inserting 34, 50:
level 0: 20
level 1: 5 34
level 2: 25 50

After inserting 30
level 0: 25
level 1: 20 34
level 2: 5 30 50

After inserting 10
level 0: 25
level 1: 10 34
level 2: 5 20 30 50

After removing 34, 30, 50:
level 0: 10
level 1: 5 25
level 2: 20

After removing 5:
level 0: 20
level 1: 10 25
     */
  }

  // display tree like a tree, horizontally
  void DisplayTreeHorizontally()
  {
    cout << "==========tree/horizontal view==========\n";
    DisplayTreeHorizontally(root, 0);
  }

  // display the tree rooted at someNode like a tree, horizontally
  void DisplayTreeHorizontally(AVLTreeNode *someNode, int space)
  {
    if (someNode == nullptr)
    {
      return;
    }
    else
    {
      space += 10;

      DisplayTreeHorizontally(someNode->right, space);

      cout << endl;
      for (int i = 10; i < space; i++)
      {
        cout << " ";
      }
      cout << someNode->element << endl;

      DisplayTreeHorizontally(someNode->left, space);
    }
  }

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool binaryTreeInsert(const int &e){
    if (root == nullptr)
      root = createNewNode(e); // Create a new root
    else{
      // Locate the parent node
      AVLTreeNode *parent = nullptr;
      AVLTreeNode *current = root;
      while (current != nullptr)
        if (e < current->element){
          parent = current;
          current = current->left;
        }
        else if (e > current->element){
          parent = current;
          current = current->right;
        }
        else
          return false; // Duplicate node not inserted
      if (e < parent->element)
        parent->left = createNewNode(e);
      else
        parent->right = createNewNode(e);
    }

    size++;
    return true; // Element inserted
  }

  // Return a path from the root leading to the specified element
  vector<AVLTreeNode *> *path(const int &e) const{
    vector<AVLTreeNode *> *v = new vector<AVLTreeNode *>();
    AVLTreeNode *current = root;
    while (current != nullptr){
      v->push_back(current);
      if (e < current->element)
        current = current->left;
      else if (e > current->element)
        current = current->right;
      else
        break;
    }
    return v;
  }

  // insert element into AVLTree
  bool insert(int element){
    bool successful = binaryTreeInsert(element);
    if (!successful)
      return false; // element is already in the tree
    else
      balancePath(element);
    return true; // element is inserted
  }

  // remove element from AVLTree
  bool remove(int element)
  {
    if (root == nullptr)
      return false; // Element is not in the tree

    // Locate the node to be deleted and also locate its parent node
    AVLTreeNode *parent = nullptr;
    AVLTreeNode *current = root;
    while (current != nullptr)
    {
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        break; // Element is in the tree pointed by current
    }

    if (current == nullptr)
      return false; // Element is not in the tree

    // Case 0: current is a leaf
    if(current->left == nullptr && current->right == nullptr){
      if (parent == nullptr)
      {
        root = nullptr;
      }
      else
      {
        if (element < parent->element)
          parent->left = nullptr;
        else
          parent->right = nullptr;
      }

      delete current; // Delete current
    }
    // Case 1: current has no left children
    else if (current->left == nullptr)
    {
      // Connect the parent with the right child of the current node
      if (parent == nullptr)
        root = current->right;
      else
      {
        if (element < parent->element)
          parent->left = current->right;
        else
          parent->right = current->right;

        // Balance the tree if necessary
        balancePath(parent->element);
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      AVLTreeNode *parentOfRightMost = current;
      AVLTreeNode *rightMost = current->left;

      while (rightMost->right != nullptr)
      {
        parentOfRightMost = rightMost;
        rightMost = rightMost->right; // Keep going to the right
      }

      // Replace the element in current by the element in rightMost
      current->element = rightMost->element;

      // Eliminate rightmost node
      if (parentOfRightMost->right == rightMost)
        parentOfRightMost->right = rightMost->left;
      else
        // Special case: parentOfRightMost is current
        parentOfRightMost->left = rightMost->left;

      // Balance the tree if necessary
      balancePath(parentOfRightMost->element);

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }

///////EXERCISE////////
  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  AVLTreeNode *search(const int &e) const{
    return searchRecursive(this->root,e);
  }
  AVLTreeNode* searchRecursive(AVLTreeNode* node,const int& e) const{
    if(node==nullptr){
      return nullptr;
    }
    if(node->element==e){
      return node;
    }else if(e>node->element){
      searchRecursive(node->right,e);
    }else if(e<node->element){
      searchRecursive(node->left,e);
    }
  }

  // create a new AVLTreeNode
  AVLTreeNode *createNewNode(int element)
  {
    return new AVLTreeNode(element);
  }

///////EXERCISE////////
  /** Balance the nodes in the path from the specified node to the root if necessary */
  void balancePath(int element)
  {
    vector<AVLTreeNode *> *p = path(element);
    for (int i = p->size() - 1; i >= 0; i--)
    {
      AVLTreeNode *A = (*p)[i];
      AVLTreeNode *parentOfA = (A == root) ? nullptr : (*p)[i - 1];

      updateHeight(A); // ensure that height is updated first

      // WRITE CODE HERE
      // hint: we need to check if the tree is balanced at A i.e. use balanceFactors of A and A's children
      //to determine if rotations are needed (if needed then perform rotations by calling the appropriate balance
      // methods [SEE BELOW])
      int parentFactor=balanceFactor(A),leftChildFactor=balanceFactor(A->left),rightChildFactor=balanceFactor(A->right);

      if(parentFactor==2){
        if(rightChildFactor==1||rightChildFactor==0){
          balanceRR(A,parentOfA);
        }else if(rightChildFactor==-1){
          balanceRL(A,parentOfA);
        }
      }else if(parentFactor==-2){
        if(leftChildFactor==-1||leftChildFactor==0){
          balanceLL(A,parentOfA);
        }else if(leftChildFactor==1){
          balanceLR(A,parentOfA);
        }
      }

    }
  }

  /** Update the height of a specified node */
  void updateHeight(AVLTreeNode *node)
  {
    if (node->left == nullptr && node->right == nullptr) // node is a leaf
      node->height = 0;
    else if (node->left == nullptr) // node has no left subtree
      node->height = 1 + (*(node->right)).height;
    else if (node->right == nullptr) // node has no right subtree
      node->height = 1 + (*(node->left)).height;
    else
      node->height = 1 + max((*(node->right)).height, (*(node->left)).height);
  }

///////EXERCISE////////
  /** Return the balance factor of the node */
  int balanceFactor(AVLTreeNode *node){
    int rightSubTree,leftSubTree;
    if(node == nullptr)return 0;
    if(node->right){
      rightSubTree=(node->right->height);
    }else{
      rightSubTree=0;
    }
    if(node->left){
      leftSubTree=(node->left->height);
    }else{
      leftSubTree=0;
    }
    return rightSubTree-leftSubTree;
  }

  /** Balance LL */
  void balanceLL(AVLTreeNode *A, AVLTreeNode *parentOfA){
    AVLTreeNode *B = A->left; // A is left-heavy and B is left-heavy
    if (A == root)
      root = B;
    else if (parentOfA->left == A)
      parentOfA->left = B;
    else
      parentOfA->right = B;
    A->left = B->right; // Make T2 the left subtree of A
    B->right = A;       // Make A the left child of B
    updateHeight(A);
    updateHeight(B);
  }

  /** Balance LR */
  void balanceLR(AVLTreeNode *A, AVLTreeNode *parentOfA){
    AVLTreeNode *B = A->left;  // A is left-heavy
    AVLTreeNode *C = B->right; // B is right-heavy
    if (A == root)
      root = C;
    else if (parentOfA->left == A)
      parentOfA->left = C;
    else
      parentOfA->right = C;
    A->left = C->right; // Make T3 the left subtree of A
    B->right = C->left; // Make T2 the right subtree of B
    C->left = B;
    C->right = A;
    updateHeight(A);
    updateHeight(B);
    updateHeight(C);
  }

///////EXERCISE////////
  /** Balance RR */
  void balanceRR(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {
     AVLTreeNode *B = A->right; 

    if (A == root)
      root = B;
    else if (parentOfA->right == A)
      parentOfA->right = B;
    else
      parentOfA->left = B;

    A->right = B->left; 
    B->left = A;       
    updateHeight(A);
    updateHeight(B);
  }
  
///////EXERCISE////////
  /** Balance RL */
  void balanceRL(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {
    AVLTreeNode *B = A->right;  // A is left-heavy
    AVLTreeNode *C = B->left; // B is right-heavy

    if (A == root)
      root = C;
    else if (parentOfA->right == A)
      parentOfA->right = C;
    else
      parentOfA->left = C;

    A->right = C->left; // Make T3 the left subtree of A
    B->left = C->right; // Make T2 the right subtree of B
    C->right = B;
    C->left = A;

    // Adjust heights
    updateHeight(A);
    updateHeight(B);
    updateHeight(C);
  }

  // returns the number of nodes at level level in the tree
  int CountNodesAtLevel(int level)
  {
    int count = 0;
    CountNodesAtLevel(root, level, count);
    return count;
  }

///////EXERCISE////////
  // helper function for CountNodesAtLevel
  void CountNodesAtLevel(AVLTreeNode *someNode, int level, int &count){
    if(someNode==nullptr){
      return;
    }
    if(level==0){
      count+=1;
    }
    level-=1;
    CountNodesAtLevel(someNode->left,level,count);
    CountNodesAtLevel(someNode->right,level,count);
  }

  // returns the number of nodes in the tree that are between min and max (inclusive)
  int Count(int min, int max)
  {
    int count = 0;
    Count(root, min, max, count);
    return count;
  }

///////EXERCISE////////
  // helper function for Count
  void Count(AVLTreeNode *someNode, int min, int max, int &count){
    if(someNode==nullptr){
      return;
    }
    if(someNode->element>=min&&someNode->element<=max){
      count++;
    }
    if(someNode->element<max){
      Count(someNode->left,min,max,count);
      Count(someNode->right,min,max,count);
    }else{
      return;
    }
  }

///////EXERCISE////////
  // right rotates the tree at node someNode if possible (if someNode is nullptr or someNode->left is nullptr, no rotation is performed)
  void RotateRight(AVLTreeNode *someNode){
    if(someNode==nullptr){
      return;
    }
    if(someNode->left==nullptr){
      return;
    }
    if(someNode==root){
      root=someNode->left;

      AVLTreeNode* temp=someNode->left;
      someNode->left=temp->right;
      temp->right=someNode;

      updateHeight(temp);
      updateHeight(someNode);
    }else{
      AVLTreeNode* temp=someNode->left;
      someNode->left=temp->right;
      temp->right=someNode;
      
      updateHeight(temp);
      updateHeight(someNode);
    }
  }

///////EXERCISE////////
  // left rotates the tree at node someNode if possible (if someNode is nullptr or someNode->right is nullptr, no rotation is performed)
  void RotateLeft(AVLTreeNode *someNode){
    if(someNode==nullptr){
      return;
    }
    if(someNode->right==nullptr){
      return;
    }
    if(someNode==root){
      root=someNode->right;

      AVLTreeNode* temp=someNode->right;
      someNode->right=temp->left;
      temp->left=someNode;

      updateHeight(temp);
      updateHeight(someNode);
    }else{
      AVLTreeNode* temp=someNode->right;
      someNode->right=temp->left;
      temp->left=someNode;

      updateHeight(temp);
      updateHeight(someNode);
    }
  }

  // returns the diameter of the tree
  // diameter is the number of nodes along the longest path between any two leaves in the tree
  // see https://leetcode.com/problems/diameter-of-binary-tree/
  int Diameter(){
    return Diameter(root);
  }

///////EXERCISE////////
  // helper function for Diameter
  int Diameter(AVLTreeNode *someNode){
    int leftHeight=GetHeight(someNode->left);
    int rightHeight=GetHeight(someNode->right);
    return leftHeight+rightHeight+1;   
  }
  int GetHeight(AVLTreeNode* someNode){
        if (someNode == nullptr){
          return 0;
        } 
        int left= GetHeight(someNode->left);
        int right=GetHeight(someNode->right);
        if(left>right){
          return left+1;
        }else{
          return right+1;
        }
    }
  

  void DepthFirstTraversal(AVLTreeNode* someNode) {
      if (!someNode) return;
      DepthFirstTraversal(someNode->left);
      DepthFirstTraversal(someNode->right);
      cout << someNode->element << " ";
  }
  
private:
  AVLTreeNode *root;
  int size;
  int height;
  vector<AVLTreeNode*> backups;
};

#endif
