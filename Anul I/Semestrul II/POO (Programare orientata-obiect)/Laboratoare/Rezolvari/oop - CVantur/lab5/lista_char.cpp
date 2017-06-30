#include "lista.h"
#include <cstring>
#include <iostream>

void ListaDubluInlantuita<char*>::assign(char* &src, const char *dest)
{
	src = new char[strlen(dest)];
	std::cout << dest << ' ';
	strcpy(src, dest);
	std::cout << src << '\n';
}

void ListaDubluInlantuita<char*>::push_back(const char* item)
{
	if(!head)
	{
		head = tail = new Node;
		assign(head->value, item);
		std::cout << head->value << '\n';
		head->next = head->prec = nullptr;
		return;
	}

	tail->next = new Node;
	tail->next->prec = tail;
	tail->next->next = nullptr;
	assign(tail->next->value, item);
	tail = tail->next;
}

void ListaDubluInlantuita<char*>::push_front(const char* item)
{
	if(!head)
	{
		head = tail = new Node;
		assign(head->value, item);
		head->next = head->prec = nullptr;
		return;
	}

	head->prec = new Node;
	head->prec->next = head;
	head->prec->prec = nullptr;
	assign(head->prec->value, item);
	head = head->prec;
}

void ListaDubluInlantuita<char*>::pop_back()
{
	if(!head) return;

	if(head == tail)
	{
		delete head->value;
		delete head;
		head = tail = nullptr;
	}

	tail = tail->prec;
	delete tail->next->value;
	delete tail->next;
	tail->next = nullptr;
}

void ListaDubluInlantuita<char*>::pop_front()
{
	if(!head) return;

	if(head == tail)
	{
		delete head->value;
		delete head;
		head = tail = nullptr;
	}

	head = head->next;
	delete head->prec->value;
	delete head->prec;
	head->prec = nullptr;
}

void ListaDubluInlantuita<char*>::print(std::ostream &out)
{
	for(auto node = head; node; node = node->next)
		out << (node->value) << '\n';
}

bool ListaDubluInlantuita<char*>::exists(const char* item)
{
	for(auto node = head; node; node = node->next)
		if(strcmp(node->value, item) == 0)
			return true;
	return false;
}