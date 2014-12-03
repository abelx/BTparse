#include "Bptr.h"
#include "Bdirect.h"
#include "Bint.h"
#include "Blist.h"
#include "Bstring.h"

bptr::bptr(int n)
{
	node	= new bint(n);
}

bptr::bptr(const string &str)
{
	node	= new bstring(str);
}

bptr::bptr(bptr v,bptr n)
{
	node	= new blist(v, n);
}

bptr::bptr(bptr k, bptr v, bptr n)
{
	node	= new bdirect(k, v, n);
}

bptr::bptr(const bptr &p)
{
	node	= p.node;
	if(p.node != NULL)
	{
		++(node->use);
	}
	
}

bptr::~bptr()
{
	if(node !=NULL)
	{
		if(node->use <= 1)
			delete node;
	}
}

bptr & bptr::operator=(const bptr &p)
{
	if(p.node == NULL && node != NULL)
	{
		if(--(node->use) == 0)
			delete node;
		node = NULL;
		return *this;
	}

	if(node == NULL && p.node != NULL)
	{
		p.node->use++;
		node	= p.node;
		return *this;
	}

	if(node == NULL && p.node == NULL)
	{
		return *this;
	}


	(p.node->use)++;
	if(--(node->use) == 0)
		delete node;
	node	= p.node;
	return *this;
}

ostream & operator<< (ostream & out, const bptr &ptr)
{
	if(ptr.node != NULL)
		ptr.node->print(out);
	return out;
}