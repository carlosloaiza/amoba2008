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

	int is_terminated();
	void my_click();
	void set_button_status(int _s);
	void set_index(int _i,int _j);
	int getCell(int _a,int _b);
	void setParent(MyWindow* parent);
private:
	MyWindow *ch;
public:
	int data[15][15]; //0-üres|| 1-kor||2-X
	int i,j;
};

#endif /* TOGGLEBUTTON_HPP_ */
