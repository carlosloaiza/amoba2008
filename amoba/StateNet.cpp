/*
 * StateNet.cpp
 *
 *  Created on: 2008.12.06.
 *      Author: bacsog
 */

#include<iostream>
#include<sstream>
#include<string>
#include "StateNet.h"

using namespace std;

StateNet::StateNet() {
	// TODO Auto-generated constructor stub
}

StateNet::~StateNet() {
	// TODO Auto-generated destructor stub
}

void StateNet::setActState(NumMatrix<int>* state) {
	actState = state;
}

std::string StateNet::getNextStep() {
//ide fog j�nni egy egyszer� keres�s, ami a gy�k�r gyerekei k�z�l kiv�lasztja azt, amelyiknek
//legnagyobb a kontroll�rt�ke - el�tte keres�s wflag-re
	for(int i=0; i<SIZE; i++) {
		for(int j=0; j<SIZE; j++) {
			if(actState->getCell(i,j)==0) {
				std::stringstream ss;
				ss<<i;
				ss<<";";
				ss<<j;
				return ss.str();
			}
		}
	}
	return "0;0";
}

void StateNet::clear() {
//TODO
//az actState-hez k�pest megvizsg�ltatja az Analyzer-rel az �sszes Node-ot, t�rli az elavultakat
}
StateNode* StateNet::createNode(NumMatrix<int>* state) {
//TODO
//hashgen -> keres�s a hash vektorban esetlegesen visszadni az elemet egy�bk�nt �j node
}

