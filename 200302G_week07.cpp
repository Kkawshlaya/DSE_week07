#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
// struct for create new node for store values
struct node* Createnode(int value){
    node* num = new node();
    num -> key = value;
    num -> left = NULL;
    num -> right = NULL;
    return num;
}

// struct for minimum value
struct node* min_value(struct node* node){
    struct node* current = node;
    while (current->left != NULL){
        current = current -> left;
    }
    return current;
}    
    
// Inorder traversal
void traverseInOrder(struct node *root) {
   // check if the node is empty
   if(root == NULL){
       return;
   }
    else {
        traverseInOrder(root -> left);// traverse to left node
        cout << root -> key << " ";
        traverseInOrder(root -> right);// traverse to right node
    }
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
    // checkk if node is empty
    if (node == NULL){
        return Createnode(key);
    }
    else if (key < node -> key){
        node -> left = insertNode(node -> left, key);// insert to left node
    }
    else {
        node -> right = insertNode(node->right,key);// inset to right node
    }
    return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int data) {
    if (root ==NULL){
        return root;
    }
    if (data < root -> key){
        root -> left = deleteNode(root->left,data);
    }
    else if (data > root -> key){
        root -> right = deleteNode(root->right,data);
    
    }
    else{
        //check if child is empty
        if (root -> left == NULL and root -> right == NULL){
            return NULL;
        }
        
        //check right child
        else if (root -> left == NULL){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        
        //check left child
        else if (root -> right == NULL){
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        
        
        else{
            struct node* temp = min_value(root->right);
            root -> key = temp -> key;
            root -> right = deleteNode(root->right, temp -> key);
        }
 
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}