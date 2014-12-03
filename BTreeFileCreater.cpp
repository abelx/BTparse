#include "BTreeFileCreater.h"

#define BSTRING	
#define BDIRECT		'd'
#define	BINT		'i'
#define BEND		'e'
#define ZERO_CHAR	'0'
#define BLIST		'l'

bptr btreeFileCreater::addIntNode()
{
	int value	= 0;
	int pos		= filebuf.getPosition();
	while(isdigit(filebuf.getCharByPosition(pos))) 
	{ 		
		value = value* 10 +(filebuf.getCharByPosition(pos) - ZERO_CHAR); 
		pos++;
	}
	
	pos++;	
	filebuf.setPosition(pos);

	bptr ptr(value);
	return ptr;
}

bptr btreeFileCreater::addStringNode()
{
	string	value;
	int		length	= 0;
	int		pos		= filebuf.getPosition();
	while(isdigit(filebuf.getCharByPosition(pos))) 
	{ 
		length = length* 10 +(filebuf.getCharByPosition(pos) - ZERO_CHAR); 
		pos++;
	}

	if(length != 0)
	{
		pos++; 
		value	= filebuf.getPart(pos, length);
		pos		+= length;
	}
	
	filebuf.setPosition(pos);

	bptr	ptr(value);
	return ptr;
}

bptr btreeFileCreater::addListNode()
{
	if(isEnd())
	{
		bptr ptr;
		return ptr;
	}

	bptr	value	= addNode();  //这里是一个问题，是先调用空构造函数，然后调用operator=还是直接调用的拷贝构造函数
	bptr	next	= addListNode();
	bptr	the(value, next);
	return the;
}

bptr btreeFileCreater::addDirectNode()
{
	if(isEnd())
	{
		bptr ptr;
		return ptr;
	}

	bptr	key(addNode());
	bptr	value(addNode());
	bptr	next(addDirectNode());

	bptr	the(key, value, next);
	return the;
}

bptr btreeFileCreater::addNode()
{
	int pos	= filebuf.getPosition();
	char c		= filebuf.getCharByPosition(pos);
	
	bptr ptr;
	switch(c)
	{
	case BLIST:
		pos++;
		filebuf.setPosition(pos);
		ptr	= addListNode();
		break;
	case BDIRECT:
		pos++;
		filebuf.setPosition(pos);
		ptr	= addDirectNode();
		break;
	case BINT:
		pos++;
		filebuf.setPosition(pos);
		ptr	= addIntNode();
		break;
	case BEND:
		break;
	default:
		ptr	= addStringNode();
		break;
	}

	return ptr;
}

bool btreeFileCreater::isEnd()
{
	
	if(filebuf.getPosition() > filebuf.getLength())
		return true;

	if(filebuf.getCharByPosition(filebuf.getPosition()) == 'e')
	{
		filebuf.setPosition(filebuf.getPosition() + 1);
		return true;
	}

	return false;
}

bptr btreeFileCreater::createTree()
{
	bptr ptr;
	if(filebuf.getLength() > 0)
		ptr = addNode();
	return ptr;
}
