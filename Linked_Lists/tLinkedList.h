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
	while (head->next != NULL) {
		Node *temp = new Node;	// 1. Make a Node
		temp = head;			// 2. Set the Temp Node to be equal to the Head(first)
		head = head->next;		// 3. Set the Head to equal Head but also pointed to next.
		delete temp;			// 4. Delete the Temp.
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
	Node *temp = new Node;	// 1. Make a Node
	temp = head;			// 2. Set the Temp Node to be equal to the Head(first)
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
	// TODO: insert return statement here
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
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
