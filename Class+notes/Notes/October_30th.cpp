#include <iostream>
#include <vector>
#include <queue>
#include <fstream>


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
      std::vector<int> vec=arraytoVec(elements,arraySize);
      simpleSort(vec);
      insertMidpoint(vec);
    }
  }

  void insertMidpoint(std::vector<int> &v,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        this->insert(v[mid]);
        insertMidpoint(v,l,mid);
        insertMidpoint(v,mid+1,h);
    }
  }

  void insertMidpoint(std::vector<int> &v){
    insertMidpoint(v,0,v.size()-1);
  }
  
  std::vector<int> arraytoVec(int * arr,int arrSize){
    std::vector<int> vec;
    for (int i = 0; i < arrSize; i++){
      vec.push_back(arr[i]);
    }
    return vec;  
  }

  void simpleSort(std::vector<int> &v){
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
//   bool insert(const int& e)
//   {
//     if (root == nullptr)
//       root = createNewNode(e); // Create a new root
//     else
//     {
//       // Locate the parent node
//       TreeNode* parent = nullptr;
//       TreeNode* current = root;
//       while (current != nullptr)
//         if (e < current->element)
//         {
//           parent = current;
//           current = current->left;
//         }
//         else if (e > current->element)
//         {
//           parent = current;
//           current = current->right;
//         }
//         else
//           return false; // Duplicate node not inserted

//       // Create the new node and attach it to the parent node
//       if (e < parent->element)
//         parent->left = createNewNode(e);
//       else
//         parent->right = createNewNode(e);
//     }

//     size++;
//     return true; // Element inserted
//   }
    bool insert(const int& e){
        if(root==nullptr){
            root= createNewNode(e);
        }else{
            insert(root,e);
        }
        size++;
        return true;
    }
    void insert(TreeNode* current, int e){
        if(!current->left){
            current->left=createNewNode(e);
            return;
        }else if(!current->right){
            current->right=createNewNode(e);
            return;
        }else{
            std::queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }else{
                    temp->left=createNewNode(e);
                }
                if(temp->right !=nullptr){
                    q.push(temp->right);
                }
                else{
                    temp->right=createNewNode(e);
                }
            }
        }
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
    std::cout << someNode->element << " "; // process someNode
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
    if (someNode == nullptr){
      return;
    }
    postorder(someNode->left);
    postorder(someNode->right);
    std::cout << someNode->element << " ";
  }

  /* Preorder traversal */
  void preorder() const
  {
    preorder(root);
  }

/////EXERCISE
  /* Preorder traversal from a subtree */
  void preorder(const TreeNode* someNode) const{
    if (someNode == nullptr){
      return;
    }
    std::cout << someNode->element << " ";
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
  std::vector<TreeNode*> path(const int& e) const{
    std::vector<TreeNode*> vec;
    pathRecursive(vec,this->root,e);
    return vec;
  }
  void pathRecursive(std::vector<TreeNode*> &v,TreeNode *temp,const int& e) const{
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

  void SaveTreeToFileBFS(std::string file){
    std::ofstream out;
    out.open(file);
    std::queue<int> data;
    SaveTreeToFileBFS(data,root,out);
    out.close();
  }

  void SaveTreeToFileBFS(std::queue<int> &q,TreeNode* someNode,std::ofstream &out){
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

  void LoadTreeFromFile(std::string file){
    std::ifstream fin;
    std::string line;
    fin.open(file);
    if(fin.fail()){
        std::cerr<<"FILE NOT FOUND\n";
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
    std::vector<int> vec;
    getVectorOfElements(vec,root);
    int elementNeeded=vec[k-1];
    TreeNode* ret=search(elementNeeded);
    return ret;
  }

  void getVectorOfElements(std::vector<int> &v,TreeNode* someNode){
    if (someNode == nullptr){
      return;
    }
    getVectorOfElements(v,someNode->left); 
    v.push_back(someNode->element);
    getVectorOfElements(v,someNode->right);
  }

  TreeNode* ClosestCommonAncestor(TreeNode* node1, TreeNode* node2){
    std::vector<TreeNode*> path1,path2;
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

    void OutputBalanceFactors(){
      if(root){
        OutputBalanceFactors(root);
      }
      else{
        std::cout << "tree is empty!\n";
      }
    }

    void OutputBalanceFactors(TreeNode *node){
      if(!node->left && !node->right){
        std::cout << "Node Value: " << node->element << ", Balance Factor: 0" << std::endl;
      }
      else if(node->left && !node->right){
        std::cout << "Node Value: " << node->element << ", Balance Factor: " << GetHeight(node->left) << std::endl;
      }
      else if(!node->left && node->right){
        std::cout << "Node Value: " << node->element << ", Balance Factor: " << -GetHeight(node->right) << std::endl;
      }
      else {
        OutputBalanceFactors(node->left);
        std::cout << "Node Value: " << node->element << ", Balance Factor: " << GetHeight(node->left) - GetHeight(node->right) << std::endl;
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

            std::cout << std::endl;
            for(int i = 10; i < space; i++){
                std::cout << " ";
            }
            std::cout << someNode->element << std::endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }
private:
  TreeNode* root;
  int size;
};


int main(){
    return 0;
}