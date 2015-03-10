/* tester.cpp drives the testing of our Vec class.
 * Student:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "VecTester.h"
#include <iostream>

int main() {
	cout << "Enter 1 to run tests, or 0 to continue: " << flush;
	int answer;
	cin >> answer;
	if (answer == 1){
		VecTester vt;
		vt.runTests();
	}
	cout << "Enter the number of dimensions in your space: " << flush;
	unsigned dimensions;
	cin >> dimensions;
	Vec v0(dimensions);
	cout << "Enter starting vector (values separated by spaces): " << flush;
	for (unsigned i = 0; i < dimensions; i++) {
		cin >> v0[i];
	}
	cout << "Enter vectors for the pointer to traverse (aka vectors will be summed):" << endl;
	Vec v1(dimensions);
	v1 = v0;
	Vec v2(dimensions);
	unsigned numVecs = 1;
	bool quit = false;
	while (!quit) {
		cout << "Enter values for Vector number "
				<< numVecs << " (values separated by spaces): " << flush;
		for (unsigned i = 0; i < dimensions; i++) {
			cin >> v2[i];
		}
		v1 = v1 + v2;
		numVecs++;
		cout << "Would you like to enter another vector?"
				<< "y for yes, n for no : " << flush;
		string loop;
		cin >> loop;
		if (loop == "n") quit = true;
	}
	cout << "Starting point (origin): " << endl << "{";
	for (unsigned i = 0; i < dimensions; i++) {
		cout << v0.getItem(i);
		if ((dimensions - 1) != i){
			cout << ",";
		}
	}
	cout << "}" << endl << "Ending Point (sum of vectors): " << endl << "{";
	for (unsigned i = 0; i < dimensions; i++) {
		cout << v1.getItem(i);
		if ((dimensions - 1) != i){
			cout << ",";
		}
	}
	cout << "}";
}



void collapse() {
	//else{
	//
	//		cout << "Enter the number of dimensions in your space: " << flush;
	//		unsigned dimensions;
	//		cin >> dimensions;
	//		Vec v0(dimensions);
	//
	//		if (dimensions == 1 || 2 || 3){
	//			cout << "Enter the starting x coordinate of your space: " << flush;
	//			Item x0;
	//			cin >> x0;
	//			v0.setItem(0, x0);
	//
	//		}
	//
	//		if (dimensions == 2 || 3){
	//			cout << "Enter the starting y coordinate of your space: " << flush;
	//			Item y0;
	//			cin >> y0;
	//			v0.setItem(1,y0);
	//		}
	//
	//		if (dimensions == 3){
	//			cout << "Enter the starting z coordinate of your space: " << flush;
	//			Item z0;
	//			cin >> z0;
	//			v0.setItem(2, z0);
	//		}
	//
	//		cout << "Enter vectors for the pointer to traverse (aka vectors will be summed):" << endl;
	//		Vec v1(dimensions);
	//		v1 = v0;
	//		Vec v2(dimensions);
	//		bool HELLO = true;
	//		while (HELLO == true){
	//
	//			if (dimensions == 1 || 2 || 3){
	//				cout << "Enter the x value to shift by: " << flush;
	//				Item x0;
	//				cin >> x0;
	//				v2.setItem(0, x0);
	//
	//			}
	//
	//			if (dimensions == 2 || 3){
	//				cout << "Enter the y value to shift by: " << flush;
	//				Item y0;
	//				cin >> y0;
	//				v2.setItem(1, y0);
	//			}
	//
	//			if (dimensions == 3){
	//				cout << "Enter the z value to shift by: " << flush;
	//				Item z0;
	//				cin >> z0;
	//				v2.setItem(2, z0);
	//			}
	//
	//			v1 = v1 + v2;
	//
	//			cout << "would you like to enter more vectors? 'Y' to continue 'N' to stop: " << flush;
	//			string loop;
	//			cin >> loop;
	//			if (loop == "N") HELLO = false;
	//		}
	//
	//		cout << "Starting point (origin): " << endl << "{";
	//		for (unsigned i = 0; i < dimensions; i++) {
	//			cout << v0.getItem(i);
	//			if ((dimensions - 1) != i){
	//				cout << ",";
	//			}
	//		}
	//		cout << "}" << endl << "Ending Point (sum of vectors): " << endl << "{";
	//		for (unsigned i = 0; i < dimensions; i++) {
	//			cout << v1.getItem(i);
	//			if ((dimensions - 1) != i){
	//				cout << ",";
	//			}
	//		}
	//		cout << "}";
	//	}
}

