#ifndef BST_H
#define BST_H

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

class node{
    private:
    public:
        int element;
        node* left;
        node* right;
        node* parent;
        node();
        node(const int &e);
        node(const int &e,node* p);
        // friend std::ostream& operator<<(std::ostream &out,const node &rhs);
};

class bst{
    private:
        node* root;
        int size;
        node* createNewNode(const int &e,node*p);
        void searchHelper(node* root,bool &key,int e);
        void DisplayTreeHorizontally(node* someNode, int space);
        void breadthFirstTraversal(std::queue<node*> q,std::queue<node*>results);
        int getHeight(node* somenode);
        void printParent(node* someNode);
        node* getParent(node* someNode);
        void getNumberOfleaves(node* someNode,int& key);
        void getNumberOfNonleaves(node* someNode,int& key);
        void mirror(node *someNode);
        void exploreTree(bool &control,node* thisBst,node* rhsBst);
        std::vector<int> bstToPreOrderVector(const bst& object);
        void copy(node* someNode);
        void clear(node* someNode);
    public:
        bst();
        bst(int *elements, int arraySize);
        bst(const bst& rhs);
        void DisplayTreeHorizontally();
        bool insert(const int &e);
        bool remove(const int& e);
        bool search(const int &e);
        void breadthFirstTraversal();
        int height();
        void inOrderTraversal();
        void preOrderTraversal();
        void postOrderTraversal();
        void printParent();
        int getNumberOfleaves();
        int getNumberOfNonleaves();
        bool isPerfect();
        void mirror();
        bool operator==(const bst& rhs);
        friend const bst operator+(const bst& lhs,const bst& rhs);
        int operator[](int i);
        unsigned length();
        void copy(const bst& rhs);
        void clear();
        ~bst();

        
};
node::node(){
    this->element=0;
    this->left=nullptr;
    this->right=nullptr;
    this->parent=nullptr;
}
node::node(const int &e){
    this->element=e;
    this->left=nullptr;
    this->right=nullptr;
    this->parent=nullptr;
}
node::node(const int &e,node* p){
    this->element=e;
    this->left=nullptr;
    this->right=nullptr;
    this->parent=p;
}
bst::bst(){
    root=nullptr;
    size=0;
}
bst::bst(int * elements, int arraySize){
    root = nullptr;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
}

bst::bst(const bst& rhs){
    root=nullptr;
    size=0;
    this->copy(rhs);
}

node* bst::createNewNode(const int &e,node * p){
    return new node(e,p);
}

bool bst::insert(const int &e){
    if (root == nullptr)
      root = createNewNode(e,nullptr); // Create a new root
    else
    {
      // Locate the parent node
      node* parents = nullptr;
      node* current = root;
      while (current != nullptr)
        if (e < current->element)
        {
          parents = current;
          current = current->left;
        }
        else if (e > current->element)
        {
          parents = current;
          current = current->right;
        }
        else
          return false; // Duplicate node not inserted

      // Create the new node and attach it to the parent node
      if (e < parents->element)
        parents->left = createNewNode(e,parents);
      else
        parents->right = createNewNode(e,parents);
    }

    size++;
    return true; 
}

