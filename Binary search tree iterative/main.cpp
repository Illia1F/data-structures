#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
	BST t;
	t.Add(8);
	t.Add(2);
	t.Add(4);
	t.Add(9);

	cout << t.getSize() << endl;

	t.Delete(4);
	t.Delete(9);
	t.Delete(8);

	cout << t.getSize() << endl;

	cout << t.Find(4) << " " << t.Find(9) << " " << t.Find(2) << endl;

	return 0;
}
