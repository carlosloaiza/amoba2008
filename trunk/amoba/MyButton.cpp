#include <iostream>
#include "MyButton.hpp"

using namespace Gtk;

MyButton::MyButton() {
	s = 0;
}

void MyButton::setIndex(int _i, int _j) {
	i = _i;
	j = _j;
}

void MyButton::setParent(MyWindow* parent) {
	ch = parent;
}

void MyButton::my_click() {
	ch->actionPerformed(this);
	set_sensitive(false);
}

void MyButton::setStatus(int _s) {
	//0 �llapotk�nt az �reset t�roljuk. Ez nekem a logika sor�n k�nyelmesebb
	//�gyhogy itt is �t�ll�tottam
	//+el�g furcsa volt az az if :)
	s = _s;
	if (s == 1) {
		this->add_pixlabel("pic/circle.png", "");
	} else if (s == 2) {
		this->add_pixlabel("pic/cross.png", "");
	}
}
