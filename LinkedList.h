#pragma once

#include <iostream>

/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: LinkedList.h
 * PURPOSE: Node, linear linked list,
 *	and circular linked list class templates.
 */

//node (used by LLL and CLL)
template<typename T>
class Node
{
	public:
		Node(void);
		Node(T& new_data);
		Node<T>(const Node<T>& src);
		Node<T>& operator=(const Node<T>& rhs);
		~Node(void);

		Node<T>* get_next(void);
		Node<T>* get_prev(void);
		T& get_data(void);
		T* get_data_ptr(void);
		void set_next(Node<T>* n);
		void set_prev(Node<T>* n);
		void set_data(T& new_data);
	private:
		Node* prev;
		Node* next;
		T* data;
};

//linear doubly linked list
template<typename T>
class LLL
{
	public:
		LLL(void);
		~LLL(void);
		LLL(const LLL& src) = delete;
		const LLL& operator=(const LLL& rhs) = delete;

		void remove_all(Node<T>* to_delete);
		bool is_empty(void);

		void push_back(T& new_data)
		{
			Node<T>* new_node = new Node<T>(new_data);
			Node<T>* temp = head;
			if (!head){
				head = new_node;
				}
			else{
				while (temp != tail){
					temp = temp->get_next();
				}
				temp->set_next(new_node);
				new_node->set_prev(temp);
			}
			tail = new_node; //always the case
		}

		T* lookup(T key) //must not use reference to accept rvalue arg
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
		Node<T>* find_node(Node<T>* list, T key) //must accept rvalue arg
		{
			if (list->get_data() == key)
				return list;
			else if (list != tail)
				return find_node(list->get_next(), key);
			else
				return nullptr;
		}

		bool remove(T to_remove)
		{ 
			bool ret = false;
			if (head){
				if (Node<T>* found_node = find_node(head, to_remove); found_node){
					remove_node(found_node);
					ret = true;
				}
			}
			return ret;
		}
		void remove_node(Node<T>* to_del)
		{
			//len of list must be >=1 to enter
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
		}

		void display(void)
		{
			Node<T>* temp = head;
			while (temp != tail){
				std::cout << temp->get_data() << '\n';
				temp = temp->get_next();
			}
			std::cout << tail->get_data() << '\n';
		}

	private:
		Node<T>* head;
		Node<T>* tail;
};

#include "LinkedList.cpp" //avoids linker error
