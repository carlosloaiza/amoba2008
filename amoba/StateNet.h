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

class StateNet {
public:
	StateNet();
	virtual ~StateNet();
	void setActState(NumMatrix<int>* state);
	std::string getNextStep();

private:
	NumMatrix<int>* actState;
};

#endif /* STATENET_H_ */
