#include "Catalog.h"

Catalog::Catalog()
{
	ifstream file("info-soft.txt");
	if (file.is_open()) {
		string type;
		while (!file.eof()) {
			getline(file, type);
			if (type == "FreeSoftware") {
				Software* obj = new FreeSoftware();
				obj->load(file); //name+company
				catalog.push_back(obj);
			}
			else if (type == "Shareware") {
				Software* obj = new Shareware();
				obj->load(file); //name+company+install+days
				catalog.push_back(obj);
			}
			else if (type == "Comercial") {
				Software* obj = new Comercial();
				obj->load(file); //name+company+install+days+price
				catalog.push_back(obj);
			}
		}
		file.close();
	}
}

Catalog::~Catalog()
{
	for (int i = 0; i < catalog.size(); i++)
	{
		delete catalog[i];
	}
}

void Catalog::addSoftware(Software* software)
{
	if (software != nullptr) {
		catalog.push_back(software);
	}
}

void Catalog::delSoftware(int index)
{
	if (index > 0 && index <= catalog.size()) {
		delete catalog[index - 1];
		//catalog[index - 1]->~Software(); //плохой вариант, остаются данные
		catalog.erase(catalog.begin()+index-1);
	}
}

void Catalog::showCatalog() const
{
	for (int i = 0; i < catalog.size(); i++)
	{
		cout << "\t#" << i + 1 << endl;
		catalog[i]->showInfo();
		cout << endl;
	}
}
