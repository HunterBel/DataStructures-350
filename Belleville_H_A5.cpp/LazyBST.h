#ifndef LAZYBST_H
#define LAZYBST_H

#include<iostream> 

template<class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T k);
        virtual ~TreeNode();

        T key; //data
        TreeNode<T> *left;
        TreeNode<T> *right;

        //Lazy BST
        int leftDepth;
        int rightDepth;
};

template<class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = T();
    leftDepth = 0;
    rightDepth = 0;
}

template<class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
    leftDepth = 0;
    rightDepth = 0;
}

template<class T>
TreeNode<T>::~TreeNode(){
    left = NULL; //class gave me this
    right = NULL;
}



template<class T>
class LazyBST{
    public:    
        LazyBST();
        virtual ~LazyBST();

        void insert(T value);
        bool contains(T value); //search()
        bool deleteNode(T k);
        TreeNode<T>* getSuccessor(TreeNode<T> *d);

        bool isEmpty();
        T* getMin();
        T* getMax();
        void printTree();
        void recPrint(TreeNode<T> *node);

        void printNodeDepth(TreeNode<T>* node, int depth) const;

        int getNodeDepth(TreeNode<T>* node) const;
        TreeNode<T>* getRoot() const;

        void rebalance();
        void rebuildTree(TreeNode<T>*& node, T* values, int start, int end);
        void extractValues(TreeNode<T>* node, T* values, int& index);





    private:
        TreeNode<T> *root;
        double imbalanceFactor = 1.5; // Depth amount for rebalance

};

template<class T>
LazyBST<T>::LazyBST(){
    root = NULL;
}

template<class T>
LazyBST<T>::~LazyBST(){
    delete root; 
}

template<class T>
void LazyBST<T>::recPrint(TreeNode<T> *node){   
    
    if(node == NULL)
        return;

    std::cout << node->key << std::endl;
    recPrint(node->left);
    recPrint(node->right);
}

template<class T>
void LazyBST<T>::printTree(){
    recPrint(root);
}

template<class T>
bool LazyBST<T>::isEmpty(){
    return (root == NULL);
}

template<class T>
T* LazyBST<T>::getMin(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }

    return &(current->key);
}

template<class T>
T* LazyBST<T>::getMax(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }

    return &(current->key);
}

template<class T>
void LazyBST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);

    if(isEmpty()){
        root = node;
    }
    else {
        TreeNode<T> *current  = root;
        TreeNode<T> *parent  = root;

        int depth = 0; // Initialize depth counter

        while(true){
            parent = current;

            if(value < current->key){
                current = current->left;
                parent->leftDepth++; // Increment left depth
                depth++; // Increment depth as we traverse left
                if(current == NULL){
                    parent->left = node;
                    node->leftDepth = depth; // Set depth for new node
                    break;
                }
            }
            else{
                current = current->right;
                parent->rightDepth++; // Increment right depth
                depth++; // Increment depth as we traverse right
                if(current == NULL){
                    parent->right = node;
                    node->rightDepth = depth; // Set depth for new node
                    break;
                }
            }
        }
    }
}



template<class T>
bool LazyBST<T>::contains(T value){
    if(isEmpty())
        return false;

    TreeNode<T> *current = root;

    while(current->key != value){
        if(value < current->key){
            current = current->left;
        }
        else{
            current = current->right;
        }

        if(current == NULL)
            return false;
    }
    return true;
}



template<class T>
bool LazyBST<T>::deleteNode(T k){

    if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(current != NULL && current->key != k){ 
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            return false;
        }
    }

    //if we get here that means we found the node that needs to be deleted 

    /**
     * leaf node
    */
   if(current->left == NULL && current->right == NULL){

        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
   }

   /**
    * node to be deleted has 1 child
   */
  
  //left
    else if(current->right == NULL){
        //node has 1 child and its a left child
        if(current == root){
            root = current->left;
        }
        else if(isLeft){
            parent->left = current->left;
        }
        else{
            parent->right = current->left;
        }
    }

  //right
    else if(current->left == NULL){   //might be wrong 
        //node has 1 child and its a right child
        if(current == root){
            root = current->right;
        }
        else if(isLeft){
            parent->left = current->right;
        }
        else{
            parent->right = current->right;
        }
    }

    /**
     * has 2 children
    */

    else{
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }
        
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    delete current;
    return true;

}

template<class T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d; //successor parent 
    TreeNode<T> *successor = d; 
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current; 
        current = current->left; 
    }

    //once we get here, we identified our successor
    //now we need to check if the successor is the decentdant of the right child
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;

}

template<class T>
void LazyBST<T>::printNodeDepth(TreeNode<T>* node, int depth) const {
    if (node == nullptr) return;
    std::cout << "Node with key " << node->key << " has depth " << depth << std::endl;
    printNodeDepth(node->left, depth + 1);
    printNodeDepth(node->right, depth + 1);
}


template<class T>
int LazyBST<T>::getNodeDepth(TreeNode<T>* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = getNodeDepth(node->left);
        int rightDepth = getNodeDepth(node->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
}

template<class T>
TreeNode<T>* LazyBST<T>::getRoot() const {
    return root;
}

template<class T>
void LazyBST<T>::rebalance() {
    if (root == nullptr) return;
    if (abs(root->leftDepth - root->rightDepth) <= imbalanceFactor) return;

    int treeSize = root->leftDepth + root->rightDepth + 1;
    T* values = new T[treeSize];
    int index = 0;
    extractValues(root, values, index);

    delete root;
    root = nullptr;
    rebuildTree(root, values, 0, treeSize - 1);

    delete[] values;
}

template<class T>
void LazyBST<T>::rebuildTree(TreeNode<T>*& node, T* values, int start, int end) {
    if (start > end) {
        node = nullptr; 
        return;
    }

    int mid = start + (end - start) / 2; 
    node = new TreeNode<T>(values[mid]); 

    // Recursively rebuilds the left and right subtrees
    rebuildTree(node->left, values, start, mid - 1);
    rebuildTree(node->right, values, mid + 1, end);
}




template<class T>
void LazyBST<T>::extractValues(TreeNode<T>* node, T* values, int& index) {
    // Create an array to simulate the function call stack
    TreeNode<T>** stack = new TreeNode<T>*[1000]; // Adjust the size as needed
    int top = -1; // Initialize top of the stack

    while (node != nullptr || top != -1) {
        // Traverse left subtree and push nodes onto the stack
        while (node != nullptr) {
            stack[++top] = node;
            node = node->left;
        }

        // Pop node from stack and process its key
        node = stack[top--];
        values[index++] = node->key;

        // Move to the right subtree
        node = node->right;
    }

    delete[] stack; // Deallocate stack array
}



#endif 

