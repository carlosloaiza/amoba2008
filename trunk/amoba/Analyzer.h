/*
 * Analyzer.h
 *
 *  Created on: 2008.12.06.
 *      Author: bacsog
 */

#ifndef ANALYZER_H_
#define ANALYZER_H_

#define VALUE1  2000000000
#define VALUE2  976744
#define VALUE3  716345
#define VALUE4  491376
#define VALUE5  315606
#define VALUE6  187453
#define VALUE7  108550
#define VALUE8  67215
#define VALUE9  39761
#define VALUE10 25433

#include <vector>
#include <iostream>
#include <sstream>
#include "StateNode.h"
#include "NumMatrix.h"

using namespace std;

class Analyzer {
public:
	Analyzer();
	virtual ~Analyzer();

	void calculate(StateNode* stateNode, int p);
	int isTerminated(NumMatrix<int>* state);

private:

	StateNode* actNode;
	NumMatrix<int>* act;
	NumMatrix<int>* myValues;
	NumMatrix<int>* opValues;
	NumMatrix<int>* signCells;
	int myValue;
	int opValue;
	int pn;
	bool haveEmptyCell;

	void init();
	void considerValue();
	void setStateNode();
	int ValueUP(int i, int j, int player);
	int ValueRIGHTUP(int i, int j, int player);
	int ValueRIGHT(int i, int j, int player);
	int ValueRIGHTDOWN(int i, int j, int player);
	int ValueDOWN(int i, int j, int player);
	int ValueLEFTDOWN(int i, int j, int player);
	int ValueLEFT(int i, int j, int player);
	int ValueLEFTUP(int i, int j, int player);
	int getValue(int i, int j, int a, int b, int player);

	int isTerminated();

};

#endif /* ANALYZER_H_ */
