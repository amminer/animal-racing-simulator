/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: LinkedList.cpp
 * PURPOSE: Node, linear linked list,
 *	and circular linked list class templates.
 */

/*								NODE								*/
//		constructors, destructors, op overloads, and their helpers
template<typename T>
Node<T>::Node(void)
	: prev(nullptr), next(nullptr), data(nullptr) {}

template<typename T>
Node<T>::Node(T& new_data)
	: prev(nullptr), next(nullptr), data(nullptr)
{ set_data(new_data); } //using helper probably unnecessary? TODO
template<typename T>
void Node<T>::set_data(T& new_data)
{
	if(data)
		delete data;
	data = new T{new_data};
	return;
}

template<typename T>
Node<T>::Node(const Node<T>& src)
	: prev(nullptr), next(nullptr), data(nullptr)
{
	this = src;
}
template<typename T>
Node<T>& operator=(const Node<T>& rhs)
{
	if (this != &rhs){
		set_data(rhs->get_data());
	}
	return *this; //in case of chained assignments
}

template<typename T>
~Node(void)
{
	if (data)
		delete data;
}

//				public member functions
template<typename T>
Node<T>* Node<T>::get_next(void)
{ return next; }

template<typename T>
Node<T>* Node<T>::get_prev(void)
{ return prev; }

template<typename T>
void Node<T>::set_next(Node* new_next)
{
	next = new_next;
	return;
}

template<typename T>
void Node<T>::set_prev(Node* new_prev)
{
	prev = new_prev;
	return;
}

template<typename T>
T& Node<T>::get_data(void)
{ return *data; }

template<typename T>
T& Node<T>::get_data_ptr(void)
{ return data; }

/*								LLL								*/
//		constructors, destructors, op overloads, and their helpers
template<typename T>
LLL<T>::LLL(void)
	: head(nullptr), tail(nullptr) {}

template<typename T>
~LLL(void)
{ if (head) remove_all(head); }
template<typename T>
void remove_all(Node<T>* to_delete)
{
	if (to_delete != tail)
		remove_all(to_delete->get_next());
	delete to_delete; //TODO tail recursion
}

//				public member functions
template<typename T>
bool Node<T>::is_empty(void)
{ return !head; }

template<typename T>
void LLL<T>::push_back(T& new_data)
{
	push_back(head, new_data);
}
template<typename T>
void LLL<T>::push_back(Node<T>* list, T& new_data)
{
	if (list == tail){
		//left off here TODO
	}
	else{
		push_back(list->get_next(), new_data);
}

//IN PROGRESS
