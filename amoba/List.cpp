/*
 * List.cpp
 *
 *  Created on: 2008.10.16.
 *      Author: bacsog
 */

#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;


List::List() {
	head = new Node(-1,0);
}

List::~List() {
	Node* akt = head;
	Node* tmp = akt;
	while(akt->nextp!=0) {
		tmp = akt;
		akt = akt->nextp;
		delete tmp;
	}
	delete akt;
}

void List::add(int s) {
	Node* akt = head;
	while(akt->nextp!=0) {
		if(akt->nextp->entry > s) {
			akt->nextp = new Node(s, akt->nextp);
			return;
		}
		akt = akt->nextp;
	}
	akt->nextp = new Node(s, 0);
}

void List::printList() {
	Node* akt = head;
	int i = 1;
	while(akt->nextp!=0) {
		akt = akt->nextp;
		cout << i++ << ".: " << akt->entry << ((akt->nextp!=0)?", ":".\n");
	}
}

int List::elementAt(int index) {
	Node* akt = head;
	int i = 0;
	while(akt->nextp!=0) {
		akt = akt->nextp;
		if(i==index) {
			return akt->entry;
		} else {i++;}
	}
	return -1;
}

void List::remove(int index) {
	Node* akt = head;
	Node* tmp = akt;
	int i = 0;
	while(akt->nextp!=0) {
		tmp = akt->nextp;
		if(i==index) {
			akt->nextp = akt->nextp->nextp;
			delete tmp;
			return;
		} else {i++;}
		akt = akt->nextp;
	}
}

bool List::isEmpty() {
	return elementAt(0) == -1;
}
