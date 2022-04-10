/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: LL.h
 * PURPOSE: linear doubly linked list class template
 * and node class template. Used as parent of CLL,
 * used as elements of stable array in main function.
 */

#pragma once

/* class Node
 * Encapsulates some data and its neighbors in a list (next and prev).
 * Made to be used by LinkedList class template.
 */
template<typename T>
class Node
{
	public:
		Node()
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

		~Node()
		{
			if (data)
				delete data;
		}

		Node* get_next()
		{
			return next;
		}

		Node* get_prev()
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

		T get_data()
		{
			return *data;
		}

		T* get_data_ptr()
		{
			return data;
		}

	private:
		Node* prev;
		Node* next;
		T* data;
};

template<typename T>
class LinkedList
{
	public:
		LinkedList()
		{
			head = nullptr;
		}
		~LinkedList()
		{
			Node<T>* temp = head;
			while(temp){
				head = temp;
				temp = head->next;
				delete head;
			}
		}
		LinkedList(const LinkedList& src) = delete;
		const LinkedList& operator=(const LinkedList& rhs) = delete;

		void insert(T& new_data)
		{
			Node<T>* new_node {new_data};
			if (!head)
				head = new_node;
			else{
				Node<T>* temp = head;
				while (temp->get_next()){
					temp = temp->get_next();
				}
				temp->set_next(new_node);
				new_node->set_prev(temp);
			}
		}

		bool is_empty()
		{
			return !head;
		}

	private:
		Node<T>* head;
};
