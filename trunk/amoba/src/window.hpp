/*
 * window.hpp
 *
 *  Created on: 2008.10.18.
 *      Author: Karacs Anita
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "gtkmm.h"

using namespace Gtk;
using namespace std;

class MyWindow:public Window{
public:
	MyWindow();
	static int c;

	static int get_c();
	static void game();
	static void circle_or_cross();
protected:
	string t1,t2,p1,p2;
	Frame MyFrame;
	Table MyTable,MyGameTable;
	Entry MyEntry1,MyEntry2;
	Button MyButton_start;
	Label MyLabel,MyLabel1,MyLabel2,MyLabel3,status_label;
};


#endif /* WINDOW_HPP_ */
