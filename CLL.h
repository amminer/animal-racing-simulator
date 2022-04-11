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
 * Made to be used by CLL class template.
 */
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

template<typename T>
class CLL													//TODO
{
	public:
		CLL(void)
			: head(nullptr) {}

		~CLL(void) //delete all nodes if there are any
		{
			Node<T>* temp = head;
			while(temp){
				head = temp;
				temp = head->next;
				delete head;
			}
		}

		CLL(const CLL& src) = delete;
		const CLL& operator=(const CLL& rhs) = delete;

        /* CLL::insert(T& new_data)
         * PURPOSE:	insert a new node at the "tail" of the linkedlist, before head and after tail.
         * ARGS:    new_data, the new data member to be wrapped in a node and inserted.
         * RETURN:  None.
         */
		void insert(T& new_data)
		{
			/* CODE FOR NON-CIRCULAR DOUBLY LINKED WITHOUT TAIL, NEED TO CONVERT TODO

			Node<T>* new_node = new Node<T>(new_data);
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

			*/
		}

		bool is_empty(void)
		{
			return !head;
		}

		void remove(int index) 	//Would like to be able to remove by string key,
		{					  	//unsure of how w/ templating
			//TODO - not strictly necessary for asgmt1
		}

		//would like to be able to lookup by string key,
		//unsure of how w/ templating

		int size(void)
		{
			//TODO - not strictly necessary for asgmt1
			return 0;
		}

		void display(void)
		{
			//TODO - not strictly necessary for asgmt1
		}

	private:
		Node<T>* head;
		Node<T>* tail;
};
