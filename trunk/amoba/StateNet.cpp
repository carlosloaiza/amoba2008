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
	analyzer = new Analyzer();
}

StateNet::~StateNet() {
	// TODO Auto-generated destructor stub
}

void StateNet::setActState(NumMatrix<int>* state) {
	actState = state;
	clean();
	actNode = createNode(state, 2);
	actNode->setLevel(1);
	actNode->setNextPlayer(2);
	analyzer->calculate(actNode);
	expand();
}

std::string StateNet::getNextStep() {
	int max=0;
	for(int i = 0; i<actNode->getChildren()->size();i++) {
		if(actNode->getChildren()->at(i)->getWinnerFlag()==2) {
			return actNode->getBestMoves()->at(i);
		}
		if(actNode->getChildren()->at(i)->getRecursiveValue()>actNode->getChildren()->at(max)->getRecursiveValue()) {
			max = i;
		}
	}
	return actNode->getBestMoves()->at(max);
}

void StateNet::clean() {
cout << "*******CLEAN START*******"<<nodes.size()<<"\n";
	for(int i=0; i<nodes.size(); i++) {
		if(!actState->isReachable(nodes.at(i)->getState())) {
			nodes.erase(nodes.begin()+i);
			nodeHashes.erase(nodeHashes.begin()+i);
		}
	}
cout << "********CLEAN END********"<<nodes.size()<<"\n";
}
StateNode* StateNet::createNode(NumMatrix<int>* state, int player) {
	string hash = state->getHash();

	for(int i=0;i<nodes.size();i++) {
		if(nodeHashes.at(i)==hash) {
			return nodes.at(i);
		}
	}

	StateNode* sn = new StateNode();
	sn->setState(state);
	sn->setNextPlayer(player);
	bool ins = false;
	for(int i=0;i<nodes.size();i++) {
		if(nodeHashes.at(i)>hash) {
			nodes.insert(nodes.begin()+i, sn);
			nodeHashes.insert(nodeHashes.begin()+i, hash);
			ins = true;
			break;
		}
	}
	if(!ins) {
		nodes.push_back(sn);
		nodeHashes.push_back(state->getHash());
	}
	analyzer->calculate(sn);
	return sn;
}

void StateNet::expand() {
	int max = 0;
	int maxValue = -2100000000;
	int childNum = 0;
	int breakLoop = 0;
	while(nodes.size()<1000) {
		max = 0;
		maxValue = -2100000000;
		for(int i=0;i<nodes.size();i++) {
			if(nodes.at(i)->getExpandValue()>maxValue) {
				max = i;
				maxValue = nodes.at(i)->getExpandValue();
			}
		}
		childNum = nodes.size();
		createChild(nodes.at(max));
		if(childNum == nodes.size()) {breakLoop++;} else {breakLoop = 0;}
		if(breakLoop>10) {break;}
	}
	for(int i=0;i<nodes.size();i++) {
//		nodes.at(i)->printInfo();
	}
}

void StateNet::createChild(StateNode* sn) {
	NumMatrix<int>* state = sn->getState()->clone();
	vector<string>* v = sn->getBestMoves();
	string order = v->at(sn->getChildren()->size());
	state = applyOrder(state, order, sn->getNextPlayer());
	StateNode* node = createNode(state, sn->getNextPlayer()==2?1:2);
	sn->addChild(node);
	analyzer->calculate(node);
}

NumMatrix<int>* StateNet::applyOrder(NumMatrix<int>* state, string order, int player) {
    std::stringstream ss;
    char temp;
    ss<<order;
    int i, j;
    ss>>i;
    ss>>temp;
    ss>>j;
    state->setCell(i, j, player);
    return state;
}

Analyzer* StateNet::getAnalyzer() {
	return analyzer;
}
