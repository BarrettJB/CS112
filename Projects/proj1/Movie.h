/* Movie.h
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PROJ1_MOVIE_H_
#define PROJ1_MOVIE_H_

#include <string>
#include <fstream>
using namespace std;

class Movie {
public:
	Movie();
	Movie(const string& title, int year, const string& director);
	string getTitle() const;
	int    getYear() const;
	string getDirector() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator==(const Movie movie2);
private:
	string myTitle;
	int    myYear;
	string myDirector;
};

#endif /*PROJ1_MOVIE_H_*/
