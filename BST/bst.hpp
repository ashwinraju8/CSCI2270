

// Node: node struct that will be stored in the BST
//   BST
struct Node
{
    int key;
    Node* left;
    Node* right;
};

// class for storing and manipulating BST
class BST{
    private:
        Node* root;
    public:
        BST(); // constructor
        ~BST(); // destructor
        void insertNode(int value);
        Node* search(int value);
        void display();
};
