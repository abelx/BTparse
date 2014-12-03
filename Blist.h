#include "Bnode.h"

class bptr;

class blist : public bnode
{
	friend class bptr;
	bptr	value;
	bptr	next;

	blist(bptr v, bptr n): value(v), next(n) {}
	void print(ostream &o) const { o << "list start" << value << next << "list end" << endl;}
};