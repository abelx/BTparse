#include <string>

using namespace std;

class metaFile
{
	int		length;
	int		position;
	char	*fileContent;
public:
	metaFile(string);
	int		getLength();
	int		getPosition();
	bool	setPosition(int);
	char	getCharByPosition(int);
	string  getPart(int, int);

	~metaFile(){ delete [] fileContent;}
};
