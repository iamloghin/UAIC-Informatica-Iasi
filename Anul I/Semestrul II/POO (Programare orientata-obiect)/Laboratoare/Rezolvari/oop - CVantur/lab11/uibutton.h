#include "uicontrol.h"
#include <string>
using namespace std;

class UIButton : public UIControl
{
protected:
	string text;
	bool isPressed;
	
public:
	UIButton(int x, int y, int h, int w);
	void setText(string newText);
	string getText();
	void press();
	void release();
	bool getState();
	void Paint();
};