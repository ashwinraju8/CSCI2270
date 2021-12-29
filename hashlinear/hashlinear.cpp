#include <iostream>
#include "hashlinear.hpp"

/*
 * Purpose: Constructor to initialize all indices to -1
 * @param bsize size of hashtable
 * @return none
 */
hashlinear::hashlinear(int bsize)
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
unsigned int hashlinear::hashFunction(int key)
{
    unsigned int sum = key % tableSize;
    return sum;
}

/*
 * Purpose: Add a new node to the head of appropriate index and iterate if collision occurs
 * @param key value of input key
 * @return none
 */
bool hashlinear::insertItem(int key)
{
    bool collision = false; // bool to ensure only 1 collision occurs
    int idx; 
    for(int i = 0; i < tableSize; i++)
    {
        idx = hashFunction(key+i);
        if(table[idx] == -1)
        {
            table[idx] = key;
            return true;
        }
        else
        {
            if(collision == false) // only increment numCollisions 1 time if collisison occurs
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

void hashlinear::printTable()
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

int hashlinear::getNumOfCollision()
{
    return numOfcolision;
}

/*
 * Purpose: Search the network for the specified key value and return the index to that key
 * @param value value of the key to look for in table
 * @return index of key value, or -1 if not found
 */
int hashlinear::searchItem(int key)
{

    int idx = hashFunction(key);
    if(table[idx] == key)
    {
        return idx;
    }
    else
    {
        numOfcolision++; // only increment numCollisions 1 time
        int tmp = idx;
        for(int i = idx; i < tableSize; i++)
        {
            if(table[tmp] == key)
            {
                return tmp;
            }
            else
            {
                if(tmp == tableSize-1) // go to beginning of table if @ end of table
                {
                    tmp = -1;
                }
                tmp++;
            }
        }
    }
    return -1;
}

