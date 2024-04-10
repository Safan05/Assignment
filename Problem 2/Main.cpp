#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	int val;
	LinkedList<int> L;
	cin >> val;
	while (val != -1)
	{
		L.InsertEnd(val);
		cin >> val;
	}
	L.RearrangeLL();
	L.PrintList();
	return 0;
}