bool bst::remove(const int& e)
  {
    // Locate the node to be deleted and also locate its parent node
    node* parents = nullptr;
    node* current = root;
    while (current != nullptr)
    {
      if (e < current->element)
      {
        parents = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parents = current;
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
      if (parents == nullptr)
      {
        root = current->right;
      }
      else
      {
        if (e < parents->element){
            parents->left = current->right;
            current->right->parent=parents;
        }
        else{
            parents->right = current->right;
            current->right->parent=parents;
        }
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      node* parentOfRightMost = current;
      node* rightMost = current->left;

      while (rightMost->right != nullptr)
      {
        parentOfRightMost = rightMost;
        rightMost = rightMost->right; // Keep going to the right
      }

      // Replace the element in current by the element in rightMost
      current->element = rightMost->element;

      // Eliminate rightmost node
      if (parentOfRightMost->right == rightMost){
        parentOfRightMost->right = rightMost->left;
        rightMost->parent=parentOfRightMost;
      }
      else{
        // Special case: parentOfRightMost->right == current
        parentOfRightMost->left = rightMost->left;
        rightMost->parent=parentOfRightMost;
      }

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }
// display tree like a tree horizontally
void bst::DisplayTreeHorizontally(){
    DisplayTreeHorizontally(root, 0);
}

// display the tree rooted at someNode like a tree, horizontally
void bst::DisplayTreeHorizontally(node* someNode, int space){
    if(someNode == nullptr){
        return;
    }
    else{
        space += 10;

        DisplayTreeHorizontally(someNode->right, space);

        std::cout << std::endl;
        for(int i = 10; i < space; i++){
            std::cout << " ";
        }
        std::cout << someNode->element << std::endl;

        DisplayTreeHorizontally(someNode->left, space);
    }
}

bool bst::search(const int &e){
    bool control=false;
    searchHelper(root,control,e);
    return control;
}
void bst::searchHelper(node* someNode, bool &key,int e){
    if(someNode==nullptr){
        return;
    }
    if(someNode->element==e){
        key=true;
        return;
    }
    if(!key){
        searchHelper(someNode->left,key,e);
        searchHelper(someNode->right,key,e);
    }
    return;
}

void bst::breadthFirstTraversal(){
    std::queue<node*> q,results;
    q.push(root);
    results.push(root);
    breadthFirstTraversal(q,results);
    std::cout<<"{ ";
    unsigned tmp=results.size();
    for(unsigned i=0;i<tmp;i++){
        std::cout<<results.front()->element<<" ";
        results.pop();
    }
    std::cout<<"}\n";
}
void bst::breadthFirstTraversal(std::queue<node*> q,std::queue<node*>results){
    if(q.empty()){
        return;
      }else{
        node *temp=q.front();
        if(temp->left!=nullptr){
          q.push(temp->left);
          results.push(temp->left);  
        }
        if(temp->right!=nullptr){
          q.push(temp->right);
          results.push(temp->right);
        }
        q.pop();
        breadthFirstTraversal(q,results);
      }
}
int bst::height(){
    return getHeight(root);
}

int bst::getHeight(node* someNode){
    if(someNode==nullptr){
        return 0;
    }
    int left=getHeight(someNode->left);
    int right=getHeight(someNode->right);
    if(left>right){
        return left+1;
    }else{
        return right+1;
    }
}
void bst::inOrderTraversal(){
    if(!root){
        std::cout<<"{ }";
        return;
    }
    std::stack<node*> stk;
    node* tmp=root;
    stk.push(root);
    tmp=tmp->left;
    std::cout<<"{";
    while(!stk.empty()||tmp){
        while(tmp){
            stk.push(tmp);
            tmp=tmp->left;
        }
        tmp=stk.top();
        std::cout<<tmp->element<<" ";
        stk.pop();
        tmp=tmp->right;
    }
    std::cout<<"}\n";
    return;
}
void bst::preOrderTraversal(){
    if(!root){
        std::cout<<"{ }";
        return;
    }
    std::stack<node*> stk;
    node* tmp=root;
    stk.push(root);
    std::cout<<"{";
    while(!stk.empty()){
        tmp=stk.top();
        std::cout<<tmp->element<<" ";
        stk.pop();
        if(tmp->right){
            stk.push(tmp->right);
        }
        if(tmp->left){
            stk.push(tmp->left);
        }
    }
    std::cout<<"}\n";
    return;
}
void bst::postOrderTraversal(){
    if(!root){
        std::cout<<"{ }";
        return;
    }
    std::stack<node*> stk;
    node* tmp=root;
    node* prev=nullptr;
    stk.push(root);
    tmp=tmp->left;
    std::cout<<"{";
    while(!stk.empty()){
        tmp=stk.top();
        if(!prev||prev->left==tmp||prev->right==tmp){
            if(tmp->left){
                stk.push(tmp->left);
            }else if(tmp->right){
                stk.push(tmp->right);
            }else{
                stk.pop();
                std::cout<<tmp->element<<" ";
            }
        }else if(tmp->left==prev){
            if(tmp->right){
                stk.push(tmp->right);
            }else{
                stk.pop();
                std::cout<<tmp->element<<" ";
            }
        }else if(tmp->right==prev){
            stk.pop();
            std::cout<<tmp->element<<" ";
        }
        prev=tmp;
    }
    std::cout<<"}\n";
    return;
}
void bst::printParent(){
    printParent(root);
    return;
}
void bst::printParent(node* someNode){
    //inorder
    if (!someNode){
        return;
    }
    printParent(someNode->left);
    if(someNode->parent){
        std::cout<<"Parent of "<<someNode->element<<" is:"<<someNode->parent->element<<"\n";
    }else{
        std::cout<<"Root "<<someNode->element<<"\n";
    }
    printParent(someNode->right);
}
node* bst::getParent(node* someNode){
    return someNode->parent;
}
int bst::getNumberOfleaves(){
    int key=0;
    getNumberOfleaves(root,key);
    return key;
}
void bst::getNumberOfleaves(node* someNode,int & key){
    
    if(!someNode){
        return;
    }
    if(getHeight(someNode)==1){
        key+=1;
    }
    getNumberOfleaves(someNode->left,key);
    getNumberOfleaves(someNode->right,key);
}

int bst::getNumberOfNonleaves(){
    int key=0;
    getNumberOfNonleaves(root,key);
    return key;
}
void bst::getNumberOfNonleaves(node* someNode,int & key){
    
    if(!someNode){
        return;
    }
    if(getHeight(someNode)>1){
        key+=1;
    }
    getNumberOfNonleaves(someNode->left,key);
    getNumberOfNonleaves(someNode->right,key);
}
bool bst::isPerfect(){
    return size==(pow(2,height())-1);
}
void bst::mirror(){
    mirror(root);
    return;
}
void bst::mirror(node* someNode){
    if(!someNode){
        return;
    }
    node tmp;
    tmp.left=someNode->left;
    someNode->left=someNode->right;
    someNode->right=tmp.left;
    mirror(someNode->left);
    mirror(someNode->right);
    return;
}

bool bst::operator==(const bst& rhs){
    bool control=true;
    exploreTree(control,this->root,rhs.root);
    return control;
} 
void bst::exploreTree(bool &control,node* thisBst,node* rhsBst){
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


const bst operator+(const bst& lhs,const bst& rhs){
    bst ret;
    std::stack<node*> s;
    std::vector<int> toInsert;
    node* current;
    if(lhs.root){
        current=lhs.root;
        s.push(lhs.root);
    }

    // std::cout<<"It got here\n";
    while(!s.empty()){
        current=s.top();
        toInsert.push_back(current->element);
        s.pop();
        if(current->right){
            s.push(current->right);
        }
        if(current->left){
            s.push(current->left);
        }
    }
    std::cout<<"It got here\n";
    if(lhs.root){
        current=rhs.root;
        s.push(rhs.root);
    }
    while(!s.empty()){
        current=s.top();
        toInsert.push_back(current->element);
        s.pop();
        if(current->right){
            s.push(current->right);
        }
        if(current->left){
            s.push(current->left);
        }
    }
    // std::cout<<"It got here\n";
    for(unsigned i=0;i<toInsert.size();i++){
        ret.insert(toInsert[i]);
        // std::cout<<toInsert[i]<<"\n";
    }
    std::cout<<"It got here\n";
    return ret;
}
std::vector<int> bst::bstToPreOrderVector(const bst& object){
    std::vector<int> ret;
    std::stack<node*> s;
    node* current;
    if(object.root){
        current=object.root;
        s.push(object.root);
    }
    while(!s.empty()){
        current=s.top();
        ret.push_back(current->element);
        s.pop();
        if(current->right){
            s.push(current->right);
        }
        if(current->left){
            s.push(current->left);
        }
    }
    return ret;
}

int bst::operator[](int i){
    if(!root){
        return 0;
    }
    std::stack<node*> stk;
    std::vector<int> ele;
    node* tmp=root;
    stk.push(root);
    tmp=tmp->left;
    
    while(!stk.empty()||tmp){
        while(tmp){
            stk.push(tmp);
            tmp=tmp->left;
        }
        tmp=stk.top();
        ele.push_back(tmp->element);
        stk.pop();
        tmp=tmp->right;
    }
    return ele[i];
}
unsigned bst::length(){
    return unsigned(size);
}
void bst::copy(const bst& rhs){
    this->clear();
    this->copy(rhs.root);
}
void bst::copy(node* someNode){
    if(!someNode){
        return;
    }
    this->insert(someNode->element);
    copy(someNode->left);
    copy(someNode->right);
    return;
}
void bst::clear(){
    this->clear(root);
    root=nullptr;
}
void bst::clear(node* someNode){
    if(!someNode){
        delete someNode;
        return;
    }
    clear(someNode->left);
    clear(someNode->right);
    delete someNode;
    return;
}
bst::~bst(){
    this->clear();
}

#endif