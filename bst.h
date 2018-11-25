#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

using namespace std;

struct Node{
    int info;
    Node *left;
    Node *right;
};

struct Bst{
    Node *rootPtr; //pointer to the root node
    Bst(){
        rootPtr = NULL; //the tree is empty
    }

    bool emptyTree(){
        return rootPtr == NULL;
    }
    
    Node* findMin(Node *root){
        if(root == NULL)
            return NULL;
        else if(root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }

    Node* findMax(Node *root){
        if(root == NULL)
            return NULL;
        else if(root->right == NULL)
            return root;
        else
            return findMax(root->right);
    }

    void insert(Node *&root, int data){
        if(root == NULL){
            root = new Node(); //alloc some memory
            root->info = data; //put the 'data' value in the tree
            root->left = NULL; //the left pointer to NULL
            root->right = NULL; // the right pointer to NULL
        }
        else{
            if(data < root->info) //if 'data' tree is less than 'info' of this Node:
                insert(root->left, data); //it is inserted in the left pointer(newNode)
            else //if 'data' tree is greater or equal than 'info' of this Node:
                insert(root->right, data);//it's inserted in the right pointer(newNode)

        }
    }

    bool search(Node *&root, int data){
        if(root == NULL)//if the Node is empty, it is not there.
            return false;
        else if(root->info == data)//if the 'info' is equal to 'data', it was found.
            return true;
        else if(data < root->info)//if 'data' < 'info', it goes to left side of tree
            return search(root->left, data);
        else                // if 'data' >= 'info', it goes to right side of tree  
            return search(root->right, data);
    }

    Node *remove(Node *root, int data){
        if(root == NULL){
            cout<<"Number not in the tree!"<<endl;
            return root;
        }
        else if(data < root->info) 
            root->left = remove(root->left, data);
        else if(data > root->info)
            root->right = remove(root->right, data);
        else{//found it, now it will be deleted
            if(root->left == NULL && root->right == NULL){//Case 1: No child
                delete root;
                root = NULL;
            }
            //Case 2: 1 child
            else if(root->left == NULL){
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL){
                Node *temp = root;
                root = root->left;
                delete temp;
            }

            else{ //Case 3: 2 children
                Node *temp = findMin(root->right);
                root->info = temp->info;
                root->right = remove(root->right, temp->info);
            }
        }
        return root;
    }
    //Left-Recursion-Right
    void inorder(Node *root){
        if(root != NULL){
            inorder(root->left);
            cout << root->info<<" ";
            inorder(root->right);
        }
    }
    //Recursion-Left-Right
    void preorder(Node *root){
        if(root != NULL){
            cout << root->info<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    //Left-Right-Recursion
    void postorder(Node *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout << root->info<<" ";
        }
    }
     

};

#endif // BST_H_INCLUDED
