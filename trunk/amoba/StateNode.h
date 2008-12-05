/*
 * StateNode.h
 *
 *  Created on: 2008.12.05.
 *      Author: bacsog
 */

#ifndef STATENODE_H_
#define STATENODE_H_

#include "NumMatrix.h"
#include <vector>

using namespace std;

class StateNode {

public:
	StateNode();
	virtual ~StateNode();

	NumMatrix<int>* getState();
	void setState(NumMatrix<int>* newState);

	StateNode* StateNode::clone();

private:
	NumMatrix<int>* state;
	NumMatrix<int>* myValues;
	NumMatrix<int>* opValues;
	int winnerFlag;
	long myValue;
	long opValue;
	int level;
	vector<StateNode*>* parents;
	vector<StateNode*>* childs;

};

#endif /* STATENODE_H_ */
