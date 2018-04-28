#include "BSTree.h"
#include "hashTable.h"
#include <iostream>
using namespace std;

int main()
{
    HashTable t(5);
    for(int i=0; i<30; i++)
        t.Insert(i+1);

    t.Delete(2);
    t.Delete(12);
    cout << t.Find(22) << endl;

    return 0;
}
