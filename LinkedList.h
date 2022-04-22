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
		Node<T>(Node<T>& src);
		Node<T>& operator=(Node<T>& rhs);
		~Node(void);

		Node<T>*& get_next(void);
		Node<T>*& get_prev(void) ;
		T& get_data(void) ;
		T*& get_data_ptr(void) ;
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
		LLL(const LLL& src);
		const LLL& operator=(const LLL& rhs);

		bool is_empty(void);
		void push_back(T& new_data);
		T* lookup(T key); //must not use reference to accept rvalue arg
		bool remove(T to_remove);
		void display(void);
	private:
		Node<T>* head;
		Node<T>* tail;

		void copy_all(Node<T>* src, Node<T>*& dest, Node<T>*& dest_tail, Node<T>* last_dest);
		void remove_all(Node<T>* to_del);
		void push_back(Node<T>* list, Node<T>* new_node);
		Node<T>* find_node(Node<T>* list, T key); //must accept rvalue arg
		void remove_node(Node<T>* to_del);
		void display(Node<T>* list);
};

//circular doubly linked list
template<typename T>
class CLL
{
	public:
		CLL(void);
		~CLL(void);
		CLL(const CLL& src);
		const CLL& operator=(const CLL& rhs);
		bool is_empty(void);
		void push_back(T& new_data);
		T* lookup(T key); //must not use reference to accept rvalue arg
		bool remove(T to_remove); //Must accept rvalue arg
		void display(void);
	private:
		Node<T>* head;
		Node<T>* tail;

		void copy_all(Node<T>* src, Node<T>*& dest, Node<T>*& dest_tail,
							  Node<T>* last_dest, Node<T>* src_head, Node<T>* dest_head);
		void remove_all(Node<T>* to_delete);
		void push_back(Node<T>* list, Node<T>* new_node);
		Node<T>* find_node(Node<T>* list, T key); //must accept rvalue arg
		void remove_node(Node<T>* to_del);
		void display(Node<T>* list);
};

#include "LinkedList.cpp" //avoids linker error
