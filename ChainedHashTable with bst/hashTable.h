#ifndef hashTable_h
#define hashTable_h
#include "BSTree.h"
#include <iostream>
#include <vector>

class HashTable
{
    std::vector<bst::BST*> hash_table;
    int _size;
public:
    HashTable(int _size = 129) : _size(_size)
    {
        hash_table.resize(_size, NULL);
    }
    ~HashTable();
    void Clear();
    int getSize()const;
    int getHashValue(const int&)const;
    void Insert(int);
    int Find(int);
    int Delete(int);
};

#endif // hashTable_h
