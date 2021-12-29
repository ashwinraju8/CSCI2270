#include <iostream>
#include "hashchain.hpp"

/*
 * Purpose: Constructor to initialize all indices to NULL
 * @param bsize size of hashtable
 * @return none
 */
hashchain::hashchain(int bsize)
{
    tableSize = bsize;
    table = new Node*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
    }
}

/*
 * Purpose: Find hash value for given key using the division method
 * @param value value of input key
 * @return hash value
 */
unsigned int hashchain::hashFunction(int key)
{
    unsigned int sum = key % tableSize;
    return sum;
}


/*
 * Purpose: Add a new node to the head of appropriate linked list and iterate if collision occurs
 * @param key value of input key
 * @return none
 */
bool hashchain::insertItem(int key)
{
    int idx = hashFunction(key);
    
    // opted not to use suggested createNode() function
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = NULL;
    

   //Node* newNode = createNode(key, NULL);

    if(table[idx] == NULL)
    {
        table[idx] = newNode;
        return true;
    }
    else
    {
        /*
        Node* duplicate = searchItem(key); // check for duplicate key in table
        if(duplicate != -1)
        {
            cout << "Hash Table cannot store duplicate keys" << endl;
            return;
        }
        */

        // always add new node @ the head
        numOfcolision++; // only increment numCollision 1 time
        Node* tmp = table[idx];
        newNode->next = tmp;
        table[idx] = newNode;
        return true;
    }
    return false;
}

void hashchain::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] != NULL)
        {
            std::cout << "index " << i << ": " << table[i] << std::endl;
        }
        else
        {
            std::cout << "index " << i << ": " << "unused index" << std::endl;
        }
    }
}

int hashchain::getNumOfCollision()
{
    return numOfcolision;
}


/*
 * Purpose: Search the network for the specified key value and return a pointer to that node
 * @param value value of the key to look for in network
 * @return pointer to node of key value, or NULL if not found
 */
Node* hashchain::searchItem(int key)
{
    int idx = hashFunction(key);
    bool collision = false; // bool to ensure only 1 collision is counted 
    if(table[idx] != NULL)
    {
        Node* tmp = table[idx];
        while(tmp != NULL)
        {
            if(tmp->next != NULL && !collision) // collision occurs if indexed linked list has > 1 node 
            {
                numOfcolision++; // numCollisions is only incremented 1 time
                collision = true;
            }

            if(tmp->key == key)
            { 
                return tmp;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
    return NULL;
}