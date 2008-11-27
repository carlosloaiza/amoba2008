/*
 * togglebutton.cpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
 */

#include <iostream>
#include "togglebutton.hpp"

using namespace Gtk;

MyToggleButtons::MyToggleButtons() {
	//this->toggled();
	s = 2;
}

void MyToggleButtons::my_click() {
	set_button_status(ch->getState(this));
	set_sensitive(false);
}

void MyToggleButtons::set_button_status(int _s) {
//0 állapotként az üreset tároljuk. Ez nekem a logika során kényelmesebb
//úgyhogy itt is átállítottam
//+elég furcsa volt az az if :)
	s = _s;
	if (s == 1) {
		this->add_pixlabel("pic/circle.png", "");
	} else if (s == 2) {
		this->add_pixlabel("pic/cross.png", "");
	}
}

void MyToggleButtons::setParent(MyWindow* parent) {
ch = parent;
}
