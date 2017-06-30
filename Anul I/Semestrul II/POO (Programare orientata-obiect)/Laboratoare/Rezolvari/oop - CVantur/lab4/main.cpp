#include <iostream>
#include "form.h"
using namespace std;

int main()
{
	Forma *forms[3];

	forms[0] = new Dreptunghi(2, 3);
	forms[1] = new Cerc(10);
	forms[2] = new Triunghi(0, 0, 10, 0, 0, 2);

	for(int i = 0; i < 3; ++i)
		cout << forms[i]->GetName() << ' ' << forms[i]->ComputeArea() << '\n';

	return 0;
}