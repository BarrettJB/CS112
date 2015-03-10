/* MovieCollection.cpp
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "MovieCollection.h"
#include <fstream>
using namespace std;

MovieCollection::MovieCollection(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	myFile = fileName;
	Movie aMovie;
	while (true) {
		aMovie.readFrom(fin);
		if ( !fin ) break;
		string blankLine;
		getline(fin, blankLine);
		myMovies.push_back(aMovie);
	}
	fin.close();
}

vector<Movie> MovieCollection::searchByDirector(const string& directorName) const {
	vector<Movie> v;
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getDirector().find(directorName) != string::npos ) {
			v.push_back( myMovies[i] );
		}
	}
	return v;
}

vector<Movie> MovieCollection::searchByYear(const int& year) const {
	/*
	 * searchByYear() searches a MovieCollection for all Movies that were made within given year
	 *
	 * @param: integer year, The year that is desired for the search
	 * @return: a vector of Movies, all movies in the collection made in the given year
	 */
	vector<Movie> output;
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getYear() == year) {
			output.push_back( myMovies[i] );
		}
	}
	return output;
}

vector<Movie> MovieCollection::searchByTitlePhrase(const string& phrase) const {
	/*
	 * searchByTitlePhrase() searches a MovieCollection for all Movies whose titles contain
	 * the given phrase
	 * @param: string phrase, The phrase that is desired for the search
	 * @return: a vector of Movies, all movies in the collection with titles containing
	 * the given phrase
	 */
	vector<Movie> v;
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getTitle().find(phrase) != string::npos ) {
			v.push_back( myMovies[i] );
		}
	}
	return v;
}


void MovieCollection::add(const Movie& newMovie) {
	/*
	 * add() adds a movie to the MovieCollection
	 * postcondition: myMovies.size() == N &&
	 *                myMovies contains the newMovie.
	 * @param: Movie newMovie, the Movie that you want to add
	 */
	myMovies.push_back(newMovie);
}

void MovieCollection::remove(Movie newMovie) {
	/*
	 * remove() removes a movie to the MovieCollection
	 * postcondition: myMovies.size() == N --
	 *                myMovies no longer contains the newMovie.
	 * @param: Movie newMovie, the Movie that you want to remove
	 */
	for (unsigned i = 0; i < myMovies.size(); i++) {
		Movie test = myMovies[i];
		if (newMovie == test) {
			myMovies.erase(myMovies.begin()+i);
		}
	}
}

void MovieCollection::save() const {
	/*
	 * save() Rewrites the original .txt file with the new data for the collection.
	 * postcondition: myFile.txt contains the new data
	 */
	ofstream fout(myFile.c_str());
	for (unsigned i = 0; i < myMovies.size(); i++) {
		Movie amovie = myMovies[i];
		amovie.writeTo(fout);
		fout << "\n";
	}
	fout.close();
}


