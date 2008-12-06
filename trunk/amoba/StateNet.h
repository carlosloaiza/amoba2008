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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StateNet {
public:
	StateNet();
	virtual ~StateNet();
	void setActState(NumMatrix<int>* state);
	std::string getNextStep();

private:
	void clear();
	StateNode* createNode(NumMatrix<int>* state);
	vector<StateNode*> nodes();
	vector<string> nodeHashes();
	NumMatrix<int>* actState;
};

#endif /* STATENET_H_ */
