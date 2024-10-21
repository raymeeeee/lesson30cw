#include "FreeSoftware.h"
#include "Comercial.h"

int main()
{
	//Software a("Steam", "Valve");
	/*FreeSoftware b("Spotify", "Spotify AB");
	b.showInfo();*/
	Shareware c("SAI", "SAI.inc", Date(1, 9, 2000), 30);
	c.showInfo();
	//cout << "License: " << c.isCheck() << endl;
	cout << "=======================" << endl;
	Comercial d("Spotify Premium", "Spotify AB", Date(), 30, 645);
	d.showInfo();

}

