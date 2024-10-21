#pragma once
#include "FreeSoftware.h"
#include "Comercial.h"
#include <vector>
#include <fstream>

class Catalog
{
	vector<Software*> catalog;
public:
	Catalog();
	~Catalog();

	void addSoftware(Software* software);
	void delSoftware(int index);

	void showCatalog()const;

	
};

