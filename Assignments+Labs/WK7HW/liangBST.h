#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
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

class BST
{
public:
  BST() // default constructor
  {
    root = nullptr;
    size = 0;
  }

  BST(int *elements, int arraySize) // defined constructor
  {
    root = nullptr;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
  }

  /* Copy constructor */
  BST(const BST& tree)
  {
    root = nullptr;
    size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
  }

  BST(int *elements,int arraySize,bool balanced){
    root = nullptr;
    size = 0;
    if(balanced==false){
      for (int i = 0; i < arraySize; i++){
        insert(elements[i]);
      }
    }else{
      vector<int> vec=arraytoVec(elements,arraySize);
      simpleSort(vec);
      insertMidpoint(vec);
    }
  }

  void insertMidpoint(vector<int> &v,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        this->insert(v[mid]);
        insertMidpoint(v,l,mid);
        insertMidpoint(v,mid+1,h);
    }
  }

  void insertMidpoint(vector<int> &v){
    insertMidpoint(v,0,v.size()-1);
  }
  
  vector<int> arraytoVec(int * arr,int arrSize){
    vector<int> vec;
    for (int i = 0; i < arrSize; i++){
      vec.push_back(arr[i]);
    }
    return vec;  
  }

  void simpleSort(vector<int> &v){
    unsigned i;
    int j,tmp;
    for(i=1;i<v.size();i++){
        tmp=v[i];
        for(j=i-1;j>=0&&v[j]>tmp;j--){
            v[j+1]=v[j];
        }
        v[j+1]=tmp;
    }
  }

/////EXERCISE
  /* Copies the element from the specified tree to this tree */
  void copy(const TreeNode* root){
    if(root==nullptr){
        return;
    }
      this->insert(root->element);
      copy(root->left);
      copy(root->right);
  }

  /* Destructor */
  ~BST(){
    clear();
  }

