#include "Bnode.h"

class bptr;

class bint : public bnode
{
	friend class bptr;
	int	value;
	
	bint(int k):value(k){ }
	void print(ostream &o) const{ o << value << endl;}
};