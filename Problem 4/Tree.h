#include <iostream>
#include"Node.h"
#include"LinkedQueue.h"
using namespace std;
class Tree {
private:		// add private functions here
	Node* root;
	static void rec_destroy_tree(Node*& subRoot);
	static void rec_breadth_first(Node*& subRoot, LinkedQueue<int> &print);
	static void rec_ordered_family(Node*& subRoot);
public:			// add public functions here
	Tree(Node *r =nullptr);
	~Tree(void);
	void destroy_tree(); // not const
	void PrintBreadthFirst();
	void ordered_family();
};