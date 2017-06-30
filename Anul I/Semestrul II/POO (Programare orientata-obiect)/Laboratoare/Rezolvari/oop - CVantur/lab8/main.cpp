#include <iostream>
#include "array.h"

int main()
{
	Array<char> arr;

	arr += '2';
	arr += 'h';

	for(int i = 0; i < arr.GetSize(); ++i)
		std::cout << arr[i] << '\n';

	return 0;
}