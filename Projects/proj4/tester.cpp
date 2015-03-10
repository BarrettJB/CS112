/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student: Barrett Bryson, Kristofer Brink
 * Date: 3/9/2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "VecTester.h"
#include "MatrixTester.h"

void getTwo(Matrix<double>& m1, Matrix<double>& m2) {
	cout << "Enter name of first Matrix file(m1): " << flush;
	string file;
	cin >> file;
	m1.readFrom(file);
	cout << "Enter name of second Matrix file(m2): " << flush;
	cin >> file;
	m2.readFrom(file);
}

int main() {
	//	VecTester vt;
	//	vt.runTests();
	cout << "Enter 1 to run tests, or 0 to continue: " << flush;
	int answer;
	cin >> answer;
	if (answer == 1){
		MatrixTester mt;
		mt.runTests();
	}
	cout << '\n' << '\n' << '\n' << '\n' << '\n' << endl;
	cout << "Welcome to the Matrix Application" << endl;
	bool quit = false;
	do {
		cout << "Operations:" << endl;
		cout << " 1---Addition" << endl;
		cout << " 2---Subtraction" << endl;
		cout << " 3---Multiplication" << endl;
		cout << " 4---Transpose" << endl;
		cout << " 0---Quit" << endl;
		cout << "Please select an operation: " << flush;
		int response;
		cin >> response;

		if (response == 1) {
			Matrix<double> m1;
			Matrix<double> m2;
			Matrix<double> m3;
			getTwo(m1,m2);
			m3 = m1 + m2;
			cout << "\nm1 + m2 =" << endl;
			m3.writeTo(cout);
			cout << endl;
		}

		if (response == 2) {
			Matrix<double> m1;
			Matrix<double> m2;
			Matrix<double> m3;
			getTwo(m1,m2);
			m3 = m1 - m2;
			cout << "\nm1 - m2 =" << endl;
			m3.writeTo(cout);
			cout << endl;
		}

		if (response == 3) {
			Matrix<double> m1;
			Matrix<double> m2;
			Matrix<double> m3;
			getTwo(m1,m2);
			m3 = m1 * m2;
			cout << "\nm1 * m2 =" << endl;
			m3.writeTo(cout);
			cout << endl;
		}

		if (response == 4) {
			Matrix<double> m1;
			cout << "Enter name of Matrix file: " << flush;
			string file;
			cin >> file;
			m1.readFrom(file);
			Matrix<double> m3;
			m3 = m1.getTranspose();
			cout << "\nm1 transposed is:" << endl;
			m3.writeTo(cout);
			cout << endl;
		}

		if (response == 0) {
			quit = true;
		}
	} while (!quit);
	cout << "Goodbye" << flush;
}
