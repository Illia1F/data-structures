#ifndef bst_h
#define bst_h
#include <iostream>

enum{Not_found = 0};
namespace bst{
    struct BST
    {
        int key;
        BST* _left;
        BST* _right;
        BST(int key, BST* _left = NULL, BST* _right = NULL)
        : key(key), _left(_left), _right(_right) {}
    };

    int Insert(int, BST*);
    int Find(int, BST*);
    void Delete(int, BST*);
    int FindMin(BST*);
}

#endif
