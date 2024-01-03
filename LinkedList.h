#include <iostream>

class Node {
public:
    int value;  //data contained in node
    Node* next; //pointer to the next node (address to next node), initially set to nullptr

    Node(int value){        //constructor takes an data vale which is assigned to node
        this->value = value;    //takes int 'value' to initialise node
        this->next = nullptr;   //sets address of next node to nullptr
    }
};

class LinkedList {
public:
    Node* head; //pointer to the first node in the list
    Node* tail; //pointer to the last node in the list (intially set to nullptr indicating empty list)
    int size;   //keeps track of size of list

    LinkedList(){       //constructor which initilises a new instance of linked list with no nodes
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insert(int value){   //inserts a new node with given value at the end of the linked list
        this->size++;//increments size
        if (head == nullptr){   //if the list is empty, it creates a new node that sets both the head and tail to this new node
            head = new Node(value); 
            tail = head;
            return;
        }
        //if list is not empty it appends a new node to the end and updates tail
        this->tail->next = new Node(value); //Creates a new node on the heap, this->tail is a pointer to the current last node in the linked list, this->tail->next is the pointer in the last node that should point to the next node in the list
        //after adding the new node to the end of the list, we need to update the tail pointer of the linked list to point to this new node, as it is the last node in the list
        this->tail = this->tail->next; //'this->tail->next is the new node, so this line sets this->tail to the new node.
        return;
    }

void remove(int value){
    this->size--;   // Initially decrements the size of the linked list assuming a node will be removed.

    Node* prev = nullptr;   // 'prev' will hold the pointer to the node just before the current node in the loop.

    // Begin looping through the list starting from the head.
    for (auto node = this->head; node != nullptr; node = node->next){
        // Check if the current node's value matches the value to be removed.
        if (node->value == value){
            // Case: The node to be removed is the tail node.
            if (node == tail){
                // Set the next pointer of the node before the tail to nullptr, effectively removing the last node.
                prev->next = nullptr;
                // Update the tail pointer to point to the new last node.
                tail = prev;
                // Delete the node to free up memory.
                delete node;
                // Exit the function as the node is removed.
                return;
            }

            // Case: The node to be removed is the head node.
            if (node == head){
                // Update the head pointer to point to the next node in the list.
                head = node->next;
                // Delete the node to free up memory.
                delete node;
                // Exit the function as the node is removed.
                return;
            }

            // Case: The node to be removed is neither the head nor the tail.
            // Link the previous node to the next node, skipping over the current node.
            prev->next = node->next;
            // Delete the node to free up memory.
            delete node;
            // Exit the function as the node is removed.
            return;
        }
        // Update 'prev' to point to the current node before moving to the next node.
        prev = node;
    }

    // If the loop completes without removing a node, increment the size back.
    this->size++;
    // Exit the function.
    return;
}

};