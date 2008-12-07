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
	n3->setCell(1,1,1);
	n3->setCell(1,2,1);
	n3->setCell(1,3,1);
	sn->setActState(n3);

	NumMatrix<int>* n2 = new NumMatrix<int>();
	n2->setCell(1,1,1);
	n2->setCell(1,2,1);
	sn->setActState(n2);

	NumMatrix<int>* n1 = new NumMatrix<int>();
	n1->setCell(1,1,2);
	sn->setActState(n1);

	NumMatrix<int>* n4 = new NumMatrix<int>();
	n4->setCell(4,4,1);
	sn->setActState(n4);

	return 0;
}
