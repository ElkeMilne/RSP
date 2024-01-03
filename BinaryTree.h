#include <iostream>
using namespace std;

// Node structure for BinaryTree
struct Node {
    int value;      // The value/data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor for a node
    Node(int value){
        this->value = value;
        left = nullptr;   // Initializing left child to nullptr
        right = nullptr;  // Initializing right child to nullptr
    }
};

// BinaryTree class
class BinaryTree {
public:
    Node* head;  // Pointer to the root node of the tree

    // Constructor for BinaryTree
    BinaryTree(){
        this->head = nullptr;  // Initializing the head/root to nullptr (empty tree)
    }

    // Method to insert a new value into the tree
    void insert(int value){
        Node* newNode = new Node(value);  // Creating a new node with the given value

        // Case: If the tree is empty, set the new node as the head/root
        if (this->head == nullptr){
            this->head = newNode;
            return;
        }

        // Iteratively find the correct position for the new node
        Node* current = this->head;
        while (true){
            // If current node value is less than or equal to new value, go left
            if (current->value <= value){
                // If left child is empty, insert the new node here
                if (current->left == nullptr){
                    current->left = newNode;
                    return;
                }
                // Move to the left child
                current = current->left;
                continue;
            } else {
                // If right child is empty, insert the new node here
                if (current->right == nullptr){
                    current->right = newNode;
                    return;
                }
                // Move to the right child
                current = current->right;
                continue;
            }
        }
        return;
    }

    // Method to remove a node with a given value
    void remove(int value){
        // Case: If the tree is empty, nothing to remove
        if (this->head == nullptr){
            return;
        }

        // Special case: If the root/head node is the one to be removed
        if (this->head->value == value){
            // If left child is present, move it to head and merge right subtree
            if (this->head->left != nullptr){
                Node* temp = this->head->right;
                this->head = this->head->left;
                if (temp != nullptr){
                    this->mergeBinaryTrees(temp);
                }
                return;
            } else if (this->head->left != nullptr){
                // If only right child is present, move it to head
                this->head = this->head->right;
            } else{
                // If no children, set head to nullptr (empty tree)
                this->head = nullptr;
                return;
            }
        }

        // Searching for the node to remove
        Node* current = this->head;
        Node* prev = nullptr;
        while (true){
            // If current is nullptr, value not found, exit the loop
            if (current == nullptr){
                return;
            }

            // If the value is found in current node
            if (current->value == value){
                // Remove the current node and reattach its children
                if (prev->left == current){
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }

                // Merge the children of the removed node into the tree
                this->mergeBinaryTrees(current->left);
                this->mergeBinaryTrees(current->right);

                break;  // Exit the loop
            }

            // Move to the next node in the tree
            if (current->value <= value){
                prev = current;
                current = current->left;
                continue;
            } else {
                prev = current;
                current = current->right;
                continue;
            }
        }
        return;
    }

    // Method to merge two binary trees
    void mergeBinaryTrees(Node* node){
        // If node is not nullptr, perform merge
        if (node != nullptr){
            // Insert the node's value into the tree
            this->insert(node->value);
            // Recursively merge left and right subtrees
            if (node->left != nullptr){
                mergeBinaryTrees(node->left);
            }

            if (node->right != nullptr){
                mergeBinaryTrees(node->right);
            }
        }
        return;
    }

    // Method to print the tree
    void printTree(){
        // If tree is not empty, print it
        if (this->head != nullptr){
            printTree(this->head->left, 1);
            cout << endl << this->head->value << endl;
            printTree(this->head->right, 1);
            cout << endl;
        }
    }

    // Helper method to print the tree recursively
    void printTree(Node* node, int counter){
        if (node != nullptr){
            // Recursively print left subtree
            printTree(node->left, counter + 1);
            // Print current node
            cout << counter << ":" << node->value << " ";
            // Recursively print right subtree
            printTree(node->right, counter + 1);
        }
    }

};