/////EXERCISE
  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  TreeNode* search(const int& e) const{  
    return searchRecursive(this->root,e);
  }

  TreeNode* searchRecursive(TreeNode* root,const int& e) const{
    if(root==nullptr){
      return nullptr;
    }
    if(root->element==e){
      return root;
    }else if(e>root->element){
      searchRecursive(root->right,e);
    }else if(e<root->element){
      searchRecursive(root->left,e);
    }
  }

  TreeNode* createNewNode(const int& e)
  {
    return new TreeNode(e);
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool insert(const int& e){
    if (root == nullptr)
      root = createNewNode(e); // Create a new root
    else{
      // Locate the parent node
      TreeNode* parent = nullptr;
      TreeNode* current = root;
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

  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const TreeNode* someNode) const{
    if (someNode == nullptr) return;
    inorder(someNode->left); // process all nodes in left sub-tree of someNode
    cout << someNode->element << " "; // process someNode
    inorder(someNode->right); // process all nodes in right sub-tree of someNode
  }

  /* Postorder traversal */
  void postorder() const
  {
    postorder(root);
  }

/////EXERCISE
  /** Inorder traversal from a subtree */
  void postorder(const TreeNode* someNode) const{
    if (someNode == nullptr)return;
    postorder(someNode->left);
    postorder(someNode->right);
    cout << someNode->element << " ";
  }

  /* Preorder traversal */
  void preorder() const
  {
    preorder(root);
  }

/////EXERCISE
  /* Preorder traversal from a subtree */
  void preorder(const TreeNode* someNode) const{
    if (someNode == nullptr)return;
    cout << someNode->element << " ";
    preorder(someNode->left);
    preorder(someNode->right);
  }

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }

/////EXERCISE
  /* Remove all nodes from the tree */
  void clear(){
    clearRecursive(this->root);
    root=nullptr;
  }
  void clearRecursive(TreeNode* temp){
    if(temp==nullptr){
      delete temp;
      return;
    }
    clearRecursive(temp->left);
    clearRecursive(temp->right);
    delete temp;
  }

/////EXERCISE
  /* Return a path from the root leading to the specified element.
  If specified element does not exist in the tree then add a nullptr 
  to the end.*/
  vector<TreeNode*> path(const int& e) const{
    std::vector<TreeNode*> vec;
    pathRecursive(vec,this->root,e);
    return vec;
  }
  void pathRecursive(vector<TreeNode*> &v,TreeNode *temp,const int& e) const{
    if(temp==nullptr||temp->element==e){
      v.push_back(temp);
      return;
    }
    v.push_back(temp);
    if(e>temp->element){
      pathRecursive(v,temp->right,e);
    }else if (e<temp->element){
      pathRecursive(v,temp->left,e);
    }
  }
  

  /* Delete an element e from the binary tree.
   * Return true if the element is deleted successfully
   * Return false if the element is not in the tree */
  bool remove(const int& e)
  {
    // Locate the node to be deleted and also locate its parent node
    TreeNode* parent = nullptr;
    TreeNode* current = root;
    while (current != nullptr)
    {
      if (e < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        break; // Element e is in the tree pointed by current
    }

    if (current == nullptr)
      return false; // Element e is not in the tree

    // Case 1: current has no left children
    if (current->left == nullptr)
    {
      // Connect the parent with the right child of the current node
      if (parent == nullptr)
      {
        root = current->right;
      }
      else
      {
        if (e < parent->element)
          parent->left = current->right;
        else
          parent->right = current->right;
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      TreeNode* parentOfRightMost = current;
      TreeNode* rightMost = current->left;

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
        // Special case: parentOfRightMost->right == current
        parentOfRightMost->left = rightMost->left;

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }

  void SaveTreeToFileBFS(string file){
    ofstream out;
    out.open(file);
    queue<int> data;
    SaveTreeToFileBFS(data,root,out);
    out.close();
  }

  void SaveTreeToFileBFS(queue<int> &q,TreeNode* someNode,ofstream &out){
    if(someNode==nullptr){
      return;
    }
    if(!q.empty()||someNode==this->root){
      q.push(someNode->element);
      SaveTreeToFileBFS(q,someNode->left,out);
      SaveTreeToFileBFS(q,someNode->right,out);
      out<<q.front()<<",";
      q.pop();
    }
    if(q.empty()){
      return;
    }
  }

  void LoadTreeFromFile(string file){
    ifstream fin;
    string line;
    fin.open(file);
    if(fin.fail()){
        cerr<<"FILE NOT FOUND\n";
        return;
    }
    clear();
    while(getline(fin,line,',')){
      this->insert(stoi(line));   
    }
    fin.close();
  }

  TreeNode* kthSmallest(int k){
    if(k>this->size||k<1){
      return nullptr;
    }
    vector<int> vec;
    getVectorOfElements(vec,root);
    int elementNeeded=vec[k-1];
    TreeNode* ret=search(elementNeeded);
    return ret;
  }

  void getVectorOfElements(vector<int> &v,TreeNode* someNode){
    if (someNode == nullptr){
      return;
    }
    getVectorOfElements(v,someNode->left); 
    v.push_back(someNode->element);
    getVectorOfElements(v,someNode->right);
  }

  TreeNode* ClosestCommonAncestor(TreeNode* node1, TreeNode* node2){
    vector<TreeNode*> path1,path2;
    path1=this->path(node1->element);
    path2=this->path(node2->element);
    int index;
    TreeNode* ret=nullptr;
    if(path1.size()>path2.size()){
      index=path2.size();
    }else{
      index=path1.size();
    }
    for(int i=index-1;i>=0;i--){
        if(path1[i]->element==path2[i]->element){
          ret=path1[i];
          break;
        }
    }
    return ret;
  }

  const BST &operator=(BST &rhs){
    if(*this==rhs){
      return *this;
    }
      this->clear();
      this->copy(rhs.root);
      return *this;
    }

  bool operator==(BST &rhs){
    bool control=true;
    exploreTree(control,this->root,rhs.root);
    return control;
  }
  
  void exploreTree(bool &control,TreeNode* thisBst,TreeNode* rhsBst){
    if(thisBst==nullptr&&rhsBst==nullptr){
      return;
    }else if(thisBst==nullptr||rhsBst==nullptr){
      control=false;
      return;
    }
    if(thisBst->element!=rhsBst->element){
      control=false;
    }
    exploreTree(control,thisBst->left,rhsBst->left);
    exploreTree(control,thisBst->right,rhsBst->right);
  }

/////ADDITIONAL EXERCISES/////

  //   void rotateRight(TreeNode* someNode){
  //     if(!root){
  //       return;
  //     }
  //     if(someNode==root){
  //       TreeNode* leftOfRoot=root->left;
  //       leftOfRoot->right=root;
  //       root->left=nullptr;
  //       root=leftOfRoot;
  //     }else{
  //       TreeNode* parent=getParent(someNode);
  //       TreeNode* leftOfTarget=someNode->left;
  //       leftOfTarget->right=someNode;
  //       someNode->left=nullptr;
  //       if(someNode->element>parent->element){
  //         parent->right=leftOfTarget;
  //       }else{
  //         parent->left=leftOfTarget;
  //       }
  //     }
  //   }

  // TreeNode* getParent(TreeNode* someNode){
  //     TreeNode* parent = nullptr;
  //     TreeNode* current = root;
  //     while (current != nullptr){
  //       if (someNode->element < current->element)
  //       {
  //         parent = current;
  //         current = current->left;
  //       }
  //       else if (someNode->element > current->element)
  //       {
  //         parent = current;
  //         current = current->right;
  //       }
  //       else
  //         return current;
  //     }
  //     return nullptr;
  // }

  //   void postorderHeightOfNodes(){
  //     postorderHeightOfNodes(root);
  //   }
  //   void postorderHeightOfNodes(TreeNode* someNode){
  //     if (someNode == nullptr){
  //       std::cout<<"Tree is empty...\n";
  //       return;
  //     } 
  //     postorderHeightOfNodes(someNode->left);
  //     postorderHeightOfNodes(someNode->right);
  //     std::cout<<"[Height of "<<someNode->element<<":"<< GetHeight(someNode)<<"]->"; 
  //   }

  //   int getHeight2(){
  //       if(root == nullptr){
  //           return 0;
  //       }
  //       else{
  //           return getHeight2(root);
  //       }
  //   }

  //   int getHeight2(TreeNode* someNode){
  //     if(!someNode->left&&!someNode->right){
  //       return 0;
  //     }else if(someNode->left&&!someNode->right){
  //       int left= getHeight2(someNode->left);
  //       return left+1;
  //     }else if(!someNode->left&&someNode->right){
  //       int right=getHeight2(someNode->right);
  //       return right+1;
  //     }else{ 
  //       int left= getHeight2(someNode->left);
  //       int right=getHeight2(someNode->right);
  //       if(left>right){
  //         return left+1;
  //       }else{
  //         return right+1;
  //       }
  //     }
  //   }

  //   void OutputNodeHeights(){
  //     if(root){
  //       OutputNodeHeights(root);
  //     }
  //     else{
  //       cout << "Tree is empty!\n";
  //     }
  //   }

  //   void OutputNodeHeights(TreeNode *aNode){
  //     if(!aNode){
  //       return;
  //     }
  //     else{
  //       OutputNodeHeights(aNode->left);
  //       cout << "Node: " << aNode->element << " Height : " << getHeight2(aNode) <<endl;
  //       OutputNodeHeights(aNode->right);
  //     }
  //   }

    // void OuputBalanceFactor(){
    //   OutputBalanceFactor(root);
    // }

    // void OuputBalanceFactor(TreeNode* someNode){
    //   if (someNode == nullptr){
    //     std::cout<<"Tree is empty...\n";
    //     return;
    //   } 
    //   OutputBalanceFactor(someNode->left);
    //   OutputBalanceFactor(someNode->right);
    //   std::cout<<"[Balance of "<<someNode->element<<":"<< getBalanceFactor(someNode)<<"]->"; 
    // }

    // int getBalanceFactor(TreeNode * someNode){
    //   if(someNode==nullptr){
    //     return 0;
    //   }
    //   int left=GetHeight(someNode->left);
    //   int right=GetHeight(someNode->right);
    //   return left-right;
    // }

    void OutputBalanceFactors(){
      if(root){
        OutputBalanceFactors(root);
      }
      else{
        cout << "tree is empty!\n";
      }
    }

    void OutputBalanceFactors(TreeNode *node){
      if(!node->left && !node->right){
        cout << "Node Value: " << node->element << ", Balance Factor: 0" << endl;
      }
      else if(node->left && !node->right){
        cout << "Node Value: " << node->element << ", Balance Factor: " << GetHeight(node->left) << endl;
      }
      else if(!node->left && node->right){
        cout << "Node Value: " << node->element << ", Balance Factor: " << -GetHeight(node->right) << endl;
      }
      else {
        OutputBalanceFactors(node->left);
        cout << "Node Value: " << node->element << ", Balance Factor: " << GetHeight(node->left) - GetHeight(node->right) << endl;
        OutputBalanceFactors(node->right);
      }
    }

    // returns the height of the tree
    int GetHeight(){
        if(root == nullptr){
            return 0;
        }
        else{
            return GetHeight(root);
        }
    }

/////EXERCISE
    // returns the height of someNode
    int GetHeight(TreeNode* someNode){
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

    // Increment each node's value by 1
    void IncrementByOne(){
        InorderIncrementByOne(root);
    }

/////EXERCISE
    // Increment each node (that is part of the tree rooted at someNode) by 1
    void InorderIncrementByOne(TreeNode* someTreeNode){
      if(someTreeNode==nullptr){
        return;
      }
      someTreeNode->element=someTreeNode->element+1;
      InorderIncrementByOne(someTreeNode->left);
      InorderIncrementByOne(someTreeNode->right);
    }

    // returns the number of nodes in the tree
    int NodeCount(){
        return InOrderNodeCount(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode
    int InOrderNodeCount(TreeNode* someNode){
      if (someNode == nullptr) return 0;
      int left=InOrderNodeCount(someNode->left);
      int right=InOrderNodeCount(someNode->left);
      return left+right+1;
    }
    

    // returns the number of nodes in the tree with odd values
    int NodesWithOddValues(){
      return InOrderNodesWithOddValues(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode with odd values
    int InOrderNodesWithOddValues(TreeNode* someNode){
        if (someNode == nullptr){
          return 0;
        }
        int left=InOrderNodesWithOddValues(someNode->left);
        int right=InOrderNodesWithOddValues(someNode->right);
        if(someNode->element%2!=0){
          return right+left+1;
        }else{
          return right+left;
        }
    }

  // level order display
    void LevelOrderDisplay(){
        LevelOrderDisplay(root);
    }

/////EXERCISE
    // level order display of the tree rooted at someNode
    void LevelOrderDisplay(TreeNode* someNode){
        // use a queue, STL queue is fine
        //enqueue root
        //while q is not empty
        //enqueue all roots elements
        //dequeue root
        queue<TreeNode*> q,results;
        q.push(someNode);
        results.push(someNode);
        LevelOrderNodes(q,results);
        std::cout<<"{ ";
        unsigned tmp=results.size();
        for(unsigned i=0;i<tmp;i++){
          std::cout<<results.front()->element<<" ";
          results.pop();
        }
        std::cout<<"}\n";
    }

    void LevelOrderNodes(queue<TreeNode*> &q,queue<TreeNode*> &results){
      if(q.empty()){
        return;
      }else{
        TreeNode *temp=q.front();
        if(temp->left!=nullptr){
          q.push(temp->left);
          results.push(temp->left);  
        }
        if(temp->right!=nullptr){
          q.push(temp->right);
          results.push(temp->right);
        }
        q.pop();
        LevelOrderNodes(q,results);
      }
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
