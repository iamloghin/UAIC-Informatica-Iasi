#include <cstring>
#include <algorithm>
#include <iostream>
#include "array.h"
using namespace std;



template<class T>
bool cmp(const T* &lhs, const T* &rhs)
{
	return *lhs < *rhs;
}





template<class T>
Array<T>::Array() { List = nullptr; Capacity = Size = 0; }

template<class T>
Array<T>::~Array()
{
	for(int i = 0; i < Size; ++i) delete List[i];
	delete[] List;
}

template<class T>
Array<T>::Array(int capacity)
{
	Size = 0;
	Capacity = capacity;
	List = new T*[capacity];
}

template<class T>
Array<T>::Array(const Array<T> &otherArray)
{
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;

	List = new T*[Capacity];
	for(int i = 0; i < Size; ++i)
	{
		List[i] = new T;
		*List[i] = *otherArray.List[i];
	}
}

template<class T>
T& Array<T>::operator[] (int index)
{
	if(index < 0 || index >= Size) throw "Index out of range";
	return *List[index];
}


template<class T>
const Array<T>& Array<T>::operator+=(const T &newElem)
{
	if(Size == Capacity) realloc();

	List[Size] = new T;
	*List[Size++] = newElem;

	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem)
{
	if(index < 0 || index >= Size + 1) throw "Invalid position";
	if(Size == Capacity) realloc();

	for(int i = Size - 1; i >= index; --i)
		List[i + 1] = List[i];

	List[index] = new T;
	*List[index] = newElem;
	++Size;

	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if(index < 0 || index >= Size + 1) throw "Invalid position";
	if(Size + otherArray.Size > Capacity)
		realloc(Size + otherArray.Size);

	// move (index .. Size - 1) to (index + otherArray.Size .. Size - 1 + otherArray.Size)
	for(int i = Size - 1; i >= index; --i)
		List[i + otherArray.Size] = List[i];

	for(int i = 0; i < otherArray.Size; ++i)
	{
		List[index + i] = new T;
		*List[index + i] = *otherArray.List[i];
	}

	return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	if(index < 0 || index >= Size) throw "Index out of range";

	delete List[index];

	for(int i = index; i < Size - 1; --i)
		List[i] = List[i + 1];

	--Size;

	return *this;
}


template<class T>
bool Array<T>::operator=(const Array<T> &otherArray)
{
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;

	List = new T*[Capacity];
	for(int i = 0; i < Size; ++i)
	{
		List[i] = new T;
		*List[i] = *otherArray.List[i];
	}
}


template<class T>
void Array<T>::Sort()
{
	sort(List, List + Size, [this](const T* lhs, const T* rhs) -> bool { return true; });
}


template<class T>
int Array<T>::GetSize() { return Size; }

template<class T>
int Array<T>::GetCapacity() { return Capacity; }


template<class T>
void Array<T>::realloc(int newElems)
{
	int newCapacity = min(2 * Capacity, Size + newElems);
	T** newBlock = new T*[newCapacity];

	for(int i = 0; i < Size; ++i)
		newBlock[i] = List[i];

	Capacity = newCapacity;
	List = newBlock;
}