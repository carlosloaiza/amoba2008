/*
 * main.cpp
 *
 *  Created on: 2008.10.17.
 *      Author: Karacs Anita
 */

#include <gtkmm.h>
#include <iostream>
#include "window.hpp"
#include "togglebutton.hpp"

using namespace std;
using namespace Gtk;

//CVSSSSSSSSSSSSSSS

int main(int argc, char *argv[]){
	Main kit(argc,argv);
	MyWindow MainWindow;
	Main::run(MainWindow);
	return 0;
}
