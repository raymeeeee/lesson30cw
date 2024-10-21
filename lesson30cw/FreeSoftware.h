#pragma once
#include "Software.h"
using namespace std;
class FreeSoftware :
    public Software
{
public:
	FreeSoftware() { name = "undefined"; company = "undefined"; };
	FreeSoftware(string name, string company) { this->name = name; this->company = company; };

	void showInfo()const override {
		cout << "Name:" << name << endl;
		cout << "Company:" << company << endl;
	};
	bool isCheck()const override { return true; };

	void load(ifstream& file) override {
		getline(file, name);
		getline(file, company);
	};

};

