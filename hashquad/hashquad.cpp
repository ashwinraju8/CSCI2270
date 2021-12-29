#include <iostream>
#include "hashquad.hpp"

/*
 * Purpose: Constructor to initialize all indices to -1
 * @param bsize size of hashtable
 * @return none
 */
hashquad::hashquad(int bsize)
{
    tableSize = bsize;
    table = new float[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
}

/*
 * Purpose: Find hash value for given key using the division method
 * @param value value of input key
 * @return hash value
 */
unsigned int hashquad::hashFunction(int key)
{
    unsigned int sum = key % tableSize;
    return sum;
}

/*
 * Purpose: Add a new node to the head of appropriate index and iterate if collision occurs
 * @param key value of input key
 * @return none
 */
bool hashquad::insertItem(int key)
{
    bool collision = false;
    int idx; 
    for(int i = 0; i < tableSize; i++)
    {
        idx = hashFunction(key+(i*i));
        if(table[idx] == -1)
        {
            table[idx] = key;
            return true;
        }
        else
        {

            if(collision == false) // only increment numCollisions 1 time
            {
                /*
                int duplicate = searchItem(key); // check for duplicate key in table
                if(duplicate != -1)
                {
                    cout << "Hash Table cannot store duplicate keys" << endl;
                    return;
                }
                */
                numOfcolision++;
                collision = true;
            }
        }
    }
    return false;
}

void hashquad::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] != -1)
        {
            std::cout << "index " << i << ": " << table[i] << std::endl;
        }
        else
        {
            std::cout << "index " << i << ": " << "unused index" << std::endl;
        }
    }
}

int hashquad::getNumOfCollision()
{
    return numOfcolision;
}

/*
 * Purpose: Search the network for the specified key value and return the index to that key
 * @param value value of the key to look for in table
 * @return index of key value, or -1 if not found
 */
int hashquad::searchItem(int key)
{
    bool collision = false;
    int idx;
    for(int i = 0; i < tableSize; i++)
    {
        idx = hashFunction(key+(i*i));
        if(table[idx] == key)
        {
            return idx;
        }
        else
        {            
            if(collision == false) // only increment numCollisions 1 time
            {
                numOfcolision++;
                collision = true;
            }
        }
    }
    return -1;
}

