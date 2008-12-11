/*
 * Analyzer.cpp
 *
 *  Created on: 2008.12.06.
 *      Author: bacsog
 */

#include "Analyzer.h"

Analyzer::Analyzer() {
	myValues = new NumMatrix<int>();
	opValues = new NumMatrix<int>();
	signCells = new NumMatrix<int>();
	srand(time(NULL));
}

Analyzer::~Analyzer() {
}

void Analyzer::calculate(StateNode* state) {
	actNode = state;
	act = state->getState();
	pn = actNode->getNextPlayer();
	init();
	considerValue();
	setStateNode();
}

void Analyzer::init() {
	myValue = opValue = 0;
	haveEmptyCell = false;
	for(int i=0;i<myValues->getSize();i++) {
		for(int j=0;j<myValues->getSize();j++) {
			myValues->setCell(i, j, 0);
			opValues->setCell(i, j, 0);
			signCells->setCell(i, j, 0);
		}
	}
}

void Analyzer::considerValue() {
	if(isTerminated()) {
		return;
	}
    haveEmptyCell = false;
    for(int i=0; i<act->getSize(); i++) {
        for(int j=0; j<act->getSize(); j++) {
        	if(haveEmptyCell || act->getCell(i, j) == 0) {haveEmptyCell = true;}
            if( act->getCell(i, j) == 0 &&

               (act->getCell(i-1, j)>0 ||
                act->getCell(i-1, j-1)>0 ||
                act->getCell(i-1, j-2)>0 ||
                act->getCell(i-1, j+1)>0 ||
                act->getCell(i-1, j+2)>0 ||

                act->getCell(i-2, j)>0 ||
                act->getCell(i-2, j-1)>0 ||
                act->getCell(i-2, j-2)>0 ||
                act->getCell(i-2, j+1)>0 ||
                act->getCell(i-2, j+2)>0 ||

                act->getCell(i+1, j)>0 ||
                act->getCell(i+1, j-1)>0 ||
                act->getCell(i+1, j-2)>0 ||
                act->getCell(i+1, j+1)>0 ||
                act->getCell(i+1, j+2)>0 ||

                act->getCell(i+2, j)>0 ||
                act->getCell(i+2, j-1)>0 ||
                act->getCell(i+2, j-2)>0 ||
                act->getCell(i+2, j+1)>0 ||
                act->getCell(i+2, j+2)>0 ||

                act->getCell(i, j-1)>0 ||
                act->getCell(i, j-2)>0 ||
                act->getCell(i, j+1)>0 ||
                act->getCell(i, j+2)>0

                )) {
                signCells->setCell(i, j, 1);
            } else {signCells->setCell(i, j, 0);}
        }
    }

    myValue = 0;
    opValue = 0;
    int opNumber = pn==1?2:1;
    for(int i=0; i<act->getSize(); i++) {
        for(int j=0; j<act->getSize(); j++) {
            if(signCells->getCell(i,j)) {
                myValues->setCell(i,j, ValueUP(i, j, pn) +
                                    ValueRIGHTUP(i, j, pn) +
                                    ValueRIGHT(i, j, pn) +
                                    ValueRIGHTDOWN(i, j, pn) +
                                    ValueDOWN(i, j, pn) +
                                    ValueLEFTDOWN(i, j, pn) +
                                    ValueLEFT(i, j, pn) +
                                    ValueLEFTUP(i, j, pn)
								 );
                opValues->setCell(i,j, ValueUP(i, j, opNumber) +
                                    ValueRIGHTUP(i, j, opNumber) +
                                    ValueRIGHT(i, j, opNumber) +
                                    ValueRIGHTDOWN(i, j, opNumber) +
                                    ValueDOWN(i, j, opNumber) +
                                    ValueLEFTDOWN(i, j, opNumber) +
                                    ValueLEFT(i, j, opNumber) +
                                    ValueLEFTUP(i, j, opNumber)
                                  );

                myValue += myValues->getCell(i, j);
                opValue += opValues->getCell(i, j);
            }
        }
    }
}

