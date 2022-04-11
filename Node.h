/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: Node.h
 * PURPOSE: linear doubly linked list class template
 */

#pragma once

#include<iostream>

template<typename T>
class Node
{
	public:
		Node(void)
			: prev(nullptr), next(nullptr), data(nullptr) {};

		Node(T new_data)
			: prev(nullptr), next(nullptr), data(nullptr)
		{
			set_data(new_data);
		}

		void set_data(T new_data)
		{
			if(data)
				delete data;
			data = new T(new_data);
			return;
		}

		Node(const Node& src)
			: prev(nullptr), next(nullptr), data(nullptr)
		{
			this = src;
		}
		Node* operator=(const Node& rhs)
		{
			if (this != &rhs){
				set_data(rhs->get_data());
			}
		}

		~Node(void)
		{
			if (data)
				delete data;
		}

		Node* get_next(void)
		{
			return next;
		}

		Node* get_prev(void)
		{
			return prev;
		}

		void set_next(Node* n)
		{
			next = n;
			return;
		}

		void set_prev(Node* n)
		{
			prev = n;
			return;
		}

		T get_data(void)
		{
			return *data;
		}

		T* get_data_ptr(void)
		{
			return data;
		}

	private:
		Node* prev;
		Node* next;
		T* data;
};

