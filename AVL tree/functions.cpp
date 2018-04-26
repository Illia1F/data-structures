#include "library.h"

AVL* rotateRight(AVL* node)
{
    AVL* node2 = node->left;
    node->left = node2->right;
    node2->right = node;
    fixHeight(node);
    fixHeight(node2);
    return node2;
}

AVL* rotateLeft(AVL* node)
{
    AVL* node2 = node->right;
    node->right = node2->left;
    node2->left = node;
    fixHeight(node);
    fixHeight(node2);
    return node2;
}

AVL* Balance(AVL* node)
{
    fixHeight(node);
    if(balanceFactor(node) == 2){
        if(balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    } else if(balanceFactor(node) == -2)
    {
        if(balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

AVL* Insert(AVL* node, int data)
{
     if(!node) return new AVL(data);
     if(data < node->data)
            node->left = Insert(node->left, data);
     else node->right = Insert(node->right, data);
     return Balance(node);
}





