#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	int val;
	char c_val;
	LinkedList<int> L;
	LinkedList<char> Opp;
	LinkedList<int> Repeat;
	LinkedList<int> Res;
	cin >> val;
	while (val != -1)
	{
		L.InsertEnd(val);
		cin >> val;
	}
	cin >> c_val;
	while (c_val != '$')
	{
		Opp.InsertEnd(c_val);
		cin >> c_val;
	}
	cin >> val;
	while (val != -1)
	{
		Repeat.InsertEnd(val);
		cin >> val;
	}
	bool b = L.ApplyRepeatedOperation(Opp, Repeat, Res);
	if (b)
	{
		Res.PrintList();
	}
	else
	{
		cout << "Error" << endl;
		Res.PrintList();
	}
	return 0;
}

