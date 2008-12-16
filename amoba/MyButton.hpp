/*
 * togglebutton.hpp
 *
 *  Created on: 2008.12.16.
 *      Author: Bacsó Gergely
 */

#ifndef TOGGLEBUTTON_HPP_
#define TOGGLEBUTTON_HPP_

#include "gtkmm.h"
#include "Window.hpp"

using namespace Gtk;
using namespace std;

class MyWindow;
class MyButton:public ToggleButton{
public:
	MyButton();

	int is_terminated();
	void my_click();
	void setStatus(int _s);
	void setIndex(int _i,int _j);
	int getIIndex() {return iIndex;}
	int getJIndex() {return jIndex;}
	void setParent(MyWindow* parent);
private:
	MyWindow *ch;
	int iIndex,jIndex, s;
};

#endif /* TOGGLEBUTTON_HPP_ */
