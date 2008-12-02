<<<<<<< .working
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
	//data[i][j]=0;
}

void MyToggleButtons::my_click(){
	set_button_status(ch->getState(this));
	set_sensitive(false);
	if(is_terminated()==1){
		ch->status_label.set_text(ch->MyEntry1.get_text()+" nyert!");
	}
	if(is_terminated()==2){
		ch->status_label.set_text(ch->MyEntry2.get_text()+" nyert!");
	}
	ch->print_cell_data(this);
}

void MyToggleButtons::set_button_status(int _s){
//0 állapotként az üreset tároljuk. Ez nekem a logika során kényelmesebb
//úgyhogy itt is átállítottam

	data[i][j]=_s;
	if (_s == 1) {
		this->add_pixlabel("pic/circle.png", "");
	} else if (_s == 2) {
		this->add_pixlabel("pic/cross.png", "");
	}
}

void MyToggleButtons::set_index(int _i,int _j){
	i=_i;
	j=_j;
	data[i][j]=0;
}

int MyToggleButtons::getCell(int a, int b){
	if(a>=0 && a<18 && b>=0 && b<18){
		return data[a][b];
	}else {return -1;}
}

int MyToggleButtons::is_terminated(){
	if((i+4<15 || j+4<15) && (i-4>=0 || j-4>=0)){
		if(data[i][j]==1 && data[i+1][j]==1 && data[i+2][j]==1 && data[i+3][j]==1 && data[i+4][j]==1){
			return 1;
		}else{return 0;}
		if(data[i][j]==1 && data[i][j+1]==1 && data[i][j+2]==1 && data[i][j+3]==1 && data[i][j+4]==1){
			return 1;
		}else{return 0;}
		if(data[i][j]==1 && data[i+1][j+1]==1 && data[i+2][j+2]==1 && data[i+3][j+3]==1 && data[i+4][j+4]==1){
			return 1;
		}else{return 0;}
		if(data[i][j]==1 && data[i+1][j-1]==1 && data[i+2][j-2]==1 && data[i+3][j-3]==1 && data[i+4][j-4]==1){
			return 1;
		}else{return 0;}

		if(data[i][j]==2 && data[i+1][j]==2 && data[i+2][j]==2 && data[i+3][j]==2 && data[i+4][j]==2){
			return 2;
		}else{return 0;}
		if(data[i][j]==2 && data[i][j+1]==2 && data[i][j+2]==2 && data[i][j+3]==2 && data[i][j+4]==2){
			return 2;
		}else{return 0;}
		if(data[i][j]==2 && data[i+1][j+1]==2 && data[i+2][j+2]==2 && data[i+3][j+3]==2 && data[i+4][j+4]==2){
			return 2;
		}else{return 0;}
		if(data[i][j]==2 && data[i+1][j-1]==2 && data[i+2][j-2]==2 && data[i+3][j-3]==2 && data[i+4][j-4]==2){
			return 2;
		}else{return 0;}
	}else{return 0;}
}

void MyToggleButtons::setParent(MyWindow* parent){
	ch = parent;
}
=======
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
>>>>>>> .merge-right.r21
