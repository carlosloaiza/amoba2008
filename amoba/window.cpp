/*
 * window.cpp
 *
 *  Created on: 2008.10.18.
 *      Author: Karacs Anita
 */

#include "window.hpp"
#include <iostream>
#include <vector>

using namespace Gtk;
using namespace std;

//MyWindow::MyWindow(){}

MyWindow::MyWindow():
	MyTable(13,10,true),
	MyGameTable(12,12,true),
	MyLabel(
			"Welcome to Amoba game!\n"
			"The aim is to place circles and crosses into a line of four. Enjoy!\n\n"
			"Enter your names:"),
	MyLabel1("1. player:"),
	MyLabel2("2. player:"),
	MyButton_start("START")
{
	//parent=parentC;
	set_title("Amoba - The Game Ver.1.0");
	set_size_request(785,480);
	set_border_width(30);
	add(MyTable);

	MyLabel.set_alignment(ALIGN_TOP);
	MyLabel1.set_alignment(ALIGN_RIGHT);
	MyLabel2.set_alignment(ALIGN_RIGHT);
	MyLabel3.set_alignment(ALIGN_TOP);
	MyTable.set_row_spacings(5);
	MyTable.set_col_spacings(5);

	MyTable.attach(MyLabel,0,5,0,3);
	MyTable.attach(MyLabel1,1,2,4,5);
	MyTable.attach(MyEntry1,2,3,4,5);
	MyTable.attach(MyLabel2,1,2,5,6);
	MyTable.attach(MyEntry2,2,3,5,6);
	MyTable.attach(MyButton_start,2,3,6,7);
	MyButton_start.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::game));

	show_all_children();
}

void MyWindow::game(){
	status_label.set_text("default");
	t1="'s turn, locate circle(O).",t2="'s turn, locate cross(X).";

	if(MyEntry1.get_text()==""){
		p1="Karen"+t1;
	} else{
		p1=MyEntry1.get_text()+t1;
	}
	if(MyEntry2.get_text()==""){
		p2="Ann"+t2;
	} else{
		p2=MyEntry2.get_text()+t2;
	}

/*	while(!win){ //win - nyert-e a játékos...
		if(ha a kör/iksz következik){
			print_label.set_text("1. player's turn"); //beírni a nevet...
		} else{
			print_label.set_text("2. player's turn"); //szintén név...
		}
	}
*/
	status_label.set_text(p1);
	MyFrame.add(status_label);
	MyTable.attach(MyFrame,6,9,11,13);

	c=0;
	for(int i=0;i<12;i++){
		for(int j=0;j<13;j++){
			//char buffer[32];
			//sprintf(buffer,"%d,%d",i+1,j+1);
			MyToggleButtons *MyTB=new MyToggleButtons;
			MyTB->my_toggled();
			MyTB->set_button_status(2); //2-üres gomb
			MyTB->signal_toggled().connect(sigc::mem_fun(*this,&MyWindow::circle_or_cross));//Hiba itt... szerintem
			MyGameTable.attach(*MyTB,i,i+1,j,j+1);
		}
	}
	MyTable.attach(MyGameTable,5,10,0,10);

	//ide jön a logikai rész... vagy ha Gergõ azt mondja, hogy külön kell, akkor külön jön.

	show_all_children();
}

void MyWindow::circle_or_cross(){
	if(c==0){
		status_label.set_text(p2);
	}
	if(c==1){
		status_label.set_text(p1);
	}
	MyToggleButtons *ch;
	ch->my_click();
	c=abs((c%2)-1);
}

int MyWindow::get_c(){return c;}
