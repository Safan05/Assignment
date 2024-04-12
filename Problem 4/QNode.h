
#ifndef _NODE
#define _NODE
template < typename T>
class QNode
{
private:
	T item; // A data item
	QNode<T>* next; // Pointer to next node
public:
	QNode();
	QNode(const T& r_Item);
	QNode(const T& r_Item, QNode<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(QNode<T>* nextNodePtr);
	T getItem() const;
	QNode<T>* getNext() const;
}; // end Node
#endif

template < typename T>
QNode<T>::QNode()
{
	next = nullptr;
}

template < typename T>
QNode<T>::QNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
QNode<T>::QNode(const T& r_Item, QNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void QNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void QNode<T>::setNext(QNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T QNode<T>::getItem() const
{
	return item;
}

template < typename T>
QNode<T>* QNode<T>::getNext() const
{
	return next;
}