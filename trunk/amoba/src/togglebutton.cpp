/*
 * togglebutton.cpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
 */

#include <iostream>
#include "gtkmm.h"
#include "togglebutton.hpp"
#include "window.hpp"
class MyWindow;

using namespace Gtk;

MyToggleButtons::MyToggleButtons(){
	//this->toggled();
	s=0;
}

void MyToggleButtons::my_click(){
	if(MyWindow::get_c()==0){
		set_button_status(MyWindow::get_c());
	}
	if(MyWindow::get_c()==1){
		set_button_status(MyWindow::get_c());
	}
}

void MyToggleButtons::set_button_status(int _s){
	s=_s;
	if(s==0){this->add_pixlabel("circle.png","");}
	if(s==1){this->add_pixlabel("cross.png","");}
}

void MyToggleButtons::my_toggled(){
	this->toggled();
}
