/* main.cpp tests the classes in our project.
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 */

#include "MovieTester.h"
#include "CollectionTester.h"
#include "MovieCollection.h"
#include <iostream>
using namespace std;

int main() {
	MovieTester mt;
	mt.runTests();
	CollectionTester ct;
	ct.runTests();
	MovieCollection master("MasterCollection.txt");
	string blanklines;
	cout << endl << endl << endl << endl << endl;
	cout << "Welcome to the Movie Collection Manager!" << endl <<
			"Scroll up to examine function tests" << endl << endl;
	bool quit = false;
	while (!quit) {
		cout << "Options:" << endl;
		cout << "	1 - to search the collection for movies by a given director" << endl;
		cout << "	2 - to search the collection for movies made in a given year" << endl;
		cout << "	3 - to search the collection for movies with a given phrase in their title" << endl;
		cout << "	4 - to add a new movie to the collection" << endl;
		cout << "	5 - to remove a movie from the collection" << endl;
		cout << "	0 - to quit" << endl;
		cout << "------> " << flush;
		string input;
		cin >> input;
		cin.clear();

		if (input == "1") {
			string fname;
			string lname;
			cout << "Director First Name: " << flush;
			cin >> fname;
			cout << "Director Last Name: " << flush;
			cin >> lname;
			vector<Movie> outputMovies;
			outputMovies = master.searchByDirector(fname+" "+lname);
			cout << "Movies by " << fname << " " << lname <<": " << endl << endl;
			for (int i = 0; i < outputMovies.size(); i++ ) {
				cout << outputMovies[i].getTitle() << endl << outputMovies[i].getYear() << endl << endl;
			}
		}

		if (input == "2") {
			int year;
			cout << "Year: " << flush;
			cin >> year;
			vector<Movie> outputMovies;
			outputMovies = master.searchByYear(year);
			cout << "Movies made in " << year << ": " << endl << endl;
			for (int i = 0; i < outputMovies.size(); i++ ) {
				cout << outputMovies[i].getTitle() << endl << outputMovies[i].getDirector() << endl << endl;
			}
		}

		if (input == "3") {
			string phrase;
			cout << "Phrase: " << flush;
			cin >> phrase;
			vector<Movie> outputMovies;
			outputMovies = master.searchByTitlePhrase(phrase);
			cout << "Movies made with phrase " << phrase << " in their title: " << endl << endl;
			for (int i = 0; i < outputMovies.size(); i++ ) {
				cout << outputMovies[i].getTitle() << endl << outputMovies[i].getDirector() << endl << outputMovies[i].getYear() << endl << endl;
			}
		}

		if (input == "4") {
			string file;
			cout << "Name of Movie File: " << flush;
			cin >> file;
			ifstream fin(file.c_str());
			if (fin.is_open()) {
				Movie newMovie;
				newMovie.readFrom(fin);
				master.add(newMovie);
				master.save();
				fin.close();
				cout << newMovie.getTitle() << endl;
				cout << "succesfully added!" << endl << endl;
			}
			else {
				cout << endl << "File not Found" << endl << endl;
			}
		}

		if (input == "5") {
			string file;
			cout << "Name of Movie File: " << flush;
			cin >> file;
			ifstream fin(file.c_str());
			if (fin.is_open()) {
				Movie newMovie;
				newMovie.readFrom(fin);
				master.remove(newMovie);
				master.save();
				fin.close();
				cout << newMovie.getTitle() << endl;
				cout << "succesfully removed!" << endl << endl;
			}
			else {
				cout << endl << "File not Found" << endl << endl;
			}
		}

		if (input == "0") {
			quit = true;
		}
	}
}

