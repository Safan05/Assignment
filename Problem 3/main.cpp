#include "ArrayStack.h"
#include "LinkedQueue.h"
#include <iostream>
using namespace std;
template <typename T>
void PrintQueue(LinkedQueue<T> Q)
{
	T K;
	while (Q.dequeue(K))
	{
		cout << K;
		if (!Q.isEmpty())
			cout << " ";
	}
	cout << endl;
}
template <typename T>
void ReverseMinusOnes(LinkedQueue<T>& Q) {
	LinkedQueue<int> aux;
	int x;
	bool flag=false;
	Q.dequeue(x);
		while (x != -1&&!Q.isEmpty()) {
			aux.enqueue(x);
			Q.dequeue(x);
		}
		while (!Q.isEmpty()) {
			aux.enqueue(x);
			ArrayStack<int> aux2;
			Q.dequeue(x);
			if (x == -1) {
				aux.enqueue(99);
				continue;
			}
			while (x != -1) {
				aux2.push(x);
				Q.dequeue(x);
				if (Q.isEmpty()&&x!=-1) {
					flag = true;
					ArrayStack<int> aux3;
					while (!aux2.isEmpty()) {
						int y;
						aux2.pop(y);
						aux3.push(y);
					}
					while (!aux3.isEmpty()) {
						int y;
						aux3.pop(y);
						aux.enqueue(y);
					}
					break;
				}
			}
			if(flag)
				aux.enqueue(x);
			else {
				while (!aux2.isEmpty()) {
					int y;
					aux2.pop(y);
					aux.enqueue(y);
				}
				if (x == -1&&Q.isEmpty())
					aux.enqueue(x);
			}
		}
		while (!aux.isEmpty()) {
			int z;
			aux.dequeue(z);
			Q.enqueue(z);
		}
}
int main() { 
	// Note: Don't change the main function.
	 int n; 
	 int element; 
	 cin >> n; 
	 LinkedQueue<int> input; 
	 for (int i = 0; i < n; i++) {
	 cin >> element;
	 input.enqueue(element); 
	 }
	 ReverseMinusOnes(input);
	 PrintQueue(input);
	return 0;
}