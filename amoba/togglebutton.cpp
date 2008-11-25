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
	//s=2;
}

void MyToggleButtons::my_click(){
	MyWindow *ch;
	if(get_button_status()==2){
		set_button_status(ch->get_c());
	}
}

void MyToggleButtons::set_button_status(int _s){
	s=_s;
	if(s==0){this->add_pixlabel("circle.png","");std::cout<<"aaa#";}
	else{
		if(s==1){this->add_pixlabel("cross.png","");}
	}
}

int MyToggleButtons::get_button_status(){return s;}

void MyToggleButtons::my_toggled(){
	this->toggled();
}
