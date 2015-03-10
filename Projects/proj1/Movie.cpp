/* Movie.cpp
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

 #include "Movie.h"

Movie::Movie() {
	myTitle = "";
	myYear = 0;
	myDirector = "";
}

Movie::Movie(const string& title, int year, const string& director) {
	myTitle = title;
	myYear = year;
	myDirector = director;
}

string Movie::getTitle() const {
	return myTitle;
}

int Movie::getYear() const {
	return myYear;
}

string Movie::getDirector() const {
	return myDirector;
}

void Movie::readFrom(istream& in) {
	getline(in, myTitle);
	in >> myYear;
	string newLine; getline(in, newLine);
	getline(in, myDirector);
}

void Movie::writeTo(ostream& out) const {
	out << myTitle << '\n'
	    << myYear  << '\n'
	    << myDirector << '\n';
}

bool Movie::operator==(const Movie movie2){
	/*
	 * operator== compares two movies to see if they are the exact same
	 *
	 * @param:movie2, Another Movie object
	 * @return: a bool, true if movies are the same, false otherwise.
	 */
	if (myTitle == movie2.getTitle()){
		if (myYear == movie2.getYear()) {
			if (myDirector == movie2.getDirector()){
				return true;
			}
		}
	}
	return false;
}
