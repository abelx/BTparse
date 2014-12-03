#include "BTreeFileCreater.h"
#include "Bptr.h"

int main()
{
	btreeFileCreater creater("intro.torrent");

	bptr tree =  creater.createTree();

	cout << tree << endl;

	return 0;
}
