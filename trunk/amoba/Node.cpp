/*
 * Node.cpp
 *
 *  Created on: 2008.10.08.
 *      Author: bacsog
 */

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
	nextp = 0;
}

Node::Node(int item, Node *add_on) {
	entry = item;
	nextp = add_on;
}

