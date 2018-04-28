#include "BSTree.h"
#include <iostream>

int bst::Insert(int key, BST* _curr_p)
{
    if(key <= 0)
        return Not_found;

    BST* _prev_p = NULL;
    while(_curr_p){
        _prev_p = _curr_p;
        if(_curr_p->key > key)
            _curr_p = _curr_p->_left;
        else if(_curr_p->key < key)
            _curr_p = _curr_p->_right;
        else break;
    }
    if(_curr_p != NULL)
        return Not_found;

    if(_prev_p->key > key)
        _prev_p->_left = new BST(key);
    else _prev_p->_right = new BST(key);

    return key;
}

int bst::Find(int key, BST* _curr_p)
{
    while(_curr_p != NULL && _curr_p->key != key){
        if(_curr_p->key > key)
            _curr_p = _curr_p->_left;
        else _curr_p = _curr_p->_right;
    }

    return _curr_p && _curr_p->key == key ? _curr_p->key : Not_found;
}

void bst::Delete(int key, BST* _curr_p)
{
    BST* _prev_p = NULL;
    while(_curr_p != NULL && _curr_p->key != key){
        _prev_p = _curr_p;
        if(_curr_p->key > key)
            _curr_p = _curr_p->_left;
        else _curr_p = _curr_p->_right;
    }
    BST* temp = NULL;
    // Case 1: No child
    // temp = NULL
    // Case 2: A left child
    if(_curr_p->_left && !_curr_p->_right){
        temp = _curr_p->_left;
    }
    // Case 3: A right child
    else if(!_curr_p->_left && _curr_p->_right){
        temp = _curr_p->_right;
    }
    // Case 4: Two children
    else if(_curr_p->_left && _curr_p->_right)
    {
        int n = bst::FindMin(_curr_p->_right);
        bst::Delete(n, _curr_p);
        _curr_p->key = n;
        return;
    }

    if(_prev_p->key > key)
            _prev_p->_left = temp;
        else _prev_p->_right = temp;
    delete _curr_p;
}

int bst::FindMin(BST* _curr_p)
{
    bst::BST* temp = _curr_p;
    while(temp){
        _curr_p = temp;
        temp = temp->_left;
    }
    return _curr_p->key;
}
