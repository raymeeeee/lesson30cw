#pragma once
#include "Date.h"
#include <string>

class Software
{
protected:
	string name;
	string company;
public:
	Software() { name = "undefined"; company = "undefined"; };
	Software(string name, string company) { this->name = name; this->company = company; };

	virtual ~Software() = 0 {};

	void setName(string name) { this->name = name; };
	void setCompany(string company) { this->company = company; };

	string setName()const { return name; };
	string setCompany()const { return company; };

	virtual void showInfo()const = 0;
	virtual bool isCheck()const = 0;
};

