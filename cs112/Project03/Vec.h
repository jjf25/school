/* Vec.h provides a simple vector class named Vec.
 * Student Name: Joey Faas
 * Date:9/27/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <cassert>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2);
	void writeToStream(ostream& out) const;
	void readFromStream(istream& in);
	Item& operator[](unsigned index);
	const Item& operator[](unsigned) const;
	bool operator!=(const Vec& v);
	void readFrom(string filename);
	void writeTo(string filename) const;
	Vec operator+(const Vec& addend);
	Vec operator-(const Vec& addend);
	double operator*(const Vec& factor);

private:
	unsigned mySize;
	Item * myArray;

	friend class VecTester;



};

#endif /*VEC_H_*/
