/*
 * StateNode.cpp
 *
 *  Created on: 2008.12.05.
 *      Author: bacsog
 */

#include "StateNode.h"
#include <iostream>
#include <vector>

StateNode::StateNode() {
	state = new NumMatrix<int>();
	myValues = new NumMatrix<int>();
	opValues = new NumMatrix<int>();
	winnerFlag = 0;
	myValue = 0;
	opValue = 0;
	level = 0;
	parents = new vector<StateNode*>();
	childs = new vector<StateNode*>();
}

StateNode::~StateNode() {
//TODO feladatkezelõben látszik, hogy a memória folyamatosan bõvül - bug
	delete state;
	delete myValues;
	delete opValues;
	delete parents;
	delete childs;
}

StateNode* StateNode::clone() {
//TODO fagy tõle a windows... :)
	StateNode* cloned = new StateNode();
	NumMatrix<int> nState = *(this->state);
	cloned->setState(&nState);
	return cloned;
}

NumMatrix<int>* StateNode::getState() {
	return state;
}

void StateNode::setState(NumMatrix<int>* newState) {
	this->state = newState;
}
