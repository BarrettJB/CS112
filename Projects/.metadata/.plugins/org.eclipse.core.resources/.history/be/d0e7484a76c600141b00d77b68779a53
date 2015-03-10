/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

template <class Item>
class Vec {
public:
	Vec();
	Vec(unsigned);
	Vec(const Vec& original);
	virtual ~Vec();
	unsigned getSize() const {return mySize;};
	Item* getPtr() {return myArray;};
	Vec& operator= (const Vec& original);
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator== (const Vec& v2) const;
	bool operator!= (const Vec& v2) const;
	void writeTo(ostream& out) const;
	Vec operator+ (const Vec& add);
	Vec operator- (const Vec& v2);
	Item operator* (const Vec& add);
	void readFrom(istream& in);
	void readFrom(const string& filename);
	void writeTo(const string& filename);
	Item operator[](const unsigned& Index) const;
	Item& operator[](const unsigned& Index);
	
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

template <class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

template <class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
}

template <class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

template <class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	myArray = new Item[mySize];
	if (original.myArray == NULL) myArray = NULL;
	Item* oldptr = original.myArray;
	for (unsigned i = 0; i < mySize; i++){
		myArray[i] = *oldptr;
		oldptr++;
	}
}

template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (this != &original){
		if (mySize != original.mySize) {
			if (mySize > 0){
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0){
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		Item * originalArrayPtr = original.myArray;
		for (unsigned i = 0; i < mySize; i++){
			myArray[i] = *originalArrayPtr;
			originalArrayPtr++;
		}
	}
	return *this;
}

template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index < mySize){
		myArray[index] = it;
	}
	else {
		throw range_error("Invalid Index");
	}
}

template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index < mySize){
		return myArray[index];
	}
	else {
		throw range_error("Invalid Index");
	}
}

template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize){
		if (newSize == 0){
			mySize = 0;
			delete [] myArray;
			myArray = NULL;
		}
		else {
			Item* newArray = new Item[newSize];
			if (newSize > mySize){
				for (unsigned i = 0; i < mySize; i++){
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++){
					newArray[i] = 0;
				}
			}
			else {
				for (unsigned i = 0; i < newSize; i++){
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

template <class Item>
bool Vec<Item>::operator==(const Vec& v2) const{
	if (mySize != v2.getSize()){
		return false;
	}
	else{
		for (unsigned i = 0; i < mySize; i++){
			if (myArray[i] != v2.myArray[i]){
				return false;
			}
		}
	}
	return true;
}

template <class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const{
	return !(*this==v2);
}

template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++){
		out << myArray[i] << '\t';
	}
	out << endl;
}

template <class Item>
void Vec<Item>::readFrom(istream& in){
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

template <class Item>
Vec<Item> Vec<Item>::operator+ (const Vec<Item>& add){
	Vec sum(mySize);
	if (mySize != add.mySize){
		throw invalid_argument("Invalid Index");
	}
	else {
		for (unsigned i = 0; i < mySize; i++) {
			sum.myArray[i] = (myArray[i] + add.myArray[i]);
		}

	}
	return sum;
}

template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2){
	Vec output(mySize);
	if (mySize != v2.mySize){
		throw invalid_argument("Invalid Index");
	}
	else {
		for (unsigned i = 0; i < mySize; i++) {
			output.myArray[i] = (myArray[i] - v2.myArray[i]);
		}

	}
	return output;
}

template <class Item>
Item Vec<Item>::operator* (const Vec<Item>& dotproduct){
	Item result = 0;
	if (mySize != dotproduct.mySize){
		throw invalid_argument("Invalid Index");
	}
	else {
		for (unsigned i = 0; i < mySize; i++) {
			result += (myArray[i] * dotproduct.myArray[i]);
		}

	}
	return result;
}

template <class Item>
void Vec<Item>::readFrom(const string& filename){
	if (myArray != NULL || mySize !=0){
		delete []myArray;
		myArray = NULL;
		mySize = 0;
	}
	ifstream fin(filename.c_str());
	unsigned size;
	fin >> size;
	mySize = size;
	myArray = new Item[mySize];
	Vec vtmp(size);
	vtmp.readFrom(fin);
	for (unsigned i = 0; i < size; i++) {
		myArray[i] = vtmp.myArray[i];
	}
	fin.close();
}

template <class Item>
void Vec<Item>::writeTo(const string& filename){
	ofstream fout(filename.c_str());
	fout << mySize << "\n";
	Vec<Item> temp(mySize);
	writeTo(fout);
	fout.close();
}

template <class Item>
Item& Vec<Item>::operator[](const unsigned& index){
	if (index < mySize) {
		return myArray[index];
	}
	else {
		throw range_error("Invalid Index");
	}
}

template <class Item>
Item Vec<Item>::operator[](const unsigned& index) const{
	if (index < mySize) {
		return myArray[index];
	}
	else {
		throw range_error("Invalid Index");
	}
}

#endif /*VEC_H_*/
