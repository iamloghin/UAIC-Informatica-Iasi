#include "uibutton.h"

UIButton::UIButton(int x, int y, int h, int w)
{
	X = x;
	Y = y;
	Width = w;
	Height = h;
}

void UIButton::setText(string newText)
{
	text = newText;
}

string UIButton::getText()
{
	return text;
}

void UIButton::press()
{
	isPressed = true;
}

void UIButton::release()
{
	isPressed = false;
}

bool UIButton::getState()
{
	return isPressed;
}

void UIButton::Paint()
{
	int x = X;// + Parent->getX();
	int y = Y;// + Parent->getY();
	
	printf("%d %d\n", Height, Width);
	
	for(int i = x; i < x + Height; ++i)
	{
		for(int j = y; j < y + Width; ++j)
		{
			SetCursorPosition(i, j);
			PrintChar(' ', 31, 42);
		}
	}
	
	int row = x + Height / 2;
	int col = y + Width / 4;
	
	for(int i = 0; i < text.length(); ++i)
	{
		SetCursorPosition(row, col + i);
		PrintChar(text[i], 31, 42);
	}
	
	SetCursorPosition(x + Height, y + Width);
}