/* main.cpp tests the classes in our project.
 * Student Name: Barrett Bryson
 * Date: 2/10/2015
 */

#include "MovieTester.h"
#include "CollectionTester.h"
#include <iostream>
using namespace std;

int main() {
    MovieTester mt;
    mt.runTests();
    CollectionTester ct;
    ct.runTests();
}
