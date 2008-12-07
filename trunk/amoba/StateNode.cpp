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
	level = 1;
	nextPlayer = 0;
	myWinnerChild = 0;
	opWinnerChild = 0;
	recursiveValue = 0;
	expandValue = 0;
	parents = new vector<StateNode*>();
	children = new vector<StateNode*>();
	bestMoves = new vector<string>();
}

StateNode::~StateNode() {
//TODO feladatkezel�ben l�tszik, hogy a mem�ria folyamatosan b�v�l - bug
	delete state;
	delete parents;
	delete children;
	delete bestMoves;

	for(int i = 0; children->size();i++) {
		children->at(i)->removeParent(this);
	}
}

StateNode* StateNode::clone() {
//TODO fagy t�le a windows... :)
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

void StateNode::removeParent(StateNode* parent) {
	for(int i = 0; parents->size();i++) {
		if(parents->at(i) == parent) {
			parents->erase(parents->begin()+i);
		}
	}
}

long StateNode::getRecursiveValue() {
cout << "ch: \n"; cout.flush();
cout << getChildrenValue();
cout << "ch-end: \n"; cout.flush();
cout << "nu: \n"; cout.flush();
cout << getChildrenNum();
cout << "nu-end: \n"; cout.flush();
	return getChildrenValue()/getChildrenNum();
}

long StateNode::getChildrenValue() {
	long sum = myValue-opValue;
cout << "hash: " <<this->getState()->getHash() << "\n"; cout.flush();
	for(int i=0;i<children->size();i++) {
		sum += children->at(i)->getChildrenValue();
	}
	return sum;
}

int StateNode::getChildrenNum() {
	int sum = 1;
	for(int i=0;i<children->size();i++) {
		sum += children->at(i)->getChildrenNum();
	}
	return sum + children->size();
}

void StateNode::addChild(StateNode* child) {
	children->push_back(child);
	child->setLevel(this->getLevel()+1);
	child->addParent(this);
	child->setNextPlayer(this->nextPlayer==1?2:1);
}

void StateNode::addParent(StateNode* parent) {
	parents->push_back(parent);
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

int StateNode::getLevel() {
	return level;
}

void StateNode::setLevel(int lev) {
	level = lev;
}

int StateNode::getNextPlayer() {
	return nextPlayer;
}

void StateNode::setNextPlayer(int player) {
	nextPlayer = player;
}

long StateNode::getExpandValue() {
	if(winnerFlag!=0 || getBestMoves()->size()==children->size()) {
		return -2100000000;
	}
	return getRecursiveValue()/(getLevel()+children->size());
}

void StateNode::setExpandValue(long eValue) {
	expandValue = eValue;
}

vector<StateNode*>* StateNode::getChildren() {
	return children;
}


