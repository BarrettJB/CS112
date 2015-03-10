/* CollectionTester.cpp defines the MovieCollection test-methods.
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "CollectionTester.h"

void CollectionTester::runTests() const {
   cout << "Testing class MovieCollection..." << endl;
   testConstructor();
   testSearchByYear();
   testSearchByPhrase();
   testAddRemove();
   testSave();
   cout << "All tests passed!" << endl;
}

void CollectionTester::testConstructor() const {
    cout << "- Constructor..." << flush;
    MovieCollection mc("testCollection.txt");
    // case of 1 movie
    vector<Movie> v1 = mc.searchByDirector("Hand");
    assert( v1.size() == 1 );
    assert( v1[0].getTitle() == "Bambi" );
    cout << " 1 " << flush;
    // case of 2 movies
    vector<Movie> v2 = mc.searchByDirector("Spielberg");
    assert( v2.size() == 2 );
    assert( v2[0].getTitle() == "Jaws" );
    assert( v2[1].getTitle() == "Raiders of the Lost Ark" );
    cout << " 2 " << flush;
    // case of no movies
    vector<Movie> v3 = mc.searchByDirector("Hitchcock");
    assert( v3.size() == 0 );
    cout << " 3 " << flush;
    cout << " Passed!" << endl;
}

void CollectionTester::testSearchByYear() const{
	cout << "- searchByYear()..." << flush;
	MovieCollection mc("testCollection.txt");
	//Test case with one movie
	vector<Movie> y1981 = mc.searchByYear(1981);
	assert( y1981.size() == 1);
	assert( y1981[0].getTitle() == "Raiders of the Lost Ark");
	cout << " 1 " << flush;
	//Test case with two movies
	vector<Movie> y1939 = mc.searchByYear(1939);
	assert( y1939.size() == 2);
	assert( y1939[0].getTitle() == "Gone with the Wind");
	assert( y1939[1].getTitle() == "The Wizard of Oz");
	cout << " 2 " << flush;
	//Test case with no movies
	vector<Movie> y1919 = mc.searchByYear(1919);
	assert( y1919.size() == 0);
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}

void CollectionTester::testSearchByPhrase() const {
	cout << "- searchByTitlePhrase()..." << flush;
	MovieCollection mc("testCollection.txt");
	//Test with 1 return
	vector<Movie> v1 = mc.searchByTitlePhrase("Ark");
	assert(v1[0].getTitle() == "Raiders of the Lost Ark");
	cout << " 1 " << flush;
	//Test with multiple returns
	vector<Movie> v2 = mc.searchByTitlePhrase("Wi");
	assert(v2.size() == 2);
	assert(v2[0].getTitle() == "Gone with the Wind");
	assert(v2[1].getTitle() == "The Wizard of Oz");
	cout << " 2 " << flush;
	//Test with no returns
	vector<Movie> v3 = mc.searchByTitlePhrase("Lego");
	assert(v3.size() == 0);
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}


void CollectionTester::testAddRemove() const {
	cout << "- add()/remove()... " << flush;
	MovieCollection mc("testCollection.txt");
	Movie m1("The Lego Movie",2014,"Phil Lord");
	//Test add
	mc.add(m1);
	vector<Movie> v1 = mc.searchByDirector("Phil Lord");
	assert(v1.size() == 1);
	cout << " 1 " << flush;

	//Test remove
	mc.remove(m1);
	vector<Movie> v2 = mc.searchByDirector("Phil Lord");
	assert(v2.size() == 0);

	cout << " Passed!" << endl;
}

void CollectionTester::testSave() const {
	cout << "- save()..." << flush;
	MovieCollection mc1("testCollection.txt");
	Movie m1("The Lego Movie",2014,"Phil Lord");
	mc1.add(m1);
	mc1.save();
	MovieCollection mc2("testCollection.txt");
	vector<Movie> mv = mc2.searchByTitlePhrase("Lego");
	assert(mv.size() == 1);
	cout << " 1 " << flush;
	mc2.remove(m1);
	mc2.save();
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}
