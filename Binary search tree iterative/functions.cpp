#include "BSTree.h"
#include <iostream>

BST::~BST()
{
	_root = DeleteAll(_root);
	_size = 0;
}

void BST::Clear()
{
	_root = DeleteAll(_root);
	_size = 0;
}

int BST::getSize()const
{
	return _size;
}

bool BST::Add(int key)
{
	if (_root == NULL) {
		_root = new BST_Node(key);
	}
	else
	{
		// find the place for insertion
		BST_Node* prev = NULL;
		BST_Node* temp = _root;
		while (temp != NULL && temp->key != key) {
			prev = temp;
			if (temp->key > key)
				temp = temp->_left;
			else if (temp->key < key)
				temp = temp->_right;
		}

		// if we found the same key then return false
		if (temp != NULL && temp->key == key)
			return false;

		// we found the need for us place, insert the key
		temp = new BST_Node(key);
		if (prev->key > temp->key)
			prev->_left = temp;
		else prev->_right = temp;
	}
	_size++;
	return true;
}

int BST::Find(int key)const
{
	// find the key
	BST_Node* temp = _root;
	while (temp != NULL && temp->key != key) {
		if (temp->key < key)
			temp = temp->_right;
		else if (temp->key > key)
			temp = temp->_left;
	}

	// if it is null then return NOT_FOUND, in other case return the found key
	return temp ? temp->key : Not_found;
}

int BST::Delete(int key)
{
	BST_Node * prev = NULL;
	BST_Node* temp = _root;

	// here we find the element for delete
	while (temp != NULL && temp->key != key) {
		prev = temp;
		if (temp->key < key)
			temp = temp->_right;
		else
			temp = temp->_left;
	}
	if (temp != NULL) {
		// we found the element which gets ready to be deleted
		// Case 1: when we have to delete our root
		if (temp == _root) {
			// Case 1: No child
			if (_root->_right == NULL && _root->_left == NULL) {
				delete _root;
				_root = NULL;
			}
			// Case 2: A right child
			else if (_root->_right != NULL && _root->_left == NULL)
			{
				BST_Node* del = _root;
				_root = _root->_right;
				delete del;
			}
			// Case 3: A left child
			else if (_root->_right == NULL && _root->_left != NULL)
			{
				BST_Node* del = _root;
				_root = _root->_left;
				delete del;
			}
			// Case 4: Two children
			else if (_root->_right != NULL && _root->_left != NULL)
			{
				int n = FindMin(_root->_right);
				Delete(n);
				BST_Node* minKey = new BST_Node(n, _root->_right, _root->_left);
				delete _root;
				_root = minKey;
			}
		}
		else
		// Case 2: when we have to delete other element
		{
			// Case 1: No child
			if (temp->_right == NULL && temp->_left == NULL) {
				if (prev->key > temp->key)
					prev->_left = NULL;
				else prev->_right = NULL;
				delete temp;
			}
			// Case 2: A right child
			else if (temp->_right != NULL && temp->_left == NULL)
			{
				if (prev->key > temp->key)
					prev->_left = temp->_right;
				else prev->_right = temp->_right;
				delete temp;
			}
			// Case 3: A left child
			else if (temp->_right == NULL && temp->_left != NULL)
			{
				if (prev->key > temp->key)
					prev->_left = temp->_left;
				else prev->_right = temp->_left;
				delete temp;
			}
			// Case 4: Two children
			else if (temp->_right != NULL && temp->_left != NULL)
			{
				int n = FindMin(temp->_right);
				Delete(n);
				BST_Node* minKey = new BST_Node(n, temp->_right, temp->_left);
				if (prev->key > temp->key)
					prev->_left = minKey;
				else prev->_right = minKey;
				delete temp;
			}
		}
	}
	else return Not_found;
	_size--;

	return key;
}

int BST::FindMin()
{
    return FindMin(_root);
}
