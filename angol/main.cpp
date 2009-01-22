/*
 * main.cpp
 *
 *  Created on: 2009.01.09.
 *      Author: Karacs Anita
 */

#include "gtkmm.h"
#include "window.hpp"

using namespace Gtk;

int main(int argc, char *argv[]){
	Main kit(argc,argv);
	myWindow MainWindow;
	Main::run(MainWindow);
}
