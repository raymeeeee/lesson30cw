#include "FreeSoftware.h"
#include "Shareware.h"

int main()
{
	//Software a("Steam", "Valve");
	/*FreeSoftware b("Spotify", "Spotify AB");
	b.showInfo();*/
	Shareware c("SAI", "SAI.inc", Date(1, 9, 2000), 30);
	c.showInfo();
	cout << "License: " << c.isCheck() << endl;
}

