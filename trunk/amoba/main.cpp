/*
 * main.cpp
 *
 *  Created on: 2008.12.04.
 *      Author: Bacsó Gergely
 */

#include <windows.h>
#include <gtkmm.h>
#include <iostream>
#include <vector>
#include <list>
#include "Window.hpp"
#include "MyButton.hpp"


#include "StateNode.h"
#include "StateNet.h"
#include "NumMatrix.h"




using namespace std;
using namespace Gtk;

int main(int argc, char *argv[]){

	Main kit(argc,argv);
	MyWindow MainWindow;
 	Main::run(MainWindow);

	StateNet* sn = new StateNet();

	NumMatrix<int>* n3 = new NumMatrix<int>();
	n3->setCell(6,7,1);
	n3->setCell(7,7,1);
	n3->setCell(8,7,1);
	n3->setCell(9,7,2);
	sn->setActState(n3);
	cout << "\n" <<"nextstep: "<< sn->getNextStep() << "\n";

	return 0;
}
