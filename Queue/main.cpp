#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    Queue<int> s;

    if(s.empty()){
        cout << "empty\nInsert new 5 elements\n";
        for(int i=0; i<5; i++)
            s.push(i+1);
    }

    cout << "Front element: " << s.front() << endl;
    cout << "Back element: " << s.back() << endl;

    Queue<int> s2(s);

    cout << "Our queue: ";
    for(int i=0; i<s2.size(); i++){
        cout << s2.front() << " ";
        s2.pop();
    }

    return 0;
}
