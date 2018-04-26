#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    int tab[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    ofstream file("mountOfElements.txt");
    ofstream file2("Heights.txt");
    for(int i=0; i<10; i++){
        AVL* root = nullptr;
        file << tab[i] << endl;
        for(int j=0; j<tab[i]; j++){
            root = Insert(root, j);
        }
        file2 << (int)Height(root) << endl;
        delete root;
    }

    file2.close();
    file.close();


    return 0;
}
