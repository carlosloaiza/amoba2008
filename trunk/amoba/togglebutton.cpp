/*
 * togglebutton.cpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
 */

#include <iostream>
#include "togglebutton.hpp"

using namespace Gtk;

MyToggleButtons::MyToggleButtons(){
	//this->toggled();
	s=2;
}

void MyToggleButtons::my_click(){
	MyWindow *ch;   // ahányszor kattintanék a gombokra, annyiszor létrehozza a MyWindow mutatót.Ezért lesz a c mindig 0
	set_button_status(ch->get_c());  //nem fut le... :S
	set_sensitive(false);
}

void MyToggleButtons::set_button_status(int _s){
	s=_s;
	if(s==0){this->add_pixlabel("pic/circle.png","");}
	else{
		if(s==1){this->add_pixlabel("pic/cross.png","");}
	}
}

int MyToggleButtons::get_button_status(){return s;}
