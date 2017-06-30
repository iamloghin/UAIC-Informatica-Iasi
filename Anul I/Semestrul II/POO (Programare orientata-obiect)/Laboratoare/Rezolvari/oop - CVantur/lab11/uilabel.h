#include "uicontrol.h"
#include <string>
using namespace std;

class UILabel : public UIControl
{
protected:
	string text;
	
public:
	void setText(string newText);
	string getText();	
};