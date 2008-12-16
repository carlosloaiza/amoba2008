/*
 * Analyzer.h
 *
 *  Created on: 2008.12.16.
 *      Author: bacsog
 */

#ifndef ANALYZER_H_
#define ANALYZER_H_

#define VALUE1  2000000000
#define VALUE2  97674416
#define VALUE3  71634508
#define VALUE4  49137654
#define VALUE5  31560629
#define VALUE6  18745355
#define VALUE7  10855060
#define VALUE8  6721560
#define VALUE9  3976113
#define VALUE10 2543300

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

	void calculate(StateNode* stateNode);
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
