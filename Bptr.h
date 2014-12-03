#ifndef BPTR

#define BPTR

#include <iostream>
#include <string>

using namespace std;

class bnode;

class bptr
{
	friend ostream & operator<< (ostream &, const bptr&);

	bnode * node;
public:
	bptr(int);
	bptr(const string &);
	bptr(bptr, bptr);
	bptr(bptr, bptr, bptr);
	bptr(const bptr &);
	bptr() { node = NULL;}
	bptr& operator= (const bptr&);
	~bptr();
};
#endif