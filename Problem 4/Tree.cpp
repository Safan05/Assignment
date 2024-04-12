#include "Tree.h"
Tree::Tree(Node* r)
{
	root = r;
}

void Tree::rec_destroy_tree(Node*& subRoot)
{
	if (subRoot != nullptr)
	{
		// recursive call on left
		rec_destroy_tree(subRoot->getleft());

		// recursive call on right
		rec_destroy_tree(subRoot->getright());

		delete subRoot;
		subRoot = nullptr; // this line is why we pass subRoot by reference (subRoot = something)
	}
}
void Tree::rec_breadth_first(Node*& sroot,LinkedQueue<int>& print)
{
	if (sroot != NULL) {
		Node* pT = sroot;
		Node* r = NULL, * l = NULL;
		pT = sroot->getleft();
		if (pT != NULL)
			print.enqueue(pT->getdata());
		l = pT;
		pT = sroot->getright();
		if (pT != NULL)
			print.enqueue(pT->getdata());
		r = pT;
		rec_breadth_first(l, print);
		rec_breadth_first(r, print);
	}
}
void Tree::rec_ordered_family(Node*& sroot)
{
	if (sroot != NULL) {
		Node* r = sroot->getright(), * l = sroot->getleft();
		if (r != NULL && l != NULL) {
			if (sroot->getdata() > l->getdata() && sroot->getdata() < r->getdata())
				sroot->setdata(10 * sroot->getdata());
		}
		else if (l == NULL && r != NULL) {
			if (r->getleft() == NULL && r->getright() == NULL) {
				sroot->setright(nullptr);
				delete r;
				r = NULL;
			}
		}
		else if (r == NULL && l != NULL) {
			if (l->getleft() == NULL && l->getright() == NULL) {
				sroot->setleft(nullptr);
				delete l;
				l = NULL;
			}
		}
		rec_ordered_family(l);
		rec_ordered_family(r);
	}
}
void Tree::destroy_tree() // not const
{
	// not const because rec_destroy_tree takes the root by reference, so may change it
	rec_destroy_tree(root);
}
void Tree::PrintBreadthFirst() {
	LinkedQueue<int> print;
	print.enqueue(root->getdata());
	rec_breadth_first(root,print);
	int K;
	while (print.dequeue(K))
	{
		cout << K;
		if (!print.isEmpty())
			cout << " ";
	}
	cout << endl;
}
void Tree::ordered_family()
{
	rec_ordered_family(root);
}
Tree::~Tree()
{
	destroy_tree();
}
