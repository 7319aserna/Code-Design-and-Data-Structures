#include "currentState.h"
#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value

	void display();

	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();
};

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = NULL;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	// Delete ALL OF THE NODES
	while (head != nullptr && head->next != NULL) {
		pop_front();
		//Node *temp = new Node;	// 1. Make a Node
		//temp = head;			// 2. Set the Temp Node to be equal to the Head(first)
		//head = head->next;		// 3. Set the Head to equal Head but also pointed to next.
		//delete temp;			// 4. Delete the Temp.
	}
}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node *temp = new Node;	// 1. Make a Node
	temp->data = val;		// 2. Set the Node's Value to the parameter
	temp->next = head;		// 3. The new Node's (* next) points to the Head.
	head = temp;			// 4. The Head is now the new Node.
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	Node *temp = head;		// 1. Make a Node and set the Temp Node to be equal to the Head(first)
	head = head->next;		// 3. Set the Head to equal Head but also pointed to next.
	delete temp;			// 4. Delete the Temp.
}

template<typename T>
inline T & tForwardList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	return head->data;
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	while (head != nullptr && head->data == val) {
		Node *temp = head;
		head = temp->next;
		delete temp;

		if (this->head == nullptr) {
			break;
		}
	}

	Node *hold = head;
	while (hold != nullptr && hold->next != nullptr) {
		if (hold->next->data == val) {
			Node *temp = hold->next;
			hold->next = temp->next;
			delete temp;
		}
		else {
			hold = hold->next;
		}
	}
}

template<typename T>
inline void tForwardList<T>::display()
{
	Node *temp = new Node;					// 1. Make a Node.
	temp = head;							// 2. Set the Node to be the Head(Front).
	while (temp != NULL) {					// 3. In order to print out all the nodes on the screen, we need a loop which runs as many times as nodes exist.
		std::cout << temp->data << "\t";	// 4. When we print out the values, we have to set the Temp (which is equal to the Head), to point to the Data(Which points to the Value).
		temp = temp->next;					// 5. Temp will now equal the Temp, which will point to next(moves to the next memory address).
	}
	std::cout << std::endl;
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	return iterator(head);
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::end()
{
	return iterator(NULL);
}

template<typename T>
inline tForwardList<T>::iterator::iterator() {
	// initializes an empty iterator pointing to null
	cur = NULL;
}

template<typename T>
inline tForwardList<T>::iterator::iterator(Node * startNode) {
	// initializes an iterator pointing to the given node
	cur = startNode;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator==(const iterator & rhs) const {
	// returns true if the iterator points to the same node
	if (cur == rhs.cur) {
		return true;
	}
	return false;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator!=(const iterator & rhs) const {
	// returns false if the iterator does not point to the same node
	if (cur != rhs.cur) {
		return true;
	}
	return false;
}

template<typename T>
inline T & tForwardList<T>::iterator::operator*() const {
	// returns a reference to the element pointed to by the current node
	return cur->data;
}

template<typename T>
typename tForwardList<T>::iterator & tForwardList<T>::iterator::operator++() {
	// pre-increment (returns a reference to this iterator after it is incremented)
	cur = cur->next;
	return *this;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int) {
	// post-increment (returns an iterator to current node while incrementing the existing iterator)
	iterator copy = *this;
	cur = cur->next;
	return copy;
}