#include "BSTree.h"

Node* BSTree::insert(Node *r, char ch)
{
    if(r == nullptr)
        return new Node(ch);
    
    if(r->value < ch)
        r->right = insert(r->right,ch);
    else if (r->value > ch)
        r->left =  insert(r->left ,ch);
    else
        return r;
    
    return r;
}


void BSTree::Display(Node* r, const std::string& Branches, bool isLeaf)
{
    std::string blank = "     ";
    std::string line = { char(954) ,' ' , ' ', ' ', ' ' }; //│
    std::string upp = { char(969), char(973),char(973) ,char(973) };//╔─── 
    std::string down = { char(968), char(973),char(973) ,char(973) }; //└─── 
    r->right;
    if (r != nullptr)
    {
        
        if(r->right != nullptr)
            Display(r->right, Branches + (!isLeaf ? line : blank), true);

        std::cout << Branches;
        std::cout << (isLeaf ? upp : down);
        if (CurrCursorPos == r)
            std::cout << "[(" << r->value << ")]\n";
        else
            std::cout << "[" << r->value << "]\n";

        if(r->left != nullptr)
            Display(r->left, Branches + (isLeaf ? line : blank), false);
    }
}


void BSTree::MakeTree(std::string file)
{
    std::fstream fin(file);

    if(fin.is_open())
    {
        char c;
        while(!fin.eof())
        {
            fin.get(c);
            Root = insert(Root,c);
        }
    }
    else
        std::cout << "Coudn't open File !\n";
}


void BSTree::Show()
{
    Display(Root);
}