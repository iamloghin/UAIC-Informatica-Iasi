#include "print.h"
#include <cstdio>

void SetCursorPosition(int x, int y)
{
 	printf("\033[%d;%dH", x + 1, y + 1);
}

void PrintChar(char c, int foreground, int background)
{
	printf("\033[%dm\033[%dm%c\033[%dm\033[%dm", foreground, background, c, 39, 49);
}