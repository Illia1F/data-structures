#ifndef library_h
#define library_h
#include <iostream>

struct AVL
{
    int data;
    unsigned char height;
    AVL* left;
    AVL* right;
    AVL(int data)
    : data(data), left(nullptr), right(nullptr), height(1) {}
    ~AVL()
    {
        delete left;
        delete right;
    }
    /// function is returning height of node
    friend unsigned char Height(AVL* node)
    {
        return (node)?(node->height):(0);
    }
    /// function is calculating the height difference of subtrees
    friend int balanceFactor(AVL* node)
    {
        return Height(node->right)-Height(node->left);
    }
    /// function is repairing the height of node
    friend void fixHeight(AVL* node)
    {
        unsigned char hl = Height(node->left);
        unsigned char hr = Height(node->right);
        node->height = ((hl>hr)?(hl):(hr)) + 1;
    }
    /// Rotating to right
    friend AVL* rotateRight(AVL* node);
    /// Rotating to left
    friend AVL* rotateLeft(AVL* node);
    /// Balancing of node
    friend AVL* Balance(AVL* node);
    /// the difficult of performing above functions is O(1)
    friend AVL* Insert(AVL* node, int data);
};

#endif // library_h
