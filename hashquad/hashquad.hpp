#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;


class hashquad
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer declaration of array
    float *table;
    int numOfcolision =0;
    public:
        hashquad(int bsize);  // Constructor

        // inserts a key into hash table
        bool insertItem(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();
        int getNumOfCollision();

        int searchItem(int key);
};

#endif