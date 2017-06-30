#include "lista.h"

template <class T>
void ListaDubluInlantuita<T>::push_back(const T &item)
{
	if(!head)
	{
		head = tail = new Node;
		head->value = item;
		head->next = head->prec = nullptr;
		return;
	}

	tail->next = new Node;
	tail->next->prec = tail;
	tail->next->next = nullptr;
	tail->next->value = item;
	tail = tail->next;
}

template <class T>
void ListaDubluInlantuita<T>::push_front(const T &item)
{
	if(!head)
	{
		head = tail = new Node;
		head->value = item;
		head->next = head->prec = nullptr;
		return;
	}

	head->prec = new Node;
	head->prec->next = head;
	head->prec->prec = nullptr;
	head->prec->value = item;
	head = head->prec;
}

template <class T>
void ListaDubluInlantuita<T>::pop_back()
{
	if(!head) return;

	if(head == tail)
	{
		delete head;
		head = tail = nullptr;
	}

	tail = tail->prec;
	delete tail->next;
	tail->next = nullptr;
}

template <class T>
void ListaDubluInlantuita<T>::pop_front()
{
	if(!head) return;

	if(head == tail)
	{
		delete head;
		head = tail = nullptr;
	}

	head = head->next;
	delete head->prec;
	head->prec = nullptr;
}

template <class T>
void ListaDubluInlantuita<T>::print(std::ostream &out)
{
	for(auto node = head; node; node = node->next)
		out << (node->value) << '\n';
}

template <class T>
bool ListaDubluInlantuita<T>::exists(const T &item)
{
	for(auto node = head; node; node = node->next)
		if(node->value == item)
			return true;
	return false;
}

template class ListaDubluInlantuita<int>;