/*
 * main.cpp
 *
 *  Created on: 2008.10.17.
 *      Author: Karacs Anita
 */

#include <gtkmm.h>
#include <iostream>
#include <vector>
#include "Window.hpp"
#include "MyButton.hpp"


#include "StateNode.h"



using namespace std;
using namespace Gtk;

int main(int argc, char *argv[]){
	Main kit(argc,argv);
	MyWindow MainWindow;
	Main::run(MainWindow);

	for(int i = 0; i<1; i++){
		StateNode* sn = new StateNode();
		if(i%1000==0) cout << i << "\n";
		sn->~StateNode();
	}

	return 0;
}
