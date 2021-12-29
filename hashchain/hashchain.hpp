#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

class hashchain
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Node* *table;
    int numOfcolision =0;
    Node* createNode(int key, Node* next)
    {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = next;
        return newNode;
    }
    
public:
    hashchain(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    Node* searchItem(int key);
};

#endif
