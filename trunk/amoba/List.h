/*
 * List.h
 *
 *  Created on: 2008.10.08.
 *      Author: bacsog
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

class List {

	private: Node* head;

	public: List();
	public: virtual ~List();
	public: void add(int in);
	public: void printList();
	public: int elementAt(int i);
	public: void remove(int i);
	public: bool isEmpty();
};

#endif /* LIST_H_ */
