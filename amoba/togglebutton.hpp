/*
 * togglebutton.hpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
 */

#ifndef TOGGLEBUTTON_HPP_
#define TOGGLEBUTTON_HPP_

#include "gtkmm.h"
#include "window.hpp"

using namespace Gtk;
using namespace std;

class MyWindow;
class MyToggleButtons:public ToggleButton{
public:
	MyToggleButtons();

	void my_click();
	void set_button_status(int _s);
	void setParent(MyWindow* parent);
private:
	MyWindow *ch;
	int s; //0-üres|| 1-kor||2-X
};

#endif /* TOGGLEBUTTON_HPP_ */
