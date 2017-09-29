/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Joey Faas
 * Date: 9/27/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <cstdlib>
#include <stdexcept>
#include <ostream>
#include <fstream>

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
	if (mySize > 0) {
		for (unsigned i = 0; i < size; i++) {
			myArray[i] = 0;
		}
	} else {
		myArray = NULL;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	myArray = new Item[original.mySize]();
	if (original.mySize > 0) {
		for (unsigned i = 0; i < original.mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
}
Vec::~Vec() {
	mySize = 0;
	delete[] myArray;
	myArray = NULL;
}

Vec& Vec::operator=(const Vec& original) {

	if (original.myArray != myArray) {
		mySize = original.mySize;
		delete[] myArray;
		myArray = new Item[original.mySize]();

		if (original.mySize > 0) {
			for (unsigned i = 0; i < mySize; i++) {
				myArray[i] = original.myArray[i];
			}
		} else {
			myArray = NULL;
		}
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (myArray != NULL) {

		if (index >= mySize) {
			throw range_error("Vec(index) is too large!");
		} else {
			myArray[index] = it;
		}
	} else {
		throw range_error("setItem(vec can not be empty)");
	}
}

Item Vec::getItem(unsigned index) const {
	if (myArray != NULL) {
		if (index >= mySize) {
			throw range_error("Vec(index) is too large for the vector");
		} else {
			return myArray[index];
		}
	} else {
		throw range_error("Vec cannot be empty");
	}
}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete[] myArray;
			myArray = NULL;
			mySize = 0;
		}

		else {

			Item* newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize + 1; i < newSize; i++) {
					newArray[i] = 0;

				}
				mySize = newSize;

			} else {
				mySize = newSize;
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
			}
			myArray = newArray;
		}
	}
}

bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

void Vec::writeToStream(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << "\n";

	}
}

void Vec::readFromStream(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

//changes the item at the index
Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}
	return myArray[index];
}

//retrieves the item at the index
const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Vec(index) is too large for the vector");
	} else if (index < 0) {
		throw range_error("Vec(index) is too small for the vector");
	}

	return myArray[index];
}

bool Vec::operator!=(const Vec& v) {
	unsigned a = 0;
	if (mySize == v.mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] == v.myArray[i]) {
				a += 1;
			}
		}
		if (a == mySize) {
			return false;
		}
	}
	return true;
}

void Vec::readFrom(string filename){
	int numvalues;
	ifstream fin(filename.c_str());
	assert(fin.is_open());

	fin>>numvalues;
	delete[] myArray;

	Item *temp = new Item[numvalues];

	for (int i=0; i<numvalues; i++){
		fin>>temp[i];
	}
	myArray = temp;
	mySize= numvalues;
	fin.close();
}

void Vec::writeTo(string filename) const{
	ofstream fout(filename.c_str());
	assert(fout.is_open());
	fout<<mySize<<endl;
	for (int i=0; i<mySize; i++){
		fout<<myArray[i]<<endl;
	}
	fout.close();
}

Vec Vec::operator+(const Vec& addend){
	if (mySize != addend.mySize){
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec temp = *this;
	for (unsigned i = 0; i<mySize; i++){
		temp.setItem(i, myArray[i] + addend.getItem(i));
	}
	return temp;
}

Vec Vec::operator-(const Vec& addend){
	if (mySize != addend.mySize){
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec temp = *this;
	for (unsigned i = 0; i<mySize; i++){
		temp.setItem(i, myArray[i] - addend.getItem(i));
	}
	return temp;
}

double Vec::operator*(const Vec& factor){
	if (mySize != factor.mySize){
		throw std::invalid_argument("Vectors are not the same size!");
	}
	Vec sums(mySize);
	for (unsigned i = 0; i<mySize; i++){
		sums.setItem(i, myArray[i] * factor.myArray[i]);
	}
	double sum = 0;
	for (unsigned i=0; i<mySize; i++){
		sum+= sums.getItem(i);
	}
	return sum;
}
