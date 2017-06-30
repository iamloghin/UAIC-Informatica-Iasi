#include <ostream>

template <class T>
class ListaDubluInlantuita
{
  	struct Node
 	{
  		T value;
  		Node *next, *prec;
 	};
 	Node *head, *tail;
 
	public:
 	ListaDubluInlantuita() { head = nullptr; }
 	// completati cu functiile cerute aici
 	void push_back(const T &item);
 	void push_front(const T &item);
 	void pop_back();
 	void pop_front();
 	void print(std::ostream &out);
 	bool exists(const T &item);
};

template <>
class ListaDubluInlantuita <char*>
{
  	struct Node
 	{
  		char* value;
  		Node *next, *prec;
 	};
 	Node *head, *tail;

 	void assign(char* &src, const char* dest);
 
	public:
 	ListaDubluInlantuita() { head = nullptr; }
 	// completati cu functiile cerute aici
 	void push_back(const char* item);
 	void push_front(const char* item);
 	void pop_back();
 	void pop_front();
 	void print(std::ostream &out);
 	bool exists(const char* item);
};