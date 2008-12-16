/*
 * main.cpp
 *
 *  Created on: 2008.12.14.
 *      Author: Bacsó Gergely
 */

#include <windows.h>
#include <gtkmm.h>
#include <iostream>
#include <vector>
#include <list>
#include "Window.hpp"
#include "MyButton.hpp"

using namespace std;
using namespace Gtk;

int main(int argc, char *argv[]){

	Main kit(argc,argv);
	MyWindow MainWindow;
 	Main::run(MainWindow);

	return 0;
}
