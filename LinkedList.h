#ifndef _LINKEDLIST
#define _LINKEDLIST
#include <iostream>
#include "Node.h"
using namespace std;
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}
	LinkedList(LinkedList& L) { //copy constructor 
		Node<T>* origin = L.Head;
		if (origin == NULL)
			Head = NULL;	// empty linked list 
		else {
			Head = new Node<T>(); // to create a copy of the head
			Head->setItem(origin->getItem());
			Node<T>* H;
			H = Head;
			origin = origin->getNext();
			while (origin != NULL) {
				Node<T>* n = new Node<T>;
				n->setItem(origin->getItem());
				H->setNext(n);
				H = H->getNext();
				origin = origin->getNext();
			}
		}
	}
	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	bool AddPairs(LinkedList<int>& Pairs_pos, LinkedList<int>& Result) {
		Node<T>* p = Pairs_pos.Head;
		int count = 0;
		Node<T>* z = Head;
		while (z != NULL) {
			count++;
			z = z->getNext();
		}
		if (p != NULL && Head != NULL) {
			while (p != NULL) {
				if (p->getItem() < 0)
					break;
				p = p->getNext();
			}
			p = Pairs_pos.Head;
			while (p->getNext() != NULL) {
				if (p->getItem() > count)
					return false;
				int val = 0;
				for (int _ = 0; _ < 2; _++) {
					Node<T>* z = Head;
					for (int i = 1; i < p->getItem(); i++)
						z = z->getNext();
					val += z->getItem();
					p = p->getNext();
				}
				Result.InsertEnd(val);
				if (p == NULL)
					break;
			}
		}
		return true;
	}
	void PrintList() const
	{
		Node<T>* p = Head;
		while (p)
		{
			cout << p->getItem();
			p = p->getNext();
			if (p)
				cout << " ";
		}
		cout << "NULL\n";
	}
	Node<char>* gethead() {
		return Head;
	}
	bool ApplyRepeatedOperation(LinkedList<char> Opp, LinkedList<int> Repeat, LinkedList<int>& Res) {
		Node<T>* H = Head;
		Node<char>* O = Opp.gethead();
		Node<T>* R = Repeat.Head;
		while (H != NULL) {
			while (R != NULL)
			{
				while (R->getItem() <= 0 && R != NULL)
					R = R->getNext();
				if (O->getItem() != NULL) {
					if (O->getItem() == 'S')
					{
						for (int i = 0; i < R->getItem(); i++) {
							if (H == NULL)
								return false;
							H = H->getNext();
						}
					}
					else {
						while (R->getItem() < 2 && R != NULL)
							R = R->getNext();
						if (O->getItem() == '+') {
							int sum = H->getItem();
							H = H->getNext();
							if (H == NULL)
								return false;
							for (int i = 1; i < R->getItem(); i++) {
								if (H == NULL)
									return false;
								sum = sum + H->getItem();
								H = H->getNext();
							}
							Res.InsertEnd(sum);
						}
						else if (O->getItem() == 'X') {
							int prod = H->getItem();
							H = H->getNext();
							if (H == NULL)
								return false;
							for (int i = 1; i < R->getItem(); i++) {
								if (H == NULL)
									return false;
								prod = prod * H->getItem();
								H = H->getNext();
							}
							Res.InsertEnd(prod);
						}
					}
					O = O->getNext();
				}
				else {
					int sum = H->getItem();
					H = H->getNext();
					if (H == NULL)
						return false;
					for (int i = 1; i < R->getItem(); i++) {
						if (H == NULL)
							return false;
						sum = sum + H->getItem();
						H = H->getNext();
					}
					Res.InsertEnd(sum);
				}
				R = R->getNext();
			}
			if (H != NULL && R == NULL) {
				if (O == NULL) {
					int sum = H->getItem();
					H = H->getNext();
					if (H == NULL)
						return false;
					for (int i = 1; i < 2; i++) {
						if (H == NULL)
							return false;
						sum = sum + H->getItem();
						H = H->getNext();
					}
					Res.InsertEnd(sum);
				}
				else if (H != NULL && O != NULL)
				{
					if (O->getItem() == 'S')
					{
						for (int i = 0; i < 2; i++) {
							if (H == NULL)
								return false;
							H = H->getNext();
						}
					}
					else {
						if (O->getItem() == '+') {
							int sum = H->getItem();
							H = H->getNext();
							if (H == NULL)
								return false;
							for (int i = 1; i < 2; i++) {
								if (H == NULL)
									return false;
								sum = sum + H->getItem();
								H = H->getNext();
							}
							Res.InsertEnd(sum);
						}
						else if (O->getItem() == 'X') {
							int prod = H->getItem();
							H = H->getNext();
							if (H == NULL)
								return false;
							for (int i = 1; i < 2; i++) {
								if (H == NULL)
									return false;
								prod = prod * H->getItem();
								H = H->getNext();
							}
							Res.InsertEnd(prod);
						}
					}
					O = O->getNext();
				}
			}

		}
		return true;
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {
		Node<T>* P = Head;
		if (P == NULL) {
			InsertBeg(data);
			return;
		}
		while (P->getNext() != NULL)
			P = P->getNext();
		Node<T>* Temp = new Node<T>(data);
		P->setNext(Temp);
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value);
	int count_length();
	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst();


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value);

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value);

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();

};

#endif	
