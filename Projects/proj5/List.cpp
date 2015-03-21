/*
 * List.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: bb36
 */

#include "List.h"
#include <stdexcept>

List::List() {
	myFirst = NULL;
	myLast = NULL;
	mySize = 0;

}

List::List(const List& original) {
	myFirst = myLast = NULL;          //  set pointers
	mySize = 0;                       //   and size to 'empty' values
	if (original.getSize() > 0) {     //  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {         //  while there are more nodes:
			append(oPtr->myItem);       //   append the item in that node
			oPtr = oPtr->myNext;        //   advance to next node
		}
	}

}

Item List::getFirst() const {
	if (myFirst == NULL || mySize == 0) {
		throw std::underflow_error("Pointer is NULL");
	}
	return myFirst->myItem;
}

Item List::getLast() const {
	if (myLast == NULL || mySize == 0) {
		throw std::underflow_error("Pointer is NULL");
	}
	return myLast->myItem;
}

void List::append(Item it) {
	Node * nodePtr = new Node(it,NULL);
	if(mySize == 0 || myFirst == NULL) {
		myFirst = nodePtr;
	}
	else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize++;
}

void List::prepend(Item it) {
	Node * nodePtr = new Node(it,myFirst);
	if(mySize == 0 || myFirst == NULL) {
		myLast = nodePtr;
	}
	myFirst = nodePtr;
	mySize++;
}

List& List::operator=(const List& original) {
	if (this != &original) {
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* oPtr = original.myFirst; //  start at the first node
			while (oPtr != NULL) {         //  while there are more nodes:
				append(oPtr->myItem);       //   append the item in that node
				oPtr = oPtr->myNext;

			}
		}
	}
	return *this;
}

bool List::operator==(const List& l2) const{
	if (mySize != l2.mySize) {
		return false;
	}
	else {
		Node* test1Ptr = myFirst;
		Node* test2Ptr = l2.myFirst;
		while (test1Ptr != NULL) {
			if (test1Ptr->myItem != test2Ptr->myItem) {
				return false;
			}
			test1Ptr = test1Ptr->myNext;
			test2Ptr = test2Ptr->myNext;
		}
	}
	return true;
}

void List::readFrom(istream& in) {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
	Item input;
	in >> input;
	while (in != NULL) {
		this->append(input);
		in >> input;
	}
}

void List::writeTo(string fileName) const {
	ofstream fout(fileName.c_str());
	Node * nodePtr = myFirst;
	while (nodePtr != NULL) {
		fout << nodePtr->myItem << " ";
		nodePtr = nodePtr->myNext;
	}

}

int List::search(Item it) const {
	Node * nodePtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		if (nodePtr->myItem == it) {
			return i;
		}
		nodePtr = nodePtr->myNext;
	}
	return -1;
}

void List::insert(Item it, unsigned index) {
	Node * nodePtr = myFirst;
	if (index == 0) {
		this->prepend(it);
	}
	else {
		if ( index == mySize) {
			this->append(it);
		}
		else {
			for (unsigned i = 1; i < index; i++) {
				nodePtr = nodePtr->myNext;
			}
			Node * insert = new Node(it,nodePtr->myNext);
			nodePtr->myNext = insert;
			mySize++;
		}
	}
}

List::~List() {
	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}


List::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

List::Node::Node(Item item,Node* next) {
	myItem = item;
	myNext = next;
}

List::Node::~Node() {
	//	cout << "~Node() is deallocating the node containing item "	<< myItem << endl;
	delete myNext;  // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)

}