int Analyzer::ValueUP       (int i, int j, int pn){ return getValue(i, j, -1,  0, pn); }
int Analyzer::ValueLEFTUP   (int i, int j, int pn){ return getValue(i, j, -1, -1, pn); }
int Analyzer::ValueRIGHTUP  (int i, int j, int pn){ return getValue(i, j, -1,  1, pn); }
int Analyzer::ValueDOWN     (int i, int j, int pn){ return getValue(i, j,  1,  0, pn); }
int Analyzer::ValueLEFTDOWN (int i, int j, int pn){ return getValue(i, j,  1, -1, pn); }
int Analyzer::ValueRIGHTDOWN(int i, int j, int pn){ return getValue(i, j,  1,  1, pn); }
int Analyzer::ValueLEFT     (int i, int j, int pn){ return getValue(i, j,  0, -1, pn); }
int Analyzer::ValueRIGHT    (int i, int j, int pn){ return getValue(i, j,  0,  1, pn); }

int Analyzer::getValue(int i, int j, int a, int b, int player) {
    int op = player==1?2:1;
    int r_value = 0;

    if(act->getCell(i-1*a, j-1*b)==op && (act->getCell(i+1*a, j+1*b)==op || act->getCell(i+2*a, j+2*b)==op || act->getCell(i+3*a, j+3*b)==op || act->getCell(i+4*a, j+4*b)==op)) {
        return 0;
    }
    if(act->getCell(i-2*a, j-2*b)==op &&(act->getCell(i+2*a, j+2*b)==op || act->getCell(i+3*a, j+3*b)==op)) {
        return 0;
    }



///*****************************MINTÁK*****************************
    if(act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE8;
        if(act->getCell(i-2*a, j-2*b)==op || act->getCell(i+1*a, j+1*b)==op) {r_value = int(r_value/2);}
        if(act->getCell(i-3*a, j-3*b)==op || act->getCell(i+2*a, j+2*b)==op) {r_value = int(2*r_value/3);}
        if(act->getCell(i-4*a, j-4*b)==op || act->getCell(i+3*a, j+3*b)==op) {r_value = int(3*r_value/4);}
        if(act->getCell(i-5*a, j-5*b)==op || act->getCell(i+4*a, j+4*b)==op) {r_value = int(4*r_value/5);}
    }

    if(act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE5;
        if(act->getCell(i-3*a, j-3*b)==op || act->getCell(i+2*a, j+2*b)==op) {r_value = int(  r_value/2);}
        if(act->getCell(i-4*a, j-4*b)==op || act->getCell(i+3*a, j+3*b)==op) {r_value = int(2*r_value/3);}
        if(act->getCell(i-5*a, j-5*b)==op || act->getCell(i+4*a, j+4*b)==op) {r_value = int(3*r_value/4);}
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE2;
        if(act->getCell(i-4*a, j-4*b)==op || act->getCell(i+1*a, j+1*b)==op) {r_value = int(2*VALUE4/3);}
    }

    if(act->getCell(i-4*a, j-4*b)==player && act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE1;
    }

    if(act->getCell(i-1*a, j-1*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE5;
        if(act->getCell(i-2*a, j-2*b)==op || act->getCell(i+2*a, j+2*b)==op) {r_value = int(r_value/2);}
        if(act->getCell(i-3*a, j-3*b)==op && act->getCell(i+3*a, j+3*b)==op) {r_value = int(2*r_value/3);}
    }

    if(act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE2;
        if(act->getCell(i-3*a, j-3*b)==op || act->getCell(i+2*a, j+2*b)==op) {r_value = VALUE3;}
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE1;
    }

    if(act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player && act->getCell(i+1*a, j+1*b)==player && act->getCell(i+2*a, j+2*b)==player) {
        r_value += VALUE1;
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==0  && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE5;
        if(act->getCell(i-4*a, j-4*b)==op || act->getCell(i+1*a, j+1*b)==op) {r_value = VALUE6;}
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==0 ) {
        r_value += VALUE5;
        if(act->getCell(i-4*a, j-4*b)==op || act->getCell(i+1*a, j+1*b)==op) {r_value = VALUE6;}
    }

    if(act->getCell(i-4*a, j-4*b)==player && act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==0 ) {
        r_value += VALUE6;
    }

    if(act->getCell(i-4*a, j-4*b)==player && act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==0  && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE6;
    }

    if(act->getCell(i-4*a, j-4*b)==player && act->getCell(i-3*a, j-3*b)==0  && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE6;
    }

    if(act->getCell(i-4*a, j-4*b)==0  && act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player) {
        r_value += VALUE6;
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE6;
    }

    if(act->getCell(i-2*a, j-2*b)==player && act->getCell(i-1*a, j-1*b)==player && act->getCell(i+2*a, j+2*b)==player) {
        r_value += VALUE5;
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-1*a, j-1*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE5;
    }

    if(act->getCell(i-3*a, j-3*b)==player && act->getCell(i-2*a, j-2*b)==player && act->getCell(i+1*a, j+1*b)==player) {
        r_value += VALUE5;
    }

    return r_value;
}

void Analyzer::setStateNode() {
	actNode->setMyValue(myValue);
	actNode->setOpValue(opValue);
	int term = isTerminated();
	if(term!=0) {
		actNode->setWinnerFlag(term);
		actNode->setMyValue(term==pn?2100000000:-2100000000);
	    vector<string>* orders = new vector<string>();
	    orders->push_back("end");
		return;
	}

    vector<string>* orders = new vector<string>();
    vector<int>* values = new vector<int>();

    for(int i=0; i<act->getSize(); i++) {
        for(int j=0; j<act->getSize(); j++) {
            if(signCells->getCell(i, j)==1) {
            	if(myValues->getCell(i, j)==0 && opValues->getCell(i, j)==0) {continue;}
            	stringstream ss;
            	ss<< i << ";" << j;
            	orders->push_back(ss.str());
            	int cellValue = int(1.15 * abs(myValues->getCell(i, j))+abs(opValues->getCell(i, j))+rand()%20);
                if(cellValue<0) { cellValue = -cellValue;}
                if(cellValue<-2147483000) { cellValue = 2147483000;}
            	values->push_back(cellValue);
            }
        }
    }
    bool isOrdered = false;
    string string_temp;
    int int_temp = 0;
    while(!isOrdered) {
        isOrdered = true;
        for(int i=0; i<values->size()-1; i++) {
            if(values->at(i)<values->at(i+1)) {
                isOrdered = false;

                int_temp = values->at(i);
                values->at(i) = values->at(i+1);
                values->at(i+1) = int_temp;
                string_temp = orders->at(i);
                orders->at(i) = orders->at(i+1);
                orders->at(i+1) = string_temp;
            }
        }
    }
//    for(int i=0; i<orders->size();i++) {cout << orders->at(i) << "\n";}
    orders->erase(orders->begin()+6, orders->end());
    actNode->setBestMoves(orders);
}

int Analyzer::isTerminated() {return isTerminated(act);}

int Analyzer::isTerminated(NumMatrix<int>* a) {
	for(int i=0; i<a->getSize(); i++) {
		for(int j=0; j<a->getSize(); j++) {
			if(a->getCell(i, j)==1 && a->getCell(i+1, j)==1 && a->getCell(i+2, j)==1 && a->getCell(i+3, j)==1 && a->getCell(i+4, j)==1) {
				return 1;
			}
			if(a->getCell(i, j)==1 && a->getCell(i, j+1)==1 && a->getCell(i, j+2)==1 && a->getCell(i, j+3)==1 && a->getCell(i, j+4)==1) {
				return 1;
			}
			if(a->getCell(i, j)==1 && a->getCell(i+1, j+1)==1 && a->getCell(i+2, j+2)==1 && a->getCell(i+3, j+3)==1 && a->getCell(i+4, j+4)==1) {
				return 1;
			}
			if(a->getCell(i, j)==1 && a->getCell(i+1, j-1)==1 && a->getCell(i+2, j-2)==1 && a->getCell(i+3, j-3)==1 && a->getCell(i+4, j-4)==1) {
				return 1;
			}

			if(a->getCell(i, j)==2 && a->getCell(i+1, j)==2 && a->getCell(i+2, j)==2 && a->getCell(i+3, j)==2 && a->getCell(i+4, j)==2) {
				return 2;
			}
			if(a->getCell(i, j)==2 && a->getCell(i, j+1)==2 && a->getCell(i, j+2)==2 && a->getCell(i, j+3)==2 && a->getCell(i, j+4)==2) {
				return 2;
			}
			if(a->getCell(i, j)==2 && a->getCell(i+1, j+1)==2 && a->getCell(i+2, j+2)==2 && a->getCell(i+3, j+3)==2 && a->getCell(i+4, j+4)==2) {
				return 2;
			}
			if(a->getCell(i, j)==2 && a->getCell(i+1, j-1)==2 && a->getCell(i+2, j-2)==2 && a->getCell(i+3, j-3)==2 && a->getCell(i+4, j-4)==2) {
				return 2;
			}
		}
	}
	return 0;
}
