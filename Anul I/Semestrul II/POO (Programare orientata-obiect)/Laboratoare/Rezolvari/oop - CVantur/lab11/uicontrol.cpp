#include "uicontrol.h"

int UIControl::getX()
{
	int x;
	UIControl *fth;
	
	for(x = X; fth; fth = fth->Parent)
		x += fth->X;
	
	return x;
}

int UIControl::getY()
{
	int y;
	UIControl *fth;
	
	for(y = Y; fth; fth = fth->Parent)
		y += fth->Y;
	
	return y;
}