/*
 * Node.h
 *
 *  Created on: 2008.10.16.
 *      Author: bacsog
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

struct Node {

   int entry;
   Node *nextp;

   Node();
   Node(int item, Node *add_on = 0);
};

#endif /* NODE_H_ */
