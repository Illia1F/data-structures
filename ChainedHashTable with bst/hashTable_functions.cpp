#include "BSTree.h"
#include "hashTable.h"

HashTable::~HashTable()
{
    hash_table.clear();
    _size = 0;
}

void HashTable::Clear()
{
    hash_table.clear();
    hash_table.resize(_size, NULL);
    _size = 0;
}

int HashTable::getSize()const
{
    return _size;
}

int HashTable::getHashValue(const int& key)const
{
    return key % getSize();
}

// the function which inserts an element to the hash table
void HashTable::Insert(int key)
{
    // hash value
    int hashValue = getHashValue(key);
    if(hash_table.at(hashValue) == NULL)
        hash_table.at(hashValue) = new bst::BST(key);
    else bst::Insert(key, hash_table.at(hashValue));
}

int HashTable::Find(int key)
{
    // hash value
    int hashValue = getHashValue(key);

    return hash_table.at(hashValue) && hash_table.at(hashValue)->key == key
            ? key : bst::Find(key, hash_table.at(hashValue));
}

int HashTable::Delete(int key)
{
    // hash value
    int hashValue = getHashValue(key);

    if(hash_table.at(hashValue) && hash_table.at(hashValue)->key == key){
        bst::BST* temp = hash_table.at(hashValue);
        // Case 1: No child
        if(hash_table.at(hashValue)->_left && hash_table.at(hashValue)->_right){
            delete hash_table.at(hashValue);
            hash_table.at(hashValue) = NULL;
        }
        // Case 2: A left child
        else if(hash_table.at(hashValue)->_left && !hash_table.at(hashValue)->_right){
            hash_table.at(hashValue) = hash_table.at(hashValue)->_left;
            delete temp;
        }
        // Case 3: A right child
        else if(!hash_table.at(hashValue)->_left && hash_table.at(hashValue)->_right){
            hash_table.at(hashValue) = hash_table.at(hashValue)->_right;
            delete temp;
        }
        // Case 4: Two children
        else if(hash_table.at(hashValue)->_left && hash_table.at(hashValue)->_right)
        {
            int n = bst::FindMin(hash_table.at(hashValue)->_right);
            bst::Delete(n, hash_table.at(hashValue));
            hash_table.at(hashValue)->key = n;
        }
    }
    else
    {
        bst::Delete(key, hash_table.at(hashValue));
    }

    return key;
}
