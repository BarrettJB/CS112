/* MovieTester.h
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PROJ1_MOVIETESTER_H_
#define PROJ1_MOVIETESTER_H_

#include "Movie.h"
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

class MovieTester {
public:
   void runTests() const;
   void testDefaultConstructor() const;
   void testExplicitConstructor() const;
   void testReadFrom() const;
   void testWriteTo() const;
   void testEquals() const;
};

#endif /*PROJ1_MOVIETESTER_H_*/
