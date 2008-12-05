/*
 * togglebutton.hpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
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
	void setParent(MyWindow* parent);
private:
	MyWindow *ch;
	int i,j, s;
};

#endif /* TOGGLEBUTTON_HPP_ */
