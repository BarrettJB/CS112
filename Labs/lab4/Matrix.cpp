/* Matrix.cpp defines Matrix class methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}

}

const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index < myRows) {
		return myVec[index];
	}
	else {
		throw range_error("Invalid Index");
	}
}

Vec<Item>& Matrix::operator[](unsigned index) {
	if (index < myRows) {
		return myVec[index];
	}
	else {
		throw range_error("Invalid Index");
	}
}

bool Matrix::operator==(const Matrix& m2) const {
   if ( myRows != m2.myRows || myColumns != m2.myColumns ) {
        return false;
   }
   else {
        return myVec == m2.myVec;
   }
}
