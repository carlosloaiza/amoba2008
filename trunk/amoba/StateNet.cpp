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
//ide fog jönni egy egyszerû keresés, ami a gyökér gyerekei közül kiválasztja azt, amelyiknek
//legnagyobb a kontrollértéke - elõtte keresés wflag-re
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
//az actState-hez képest megvizsgáltatja az Analyzer-rel az összes Node-ot, törli az elavultakat
}
StateNode* StateNet::createNode(NumMatrix<int>* state) {
//TODO
//hashgen -> keresés a hash vektorban esetlegesen visszadni az elemet egyébként új node
}

