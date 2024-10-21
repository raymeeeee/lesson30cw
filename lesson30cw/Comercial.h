#pragma once
#include "Shareware.h"
class Comercial :
    public Shareware
{
protected:
    float price;
public:
    Comercial() { price = 0; };
    Comercial(string name, string company, Date install, int days, float price) : Shareware(name, company, install, days) { this->price = price; };

    void setPrice(float price) { this->price = price; };
    float getPrice()const { return price; };

    void showInfo()const override { 
        Shareware::showInfo();
        cout << "Price: " << price << endl;
    };

    void load(ifstream& file) override {
        /*getline(file, name);
        getline(file, company);

        int d = 0, m = 0, y = 0;
        file >> d >> m >> y;
        install.setYear(y);
        install.setMonth(m);
        install.setDay(d);

        file >> days;
        file >> price;*/

        Shareware::load(file);
        file >> price;
    }
};

