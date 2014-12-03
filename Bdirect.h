#include "Bnode.h"

class bptr;

class bdirect : public bnode
{
	friend class bptr;
	bptr	key;
	bptr	value;
	bptr	next;

	bdirect(bptr k, bptr v, bptr n): key(k), value(v), next(n) {}
	void print(ostream &o) const {o << "direct start" << key << value << next << "direct end" << endl; }
};