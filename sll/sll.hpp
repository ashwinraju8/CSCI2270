#pragma once
#include <iostream>

// Node: node struct that will be stored in the LL
//   linked-list
struct Node{
    int key;
    Node* next;
};

// class for storing and manipulating linked-list
class sll{
    private:
        // pointer to head of linked-list
        Node* head;
    public:
        sll(); // constructor
        ~sll(); // destructor
        void insertNode(int value); 
        Node* search(int value);
        void display();
};