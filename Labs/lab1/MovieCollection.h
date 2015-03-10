/* MovieCollection.h
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

#include <string>
#include "Movie.h"
#include <vector>
#include <cassert>
using namespace std;

class MovieCollection {
public:
   MovieCollection(const string& fileName);
   vector<Movie> searchByDirector(const string& directorName) const;
private:
   vector<Movie> myMovies;
};

#endif /*MOVIECOLLECTION_H_*/
