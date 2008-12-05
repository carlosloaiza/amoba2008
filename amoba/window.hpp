#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "gtkmm.h"
#include "MyButton.hpp"
#include "NumMatrix.h"

using namespace Gtk;
using namespace std;

class MyButton;
class MyWindow:public Window{
public:
	MyWindow();

	void set_color(int r,int g,int b);
	Gdk::Color get_color();
	void startGame();
	void close();
	void new_game();
	void actionPerformed(MyButton* mb);

protected:
	int c;
	Gdk::Color col;
	string t1,t2,d1,d2,p1,p2;
	Frame MyFrame;
	Table MyTable,MyGameTable;
	Button MyButton_start,MyButton_new,MyButton_close;
	Label MyLabel,MyLabel1,MyLabel2,MyLabel3;
public:
	Entry MyEntry1,MyEntry2;
	Label status_label;
};


#endif /* WINDOW_HPP_ */
