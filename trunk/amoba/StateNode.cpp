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
	winnerFlag = 0;
	myValue = 0;
	opValue = 0;
	level = 0;
	nextPlayer = 0;
	parents = new vector<StateNode*>();
	childs = new vector<StateNode*>();
	bestMoves = new vector<string>();
}

StateNode::~StateNode() {
//TODO feladatkezelõben látszik, hogy a memória folyamatosan bõvül - bug
	delete state;
	delete parents;
	delete childs;
	delete bestMoves;
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

vector<string>* StateNode::getBestMoves() {
	return bestMoves;
}

void StateNode::setBestMoves(vector<string>* orders) {
	bestMoves = orders;
}

void StateNode::setState(NumMatrix<int>* newState) {
	this->state = newState;
}

void StateNode::setMyValue(int i) {
	myValue = i;
}
void StateNode::setOpValue(int i) {
	opValue = i;
}
