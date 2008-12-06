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
	myWinnerChild = 0;
	opWinnerChild = 0;
	parents = new vector<StateNode*>();
	children = new vector<StateNode*>();
	bestMoves = new vector<string>();
}

StateNode::~StateNode() {
//TODO feladatkezelõben látszik, hogy a memória folyamatosan bõvül - bug
	delete state;
	delete parents;
	delete children;
	delete bestMoves;
}

StateNode* StateNode::clone() {
//TODO fagy tõle a windows... :)
	StateNode* cloned = new StateNode();
	NumMatrix<int> nState = *(this->state);
	cloned->setState(&nState);
	return cloned;
}

void StateNode::setWinnerFlag(int i) {
	winnerFlag = i;
	for(int i=0;i < parents->size();i++) {
		if(parents->at(i)) {
			parents->at(i)->notifyWinnerFlag(winnerFlag);
		}
	}
}

void StateNode::notifyWinnerFlag(int flag) {
	if(flag = nextPlayer) {myWinnerChild++;} else {opWinnerChild++;}
	if(flag == nextPlayer) {
		setWinnerFlag(nextPlayer);
	} else if(opWinnerChild == children->size() || myWinnerChild == children->size()) {
		setWinnerFlag(flag);
	}
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
