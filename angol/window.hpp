/*
 * window.hpp
 *
 *  Created on: 2009.01.09.
 *      Author: Karacs Anita
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "gtkmm.h"
#include <vector>

using namespace Gtk;
using namespace std;

class myWindow:public Window{
public:
	myWindow();
	void setColor(int r,int g,int b);
	void closeClicked();
	void nextClicked();
	void okClicked();
	void enterClicked();
	void loginPressed();
	void new_userPressed();
	void testOkClicked();
	void nextSensitive();
	void test(ifstream &t);
	void sort();
	bool passwordCheck(ifstream &l);

	int good,bad;
	struct word{
		int freq;
		string eng;
		string hu;
	};
	word loading(ifstream &t);
	vector <word> dictionary;
	//vector <vector<int> > vTests;
	string whatPressed,language;
protected:
	string user;
	Gdk::Color c;
	Table myTable,myTable2,myTable3,sTable;
	Label myLabel,myLabel2,title,userLabel,passwordLabel,langLabel,testLabel1,testLabel2;
	Frame myFrame,myFrame2;
	Entry userEntry,passwordEntry,testEntry;
	Button close,next,ok,enter,icon,icon2,icon3,icon4,testOk;
	RadioButton login,new_user;
	RadioButton::Group myGroup;
	ScrolledWindow myScrolledWindow;
	ComboBoxEntryText myCombo;
};

#endif /* WINDOW_HPP_ */
