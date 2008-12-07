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
	actNode = createNode(state);
	actNode->setLevel(1);
	actNode->setNextPlayer(2);
	analyzer->calculate(actNode, 2);
cout << "expand start\n"; cout.flush();
	expand();
cout << "expand end\n"; cout.flush();
}

std::string StateNet::getNextStep() {
//ide fog jönni egy egyszerû keresés, ami a gyökér gyerekei közül kiválasztja azt, amelyiknek
//legnagyobb a kontrollértéke - elõtte keresés wflag-re

	return actNode->getBestMoves()->at(0);
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

void StateNet::clean() {
	for(int i=0; i<nodes.size(); i++) {
		if(!actState->isReachable(nodes.at(i)->getState())) {
//			nodes.erase(nodes.begin()+i);
//			nodeHashes.erase(nodeHashes.begin()+i);
		}
	}
}
StateNode* StateNet::createNode(NumMatrix<int>* state) {
cout << "meret: " << nodes.size() << "\n";
	string hash = state->getHash();

	for(int i=0;i<nodes.size();i++) {
		if(nodeHashes.at(i)==hash) {
cout << "mar letezett ez: "<<hash<<"\n";
			return nodes.at(i);
		}
	}

	StateNode* sn = new StateNode();
	sn->setState(state);
	bool ins = false;
	for(int i=0;i<nodes.size();i++) {
		if(nodeHashes.at(i)>hash) {
cout << "beszurom ezt: "<<hash<<"\n";
			nodes.insert(nodes.begin()+i, sn);
			nodeHashes.insert(nodeHashes.begin()+i, hash);
			ins = true;
			break;
		}
	}
	if(!ins) {
cout << "beszurom ezt: "<<hash<<"\n";
		nodes.push_back(sn);
		nodeHashes.push_back(state->getHash());
	}
	return sn;
}

void StateNet::expand() {
	int max = 0;
	int maxValue = -2100000000;
	while(nodes.size()<6) {
		max = 0;
		maxValue = -2100000000;
		for(int i=0;i<nodes.size();i++) {
cout << "for: " << i << "\n"; cout.flush();
cout << "exvalue: \n"; cout.flush();
nodes.at(i)->getExpandValue();
cout << "exvalue-end: \n"; cout.flush();
			if(nodes.at(i)->getExpandValue()>maxValue) {
				max = i;
				maxValue = nodes.at(i)->getExpandValue();
			}
		}
cout << "create start:" << "\n"; cout.flush();
		createChild(nodes.at(max));
cout << "create kesz:" << "\n"; cout.flush();
	}
}

void StateNet::createChild(StateNode* sn) {
cout << "createChild start\n"; cout.flush();

	NumMatrix<int>* state = sn->getState()->clone();
	vector<string>* v = sn->getBestMoves();
	string order = v->at(sn->getChildren()->size());
	state = applyOrder(state, order, sn->getNextPlayer());
state->print();
	StateNode* node = createNode(state);
	if(node == sn) {
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
cout << "NYÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁÁ\n";
	}
	sn->addChild(node);
}

NumMatrix<int>* StateNet::applyOrder(NumMatrix<int>* state, string order, int player) {
    std::stringstream ss;
    char temp;
    ss<<order;
    int i, j;
    ss>>i;
    ss>>temp;
    ss>>j;
cout << "order: " << order <<" i: "<< i <<", j: " << j << "\n";cout.flush();
    state->setCell(i, j, player);
cout << "********change*********\n";
state->print();
cout << "********changeend*********\n";
    return state;
}

Analyzer* StateNet::getAnalyzer() {
	return analyzer;
}
