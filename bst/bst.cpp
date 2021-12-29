#include <iostream>
#include "bst.hpp"

/*//////////////////////////////////////////
helper functions
//////////////////////////////////////////*/

void removeSubTree(Node* node) // recursively delete all nodes from a subtree with root "node"
{
  if(node != NULL)
  {
    if(node->left != NULL)
    {
      removeSubTree(node->left);
    }
    if(node->right != NULL)
    {
      removeSubTree(node->right);
    }
    delete node;
  }
}

// recursively search the tree starting at node
Node* searchRecursive(Node* node, int value)
{
  if(node != NULL)
  {
    if(value == node->key) 
    {
      return node;
    }
    else if(value < node->key)
    {
      return searchRecursive(node->left, value);
    }
    else
    {
      return searchRecursive(node->right, value);
    }
  }
  else
  {
    return NULL;
  }
}

void printRecursive(Node* node)
{
  if(node->left != NULL)
  {
    printRecursive(node->left);
  }
  std::cout << node->key << std::endl; 
  if(node->right != NULL)
  {
    printRecursive(node->right);
  }
}

/*//////////////////////////////////////////
class functions
//////////////////////////////////////////*/
BST::BST() // constructor
{
    root = NULL;
}

BST::~BST() // destructor
{
    removeSubTree(root); // call helper function
}

/*
 * Purpose: Add a new node to tree
based on value
 * @param value value of input key
 * @return none
 */
void BST::insertNode(int value)
{
    Node* newNode = new Node; // allocate space for new node
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;

    Node* tmp = root;
    Node* parent = tmp;
    while(tmp != NULL) // traverse tree to determine parent of new node
    {
        parent = tmp;
        if(value < tmp->key)
        {
        tmp = tmp->left;
        }
        else
        {
        tmp = tmp->right;
        }
    }

    // place new node into proper location
    if(parent == NULL)
    {
        root = newNode;
    }
    else if(value < parent->key)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

/*
 * Purpose: Search the network for the specified key value and return a pointer to that node
 * @param value value of the key to look for in network
 * @return pointer to node of key value
 */
Node* BST::search(int value)
{
    Node* searchNode = searchRecursive(root, value); // call helper function
    return searchNode;
}

void BST::display()
{
    if(root != NULL)
    {
        printRecursive(root);
    }
    else
    {
        std::cout << "Tree is Empty" << std::endl;
    }
}




