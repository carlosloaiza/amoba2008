/*
 * togglebutton.hpp
 *
 *  Created on: 2008.10.29.
 *      Author: Karacs Anita
 */

#ifndef TOGGLEBUTTON_HPP_
#define TOGGLEBUTTON_HPP_

#include "gtkmm.h"
#include "window.hpp"

using namespace Gtk;
using namespace std;

class MyToggleButtons:public ToggleButton{
public:
	MyToggleButtons();

	void my_click();
	void my_toggled();
	void set_button_status(int _s);
private:
	int s; //0-kör|| 1-iksz||2-üres
};

#endif /* TOGGLEBUTTON_HPP_ */
