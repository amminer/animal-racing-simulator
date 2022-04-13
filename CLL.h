/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: CLL.h
 * PURPOSE: circular doubly linked list class template.
 */

#pragma once

#include "Node.h"

template<typename T>
class CLL
{
	public:
		CLL(void)
			: head(nullptr), tail(nullptr) {}

		~CLL(void)
		{
			if (head)
				remove_all(head);
		}
		void remove_all(Node<T>* to_delete)
		{
			if (to_delete != tail)
				remove_all(to_delete->get_next());
			delete to_delete; //can this be made tail recursive? TODO
		}

		CLL(const CLL& src) = delete;
		const CLL& operator=(const CLL& rhs) = delete;

		// More legible and public alternative to (bool) !head
		bool is_empty(void)
		{
			return !head;
		}

        /* CLL::push_back(T& new_data)
         * PURPOSE:	insert a new node at the tail of the linkedlist,
         * ARGS:    new_data, data to be wrapped in a node and inserted.
         * RETURN:  None.
         */
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
			head->set_prev(new_node);
			new_node->set_next(head);
		}

		void push_front(T& new_data)
		{
			//TODO - not strictly necessary for asgmt1
		}

		void insert_at(T& new_data, int position)
		{
			//TODO - not strictly necessary for asgmt1
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

		void pop_back(void)
		{ 
			//TODO - not strictly necessary for asgmt1
		}

		void pop_front(void)
		{ 
			//TODO - not strictly necessary for asgmt1
		}

		void remove(T& toRemove)
		{ 
			//TODO - not strictly necessary for asgmt1
		}

		void remove_at(int index)
		{ 
			//TODO - not strictly necessary for asgmt1
		}

		int size(void)
		{
			//TODO - not strictly necessary for asgmt1
			return 0;
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
