#include "hashTable.h"
#include <iostream>
using namespace std;

int main()
{
    // create the hash table with a size of 5
    HashTable t(5);
    // insert to the hash table 30 elements
    for(int i=0; i<30; i++)
        t.Insert(i+1);
    // and try to delete some elements
    t.Delete(2);
    t.Delete(12);
    // and then find some of them
    cout << t.Find(22) << endl;

    return 0;
}
