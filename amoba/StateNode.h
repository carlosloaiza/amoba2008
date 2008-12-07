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
	vector<StateNode*>* getChildren();
	void addChild(StateNode* child);
	void addParent(StateNode* parent);
	void setWinnerFlag(int i);
	void notifyWinnerFlag(int flag);
	void removeParent(StateNode* parent);
	long getRecursiveValue();
	int getLevel();
	void setLevel(int lev);
	int getNextPlayer();
	void setNextPlayer(int player);
	long getExpandValue();
	void setExpandValue(long eValue);

private:
	long getChildrenValue();
	int getChildrenNum();
	NumMatrix<int>* state;
	int winnerFlag;
	int myWinnerChild;
	int opWinnerChild;
	long myValue;
	long opValue;
	long expandValue;
	int level;
	int nextPlayer;
	long recursiveValue;
	vector<StateNode*>* parents;
	vector<StateNode*>* children;
	vector<string>* bestMoves;

};

#endif /* STATENODE_H_ */
