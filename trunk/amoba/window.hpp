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
	MyWindow(int _c);

	int get_c();
	void set_c(int _c);
	void set_color(int r,int g,int b);
	Gdk::Color get_color();
	void game();
	void close();
	void new_game();
	void circle_or_cross();
protected:
	//static int c1;
	int c;
	Gdk::Color col;
	string t1,t2,d1,d2,p1,p2;
	Frame MyFrame;
	Table MyTable,MyGameTable;
	Entry MyEntry1,MyEntry2;
	Button MyButton_start,MyButton_new,MyButton_close;
	Label MyLabel,MyLabel1,MyLabel2,MyLabel3,status_label;
};


#endif /* WINDOW_HPP_ */