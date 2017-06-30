#include "uicontrol.h"
#include <string>
#include <vector>
using namespace std;

class UIPanel : public UIControl
{
protected:
	vector<UIControl*> v;
	
public:
	void addControl(UIControl *control);
	void removeControl(const UIControl *control);
	void Paint();
};