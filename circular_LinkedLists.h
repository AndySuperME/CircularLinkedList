#ifndef CIRCULAR_LINKEDLISTS_H
#define CIRCULAR_LINKEDLISTS_H

using std::cout;
using std::endl;

template <class T>
class LinkList;

template <class T>
class Node
{
	friend class LinkList<T>;
	public:
		Node() :Data(0), link(0) {};
		Node(T a) :Data(a), link (0) {};
	private:
		T Data;
		Node *link;
};

template <class T>
class LinkList
{
	public:
		LinkList() :first(0) {};
		void PrintList();
		void Push_front(T);
		void Push_back(T);
		void Delete(T);
		void Reverse();
		Node<T>* GetLast();
	private:
		Node<T> *first;
};

template <class T>
void LinkList<T>::PrintList()
{
	if (first == 0)
	{
		cout << "List is empty!" << endl;
		return;
	}

	Node<T> *current = first;
	while (current -> link != first)
	{
		cout << current->Data << " ";
		current = current -> link; 
	}
	cout << current->Data << endl;
}

template <class T>
void LinkList<T>::Push_front(T x)
{
	Node<T> *newnode = new Node<T>(x);
	newnode->link = first;
	first = newnode;
	if (first -> link == 0)
	{
		return;
	}

	Node<T> *current = first;
	if (current->link->link == 0)
	{
		current->link->link = first;
	}
	else
	{
		current = first->link->link;
		while (current->link != first->link)
		{
			current = current->link;
		}
		current->link= first;
	}
}

template <class T>
void LinkList<T>::Push_back(T x)
{
	Node<T> *newnode = new Node<T>(x);
	if (first == 0)
	{
		first = newnode;
		return;
	}

	Node<T> *current = first;
	if (current->link == 0)
	{
		current->link = newnode;
		newnode->link = first;
	}
	else
	{
		while (current->link != first)
		{
			current = current->link;
		}
		current->link = newnode;
		newnode->link = first;
	}
}

template <class T>
void LinkList<T>::Delete(T x)
{
	Node<T> *current = first,
		    *previous = 0;
	while (current->link != first)
	{
		if (x == current->Data && x == first->Data)
		{
			GetLast()->link = current->link;
			first = current->link;
			delete current;
			current = 0;
			break;
		}
		else if (x == current->Data)
		{
			previous->link = current->link;
			delete current;
			current = 0;
			break;
		}
		previous = current;
		current = current->link;
	}
	
	if (current == 0)
	{
		return;
	}
	previous->link = first;
	delete current;
	current = 0;
}

template <class T>
void LinkList<T>::Reverse()
{
	Node<T> *current = first,
		    *previous = 0,
		 	*tmp = first->link;
	while (tmp != first)
	{
		current->link = previous;
		previous = current;
		current = tmp;
		tmp = tmp->link;
	}
	current->link = previous;
	first = current;

	current = first;
	while (current->link != 0)
	{
		current = current->link;
	}
	current->link = first;
}

template <class T>
Node<T>* LinkList<T>::GetLast()
{
	Node<T> *current = first;
	while (current->link != first)
	{
		current = current->link;
	}
	return current;
}
#endif
