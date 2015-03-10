/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize != 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; i++){
			*(myArray+i) = *(original.myArray+i);
		}
	}
	else {
		myArray = NULL;
	}
}

Vec& Vec::operator=(const Vec& original) {
	if (myArray != original.myArray) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; i++){
			*(myArray+i) = *(original.myArray+i);
		}
	}
	return *this;
}

unsigned Vec::getSize() const{
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (mySize > index) {
		myArray[index] = it;
	}
	else {
		throw range_error("index is larger than size");
	}
}

Item Vec::getItem(unsigned index) const{
	if (mySize > index) {
		return myArray[index];
	}
	else {
		throw range_error("index is larger than size");
	}
}

void Vec::setSize(unsigned newSize) {
	if (newSize == 0) {
		delete [] myArray;
		myArray = NULL;
		mySize = newSize;
	}
	if (newSize != mySize) {
		Item *newArray = new Item[newSize];
		if (mySize < newSize) {
			for (unsigned i = 0; i < mySize; i++) {
				newArray[i] = myArray[i];
			}
			for (unsigned i = mySize; i < newSize; i++) {
				newArray[i] = 0;
			}
		}
		else {
			for (unsigned i = 0; i < newSize; i++) {
				newArray[i] = myArray[i];
			}
		}
		delete [] myArray;
		myArray = newArray;
		mySize = newSize;
	}

}

bool Vec::operator==(const Vec& v2){
	bool output = true;
	if (mySize == v2.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				output = false;
			}
		}
	}
	else {
		output = false;
	}
	return output;
}

void Vec::writeTo (ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

void Vec::readFrom (istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray [i];
	}
}

Vec::~Vec() {
	mySize = 0;
	delete [] myArray;
	myArray = NULL;
}
