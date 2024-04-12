#include <iostream>
#include "LinkedQueue.h"
#include "Node.h"
#include "Tree.h"
using namespace std;
int main() {
	int n;
	int element;
	cin >> n;
	LinkedQueue<Node*> input;
	LinkedQueue<Node*> aux;
	for (int i = 0; i < n; i++) {
		cin >> element;
		Node *n=new Node(element);
		input.enqueue(n);
	}
	char x;
	int p, c;
	Node *r;
	input.peek(r);
	Tree ce(r);
	for (int i = 1; i < n; i++) {
		cin >> x >> p >> c;
		Node *pa=NULL,*ch=NULL;
		for (int j = 0; j <= c; j++) {
			Node *aux1;
			input.dequeue(aux1);
			aux.enqueue(aux1);
			if (j == p)
				pa = aux1;
			if (j == c)
				ch = aux1;
		}
		Node* aux2;
		while (!input.isEmpty()) {
			input.dequeue(aux2);
			aux.enqueue(aux2);
		}
		while (!aux.isEmpty()) {
			aux.dequeue(aux2);
			input.enqueue(aux2);
		}
		if (x == 'L') {
			pa->setleft(ch);
		}
		else if (x == 'R') {
			pa->setright(ch);
		}
	}
	ce.ordered_family();
	ce.PrintBreadthFirst();
	return 0;
}