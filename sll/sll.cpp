#include "sll.hpp"

sll::sll() // constructor
{
    head = NULL;
}

sll::~sll() // destructor
{
    if(head == NULL)
    {
        return;
    }
    Node* tmp = head;
    while(tmp != NULL)
    {
       Node* bouttaGo = tmp;
       tmp = tmp->next;
       delete bouttaGo;
    }
    head = NULL;
}

/*
 * Purpose: Add a new node to the head of the network
 * @param value value of input key
 * @return none
 */
void sll::insertNode(int value)
{

    Node* newNode = new Node; // allocating space for new node
    newNode->key = value; // initializing new node
    newNode->next = NULL;

    // setting new node as head node
    if(head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
}

/*
 * Purpose: Search the network for the specified key value and return a pointer to that node
 * @param value value of the key to look for in network
 * @return pointer to node of key value, or NULL if not found
 */
Node* sll::search(int value)
{
    Node* tmp = head;
    bool found = false;
    Node* returnNode = NULL;

    while(found == false && tmp != NULL) // traversing through sll
    {
        if(tmp->key == value) // determining if node is desired node
        {
            returnNode = tmp;
            found = true;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return returnNode;
}

void sll::display()
{
    
    if(head == NULL) // if empty
    {
        std::cout << "empty" << std::endl;
    }
    else
    {
        Node* node = head;
        std::cout << node->key;
        while(node->next != NULL) // starting @ head node & traversing till end of sll
        {
            std::cout << " -> " << node->next->key;
            node = node->next;
        }
        std::cout << " -> " << "NULL" << std::endl;
    }
}


