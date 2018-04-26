#ifndef bst_h
#define bst_h
#include <iostream>

enum { Not_found = -1};

class BST
{
	struct BST_Node
	{
		int key;
		BST_Node* _right;
		BST_Node* _left;
		BST_Node(int key, BST_Node* _right = NULL, BST_Node* _left = NULL)
			: key(key), _right(_right), _left(_left) {}
	};
	BST_Node* _root;
	unsigned int _size;
	BST_Node* DeleteAll(BST_Node* _pointer)
	{
		if (_pointer != NULL) {
			DeleteAll(_pointer->_right);
			DeleteAll(_pointer->_left);

			delete _pointer;
			_pointer = NULL;
		}

		return _pointer;
	}
	int FindMin(BST_Node* _p)
    {
        while (_p != NULL && _p->_left != NULL)
            _p = _p->_left;

        return _p ? _p->key : Not_found;
    }
public:
	BST() : _root(NULL), _size(0)
	{}
	~BST();
	int getSize()const;
	bool Add(int);
	int Find(int)const;
	int Delete(int);
    int FindMin();
	void Clear();
};

#endif
