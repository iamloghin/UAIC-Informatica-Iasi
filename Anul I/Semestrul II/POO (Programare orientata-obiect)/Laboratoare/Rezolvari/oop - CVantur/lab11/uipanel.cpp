#include "uipanel.h"

void UIPanel::addControl(UIControl *control)
{
	v.push_back(control);
}

void UIPanel::removeControl(const UIControl *control)
{
	for(auto it = v.begin(); it != v.end(); ++it)
		if(*it == control)
		{
			v.erase(it);
			return;
		}
}

void UIPanel::Paint()
{
	for(auto c : v)
		c->Paint();
}