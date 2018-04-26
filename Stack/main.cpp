#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> tab;

    if(tab.empty()) { std::cout << "empty\n"; }

    tab.push(1);
    tab.push(2);
    tab.push(3);

    if(!tab.empty()) { std::cout << "not empty\n"; }

    while(!tab.empty()){
        std::cout << tab.top() << " ";
        tab.pop();
    }

    std::cout << std::endl << "size of tab: " << tab.size() << std::endl;

    Stack<int> b(tab);

    if(b.empty()) { std::cout << "empty\n" << std::endl; }


    return 0;
}
