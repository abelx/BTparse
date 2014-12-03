#include "Bnode.h"
#include <string>

class bptr;

class bstring : public bnode
{
	friend class bptr;
	string	value;
	
	bstring(string str): value(str){ }
	void print(ostream &o) const{ o << value << endl;}
};