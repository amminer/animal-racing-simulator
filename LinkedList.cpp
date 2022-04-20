#pragma once

#include "LinkedList.h"

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
Node<T>& Node<T>::operator=(const Node<T>& rhs)
{
	if (this != &rhs){
		set_data(rhs->get_data());
	}
	return *this; //in case of chained assignments
}

template<typename T>
Node<T>::~Node(void)
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
T* Node<T>::get_data_ptr(void)
{ return data; }

/*								LLL								*/
//		constructors, destructors, op overloads, and their helpers
template<typename T>
LLL<T>::LLL(void)
	: head(nullptr), tail(nullptr) {}

template<typename T>
LLL<T>::~LLL(void)
{ if (head) remove_all(head); }
template<typename T>
void LLL<T>::remove_all(Node<T>* to_del)
{
	if (to_del != tail)
		remove_all(to_del->get_next());
	delete to_del; //TODO tail recursion
}

//TODO copy constr, operator=

//				public member functions
template<typename T>
bool LLL<T>::is_empty(void)
{ return !head; }

template<typename T>
void LLL<T>::push_back(T& new_data)
{
	Node<T>* new_node = new Node<T>(new_data);
	if (!head){
		head = new_node;
		tail = new_node;
	}
	else
		push_back(head, new_node);
}
template<typename T>
void LLL<T>::push_back(Node<T>* list, Node<T>* new_node)
{
	if (list == tail){
		list->set_next(new_node);
		new_node->set_prev(list);
		tail = new_node;
	}
	else
		push_back(list->get_next(), new_node);
}

template<typename T>
T* LLL<T>::lookup(T key) //must not use reference to accept rvalue arg?
{
	T* ret = nullptr;
	if (head)
		if (Node<T>* ret_node = find_node(head, key); ret_node)
			ret = ret_node->get_data_ptr();
	return ret;
}
template<typename T>
Node<T>* LLL<T>::find_node(Node<T>* list, T key) //must accept rvalue arg?
{
	if (list->get_data() == key)
		return list;
	else if (list == tail)
		return nullptr;
	else
		return find_node(list->get_next(), key);
}

template<typename T>
bool LLL<T>::remove(T to_remove)
{ 
	bool ret = false;
	if (head)
		if (Node<T>* found_node = find_node(head, to_remove); found_node)
			ret = remove_node(found_node);
	return ret;
}
template<typename T>
bool LLL<T>::remove_node(Node<T>* to_del)
{
	// ! len of list must be >=1 lest ye segfault
	if (to_del == head){			//case (head, len>1) or (head, len=1)
		head = to_del->get_next();
		if (head != tail)			//subcase len>1
			head->set_prev(nullptr);
		else						//subcase len=1
			tail = nullptr;
	}
	else if (to_del == tail){		//case tail, len>1
		tail = to_del->get_prev();
		tail->set_next(nullptr);
	}
	else{							//case sandwiched, len>1
		if (to_del->get_next())	//next.prev = this.prev
			to_del->get_next()->set_prev(to_del->get_prev());
		if (to_del->get_prev()) //prev.next = this.next
			to_del->get_prev()->set_next(to_del->get_next());
	}
	delete to_del;					//all cases
	return true;
}

template<typename T>
void LLL<T>::display(void)
{
	if (head)
		display(head);
}

template<typename T>
void LLL<T>::display(Node<T>* list)
{
	if (!list)
		return;
	else{
		std::cout << list->get_data() << '\n';
		display(list->get_next());
	}
}
