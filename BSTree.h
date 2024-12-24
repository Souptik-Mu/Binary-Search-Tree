
#include <iostream>
#include <fstream>
#include <String>

class Node {
    public:
        char value;
        Node* left;
        Node* right;

        Node(char c)
        {
            this->value = c;
            left = nullptr;
            right = nullptr;
        }
};

class BSTree 
{

    private :
        Node* Root = nullptr;
        Node* CurrCursorPos = nullptr;

        Node* insert(Node* root , char c);
        void Display(Node* , const std::string& = "", bool = false);
    public :
        void Show();
        void MakeTree(std::string file);
        void select(){
            CurrCursorPos = Root;
        }

};