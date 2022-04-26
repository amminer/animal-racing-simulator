#pragma once

#include "LinkedList.h"
#include <stdexcept>

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
Node<T>::Node(Node<T>& src)
	: prev(src.prev), next(src.next), data(nullptr)
{
	*this = src;
}
template<typename T>
Node<T>& Node<T>::operator=(Node<T>& rhs)
{
	if (this != &rhs){
		set_data(rhs.get_data());
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
Node<T>*& Node<T>::get_next(void)
{ return next; }

template<typename T>
Node<T>*& Node<T>::get_prev(void) 
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
T*& Node<T>::get_data_ptr(void) 
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
	auto next_del = to_del->get_next();
	delete to_del;
	if (next_del)
		remove_all(next_del);
}

template<typename T>
LLL<T>::LLL(const LLL<T>& src)
	: head(nullptr), tail(nullptr)
{
	*this = src;
}
template<typename T>
const LLL<T>& LLL<T>::operator=(const LLL<T>& rhs)
{
	if (&rhs != this)
		copy_all(rhs.head, head, tail, nullptr);
	return *this;
}

template<typename T>
void LLL<T>::copy_all(Node<T>* src, Node<T>*& dest, Node<T>*& dest_tail, Node<T>* last_dest)
{
	if (!src)
		return;
	else{
		dest = new Node<T>(*src);
		dest->set_prev(last_dest);
		dest_tail = dest;
		copy_all(src->get_next(), dest->get_next(), dest_tail, dest);
	}
}

//				public member functions & their private helpers
template<typename T>
bool LLL<T>::is_empty(void)
{ return !head; }

template<typename T>
size_t LLL<T>::length(void)
{ return count_nodes(head); }
template<typename T>
size_t LLL<T>::count_nodes(Node<T>* list)
{
	if (list == tail)
		return 1;
	else
		return 1 + count_nodes(list->get_next());
}

template<typename T>
T& LLL<T>::at(int index)
{
	size_t i = (size_t) index;
	if (index < 0 or i >= length())
		throw std::out_of_range("index out of bounds!");
	else
		return find_at_index(head, index);
}
template<typename T>
T& LLL<T>::find_at_index(Node<T>* list, int index)
{
	if (index == 0)
		return list->get_data();
	else
		return find_at_index(list->get_next(), index-1);
}

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
bool LLL<T>::remove(T to_remove) //returns whether item was removed
{ 
	bool ret = false;
	if (head)
		if (Node<T>* found_node = find_node(head, to_remove); found_node){
			ret = true;
			remove_node(found_node);
		}
	return ret;
}
template<typename T>
void LLL<T>::remove_node(Node<T>* to_del)
{
	if (to_del == head){			//case (head, len>1) or (head, len=1)
		if (head != tail)			//subcase len>1
			head->set_prev(nullptr);
		else						//subcase len=1
			tail = nullptr;
		head = to_del->get_next();
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
}

template<typename T>
void LLL<T>::display(bool indices)
{
	if (head)
		display(head, 0, indices);
}

template<typename T>
void LLL<T>::display(Node<T>* list, size_t this_index, bool indices)
{
	if (!list)
		return;
	else{
		if (indices){
			std::cout << this_index+1 << ":\n";
		}
		std::cout << list->get_data() << '\n';
		display(list->get_next(), this_index+1, indices);
	}
}

/*								CLL								*/
//		constructors, destructors, op overloads, and their helpers
template<typename T>
CLL<T>::CLL(void)
	: head(nullptr), tail(nullptr) {}

template<typename T>
CLL<T>::~CLL(void)
{ if (head) remove_all(head); }
template<typename T>
void CLL<T>::remove_all(Node<T>* to_delete)
{
	if (to_delete != tail)
		remove_all(to_delete->get_next());
	delete to_delete; //can this be made tail recursive? TODO
}

template<typename T>
CLL<T>::CLL(const CLL<T>& src)
	: head(nullptr), tail(nullptr)
{
	*this = src;
}
template<typename T>
const CLL<T>& CLL<T>::operator=(const CLL<T>& rhs)
{
	if (&rhs != this)
		copy_all(rhs.head, head, tail, tail, rhs.head, head);
	return *this;
}

template<typename T>
void CLL<T>::copy_all(Node<T>* src, Node<T>*& dest, Node<T>*& dest_tail,
					  Node<T>* last_dest, Node<T>* src_head, Node<T>* dest_head)
{
	dest = new Node<T>(*src);
	dest_tail = dest;
	dest->set_prev(last_dest);
	dest->set_next(dest_head);
	if (src->get_next() == src_head)
		return;
	else{
		copy_all(src->get_next(), dest->get_next(), dest_tail, dest, src_head, dest_head);
	}
}

//				public member functions
template<typename T>
bool CLL<T>::is_empty(void)
{ return (bool) !head; }

template<typename T>
int CLL<T>::length(void)
{ return count_nodes(head); }
template<typename T>
int CLL<T>::count_nodes(Node<T>* list)
{
	if (list == tail)
		return 1;
	else
		return 1 + count_nodes(list->get_next());
}

template<typename T>
T& CLL<T>::at(int index)
{
	if (index < 0 or index >= length())
		throw std::out_of_range("index out of bounds!");
	else
		return find_at_index(head, index);
}
template<typename T>
T& CLL<T>::find_at_index(Node<T>* list, int index)
{
	if (index == 0)
		return list->get_data();
	else
		return find_at_index(list->get_next(), index-1);
}

template<typename T>
void CLL<T>::push_back(T& new_data)
{
	Node<T>* new_node = new Node<T>(new_data);
	if (!head){
		head = new_node;
		tail = new_node;
		new_node->set_next(new_node);
		new_node->set_prev(new_node);
	}
	else
		push_back(head, new_node);
}
template<typename T>
void CLL<T>::push_back(Node<T>* list, Node<T>* new_node)
{
	if (list == tail){
		list->set_next(new_node);
		new_node->set_prev(list);
		new_node->set_next(head);
		head->set_prev(new_node);
		tail = new_node;
	}
	else
		push_back(list->get_next(), new_node);
}

template<typename T>
T* CLL<T>::lookup(T key) //must not use reference to accept rvalue arg
{
	Node<T>* ret_node = nullptr;
	T* ret = nullptr;
	if (head){
		ret_node = find_node(head, key);
		if (ret_node){
			ret = ret_node->get_data_ptr();
		}
	}
	return ret;
}
template<typename T>
Node<T>* CLL<T>::find_node(Node<T>* list, T key) //must accept rvalue arg
{
	if (list->get_data() == key)
		return list;
	else if (list == tail)
		return nullptr;
	else
		return find_node(list->get_next(), key);
}

template<typename T>
bool CLL<T>::remove(T to_remove) //Must accept rvalue arg
{ 
	bool ret = false;
	if (head){
		if (Node<T>* found_node = find_node(head, to_remove); found_node){
			ret = true;
			remove_node(found_node);
		}
	}
	return ret;
}
template<typename T>
void CLL<T>::remove_node(Node<T>* to_del)
{
	if (to_del == head){			//case head
		head = to_del->get_next();
		head->set_prev(nullptr);
	}
	else if (to_del == tail){		//case tail
		tail = to_del->get_prev();
		tail->set_next(nullptr);
	}
	else{							//case sandwiched
		//next.prev = this.prev
		to_del->get_next()->set_prev(to_del->get_prev());
		//prev.next = this.next
		to_del->get_prev()->set_next(to_del->get_next());
	}
	delete to_del;					//all cases
}

template<typename T>
void CLL<T>::display(bool indices)
{
	if (head)
		display(head, 0, indices);
	return;
}
template<typename T>
void CLL<T>::display(Node<T>* list, size_t this_index, bool indices)
{
	if (indices){
		std::cout << this_index+1 << ":\n";
	}
	std::cout << list->get_data() <<'\n';
	if (list == tail)
		return;
	else{
		display(list->get_next(), this_index+1, indices);
	}
}

