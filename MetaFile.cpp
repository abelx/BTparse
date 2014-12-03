#include "MetaFile.h"
#include <fstream>
#include <iostream>

using namespace std;

metaFile::metaFile(string filename)
{ 
	ifstream	ifile;
	filebuf		*pbuf;

	ifile.open(filename, ios::binary);
	pbuf		=ifile.rdbuf();  
    
	// ����buffer���󷽷���ȡ�ļ���С  
	length		=pbuf->pubseekoff (0,ios::end,ios::in);  
	cout << "file length :" << length << endl;
	pbuf->pubseekpos (0,ios::in);  
     
	// �����ڴ�ռ�  
	fileContent	= new char[length];
     
	// ��ȡ�ļ�����  
	pbuf->sgetn (fileContent,length);
	position = 0;
    
	ifile.close();  
}

int metaFile::getPosition()
{
	return position;
}

int metaFile::getLength()
{
	return length;
}

bool metaFile::setPosition(int p)
{
	if(p > length)
		return false;
	else
		position = p;
	return true;
}

char metaFile::getCharByPosition(int c)
{
	if(c > length)
	{
		throw "error:position > length";
		return EOF;
	}

	return fileContent[c];
}

string metaFile::getPart(int start, int len)
{
	if(start + len > length)
	{
		throw "start + len > length";
		return "0";
	}

	char	*cp	= new char[len+1];
	memcpy(cp, fileContent+start, len);
	cp[len]		= '\0';

	string str(cp);
	delete [] cp;

	return str;
}