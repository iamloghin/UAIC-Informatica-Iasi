#include "print.h"
#include "uibutton.h"
//#include <cstdio>

using namespace std;

int main()
{
	UIButton *b = new UIButton(10, 10, 10, 30);
	b->setText("click");
	
	b->Paint();
	
	return 0;
}