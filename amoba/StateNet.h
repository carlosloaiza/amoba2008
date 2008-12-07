/*
 * StateNet.h
 *
 *  Created on: 2008.12.06.
 *      Author: bacsog
 */

#ifndef STATENET_H_
#define STATENET_H_

#include "StateNode.h"
#include "NumMatrix.h"
#include "Analyzer.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class StateNet {
public:
	StateNet();
	virtual ~StateNet();
	void setActState(NumMatrix<int>* state);
	std::string getNextStep();
	Analyzer* getAnalyzer();
	StateNode* createNode(NumMatrix<int>* state, int player);
	void expand();

private:
	void clean();
	NumMatrix<int>* applyOrder(NumMatrix<int>* state, string order, int player);
	void createChild(StateNode* sn);
	vector<StateNode*> nodes;
	vector<string> nodeHashes;

	NumMatrix<int>* actState;
	StateNode* actNode;
	Analyzer* analyzer;

};

#endif /* STATENET_H_ */
