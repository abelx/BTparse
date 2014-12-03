#ifndef BNODE
#define BNODE

#include <iostream>
using namespace std;

class bptr;

class bnode
{
	friend class bptr;
	int use;
public:
	bnode(): use(1) { }
	virtual void print(ostream &) const = 0;
	virtual ~bnode() { }
};

#endif