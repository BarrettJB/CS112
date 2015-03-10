/*
 * List.h
 *
 *  Created on: Mar 10, 2015
 *      Author: bb36
 */

#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>
#include <iostream>
using namespace std;


typedef double Item;

class List {
public:
	List();
	List(const List& original);
	virtual ~List();
	unsigned getSize() const { return mySize; };
	Item getFirst() const;
	Item getLast() const;
	void append(Item it);
	List& operator=(const List& original);
private:
	struct Node {
		Item myItem;
		Node* myNext;
		Node();
		Node(Item item,Node* next);
		virtual ~Node();
	};
	Node* myFirst;
	Node* myLast;
	unsigned mySize;
	friend class ListTester;
};

#endif /* LIST_H_ */
