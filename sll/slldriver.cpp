#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "sll.hpp"

using namespace std;

int main()
{
    for(int dataSet = 0; dataSet < 2; dataSet++) // for loop to iterate through both data sets
    {
        // instantiating linked list class
        sll LL;  

///////////////////////////////////////////////////////////////
/*
IMPORTING DATA INTO C++
*/
///////////////////////////////////////////////////////////////

        // initializing file names        
        string inputName;
        string outputName;

        // instantiating variables
        int testData[10000];
        float insert[100], search[100];
        string line;
        int count = 0;

        // setting filenames based on which data set
        if(dataSet == 0)
        {
            inputName = "dataSetA-updated.csv";
            outputName = "insert_search_ performance_linked_list_dataSetA.csv";
        }
        else
        {
            inputName = "dataSetB-updated.csv";
            outputName = "insert_search_ performance_linked_list_dataSetB.csv";
        }

        ifstream in_file(inputName); // declare input file
        ofstream out_file(outputName); // declare output file

        // using getline() to read in csv data into testData[]
        if(in_file.is_open())
        {
            while(in_file.good()) 
            {
                getline(in_file, line,',');
                int putInArr = stoi(line);
                testData[count] = putInArr;
                count++;
            }
            in_file.close();
        }
        else
        {
            cout << "File not open" << endl;
        }
///////////////////////////////////////////////////////////////
        /*
        INSERTING AND SEARCHING EXPERIMENT
        */
///////////////////////////////////////////////////////////////
        srand((unsigned)time(0));
        // helper variable initialization
        int first = 0;
        int last = 0;
        int randomIDX[100];
        int floor = 0;
        int ceiling = 99;
        for(int k = 0; k < 100; k++) // outer for loop to iterate every 100 inserts/searches
        {
            /*
            INSERT
            */
            auto startI = chrono::steady_clock::now(); // start timer for insert
            last = first + 100;                        // set the data points for the nested for loop to traverse 
            for(int i = first; i < last; i++)
            {
                LL.insertNode(testData[i]);            // insert the indexed element into linked list
            }
            first = last;
            auto endI = chrono::steady_clock::now(); // end timer for insert

            // save average time taken (nano-seconds) 1 insert 
            insert[k] = (chrono::duration_cast<chrono::nanoseconds>(endI - startI).count())/100; 

            /*
            search
            */

            // initialize variables 
            Node* searchResult;
            int range = (ceiling - floor) + 1;
            
            // create array of 100 random indices
            for(int j = 0; j < 100; j++)
            {
                randomIDX[j] = floor + rand() % range;
            }

            auto startS = chrono::steady_clock::now(); // start timer for search
            for(int i = 0; i < 100; i++)
            {
                searchResult = LL.search(testData[randomIDX[i]]); // search for indexed element
            }
            auto endS = chrono::steady_clock::now(); // end timer for insert

            // save average time taken (nano-seconds) 1 search
            search[k] = (chrono::duration_cast<chrono::nanoseconds>(endS - startS).count())/100;

            ceiling = ceiling + 100;
        }

///////////////////////////////////////////////////////////////
        /*
        SAVING RESULT DATA TO OUTPT FILE
        */
///////////////////////////////////////////////////////////////


        if(out_file.is_open())
        {
                //save insert times into 1st row
                for(int i = 0; i < 100; i++)
                {
                    out_file << insert[i] << ", ";
                }
                out_file << endl;

                // save search times into 2nd row
                for(int i = 0; i < 100; i++)
                {
                    out_file << search[i] << ", ";
                }
        }
        out_file.close();
    }
}