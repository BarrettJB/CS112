/* MovieCollection.h
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PROJ1_MOVIECOLLECTION_H_
#define PROJ1_MOVIECOLLECTION_H_

#include <string>
#include "Movie.h"
#include <vector>
#include <cassert>
using namespace std;

class MovieCollection {
public:
	MovieCollection(const string& fileName);
	vector<Movie> searchByDirector(const string& directorName) const;
	vector<Movie> searchByYear(const int& year) const;
	vector<Movie> searchByTitlePhrase(const string& phrase) const;
	void add(const Movie& newMovie);
	void remove(const Movie newMovie);
	void save() const;
private:
	vector<Movie> myMovies;
	string myFile;
};

#endif /*PROJ1_MOVIECOLLECTION_H_*/
