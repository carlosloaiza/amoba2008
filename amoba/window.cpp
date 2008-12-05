#include "Window.hpp"
#include <iostream>
#include <vector>

using namespace Gtk;
using namespace std;

MyWindow::MyWindow() :
	MyTable(13, 10, true), MyGameTable(15, 15, true), MyLabel(
			"Udvozollek! Ez az Amoba!\n"
				"A jatek celja, hogy kort es ikszet helyezz el ugy, hogy neked gyuljon ki\n"
				"hamarabb 5 egyforma egy sorban, oszlopban vagy atlosan.\n\n"
				"Jatekosok nevei:"), MyLabel1("1. jatekos:"), MyLabel2(
			"2. jatekos:"), MyButton_start("START"), MyButton_new("Uj jatek"),
			MyButton_close("Bezar") {
	c = 2;
	set_title("Amoba - The Game Ver.1.0");
	set_size_request(775, 480);
	set_border_width(30);
	set_color(240000, 250000, 280000);
	modify_bg(STATE_NORMAL, get_color());
	add(MyTable);

	MyLabel.set_alignment(ALIGN_TOP);
	MyLabel1.set_alignment(ALIGN_RIGHT);
	MyLabel2.set_alignment(ALIGN_RIGHT);
	MyLabel3.set_alignment(ALIGN_TOP);
	MyTable.set_row_spacings(5);
	MyTable.set_col_spacings(5);

	d1 = "Zoli", d2 = "Anna";
	MyTable.attach(MyLabel, 0, 5, 0, 3);
	MyTable.attach(MyLabel1, 1, 2, 4, 5);
	MyTable.attach(MyEntry1, 2, 3, 4, 5);
	MyEntry1.set_text(d1);
	MyEntry1.select_region(0, MyEntry1.get_text_length());

	MyTable.attach(MyLabel2, 1, 2, 5, 6);
	MyTable.attach(MyEntry2, 2, 3, 5, 6);
	MyEntry2.set_text(d2);
	MyEntry2.select_region(0, MyEntry2.get_text_length());
	MyTable.attach(MyButton_start, 2, 3, 6, 7);
	MyButton_start.signal_clicked().connect(sigc::mem_fun(*this,
			&MyWindow::startGame));
	MyButton_close.signal_clicked().connect(sigc::mem_fun(*this,
			&MyWindow::close));
	MyButton_new.signal_clicked().connect(sigc::mem_fun(*this,
			&MyWindow::new_game));

	show_all_children();
}

void MyWindow::startGame() {
	MyButton_start.set_sensitive(false);
	MyTable.attach(MyButton_new, 1, 2, 9, 10);
	MyTable.attach(MyButton_close, 3, 4, 9, 10);
	status_label.set_text("default");
	t1 = " kore, kor kovetkezik (O).", t2 = " kore, iksz kovetkezik (X).";

	if (MyEntry1.get_text() == "Zoli") {
		p1 = d1 + t1;
	} else {
		p1 = MyEntry1.get_text() + t1;
	}
	if (MyEntry2.get_text() == "Anna") {
		p2 = d2 + t2;
	} else {
		p2 = MyEntry2.get_text() + t2;
	}

	status_label.set_text(p1);
	MyFrame.add(status_label);
	MyTable.attach(MyFrame, 6, 9, 11, 13);

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			MyButton *MyTB = new MyButton;
			MyTB->signal_toggled().connect(sigc::mem_fun(MyTB,
					&MyButton::my_click));
			MyTB->setParent(this);
			MyTB->setIndex(i, j);
			MyGameTable.attach(*MyTB, i, i + 1, j, j + 1);
		}
	}
	MyTable.attach(MyGameTable, 5, 10, 0, 10);

	show_all_children();
}

void MyWindow::set_color(int r, int g, int b) {
	col.set_red(r);
	col.set_green(g);
	col.set_blue(b);
}

void MyWindow::actionPerformed(MyButton* button) {
	c = c%2==0?1:2;
	button->setStatus(c);
	if (c == 1) {
		status_label.set_text(p2);
	}
	if (c == 2) {
		status_label.set_text(p1);
	}
}

void MyWindow::new_game() {
	destroy_();
	MyWindow NewWindow;
	Main::run(NewWindow);
}

Gdk::Color MyWindow::get_color() {
	return col;
}

void MyWindow::close() {
	Main::quit();
}
