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

	StateNode* clone();
	NumMatrix<int>* getState();
	void setMyValue(int i);
	void setOpValue(int i);
	void setState(NumMatrix<int>* newState);
	vector<string>* getBestMoves();
	void setBestMoves(vector<string>* orders);
	void setWinnerFlag(int i);
	void notifyWinnerFlag(int flag);

private:
	NumMatrix<int>* state;
	int winnerFlag;
	int myWinnerChild;
	int opWinnerChild;
	long myValue;
	long opValue;
	int level;
	int nextPlayer;
	vector<StateNode*>* parents;
	vector<StateNode*>* children;
	vector<string>* bestMoves;

};

#endif /* STATENODE_H_ */
