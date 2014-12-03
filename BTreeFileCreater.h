#include "MetaFile.h"
#include "Bptr.h"

class btreeFileCreater
{
	metaFile	filebuf;
	bptr		ptr;

public:
	btreeFileCreater(string str): filebuf(str) {}
	bptr createTree();
private:
	bptr addNode();
	bptr addIntNode();
	bptr addStringNode();
	bptr addListNode();
	bptr addDirectNode();
	bool isEnd();
};