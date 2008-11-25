/*
 * window.hpp
 *
 *  Created on: 2008.10.18.
 *      Author: Karacs Anita
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "gtkmm.h"
#include "togglebutton.hpp"

using namespace Gtk;
using namespace std;

class MyToggleButtons;
class MyWindow:public Window{
public:
	MyWindow();

	int get_c();
	void game();
	void circle_or_cross();
protected:
	int c;
	string t1,t2,p1,p2;
	Frame MyFrame;
	Table MyTable,MyGameTable;
	Entry MyEntry1,MyEntry2;
	Button MyButton_start;
	Label MyLabel,MyLabel1,MyLabel2,MyLabel3,status_label;
};


#endif /* WINDOW_HPP_ */
