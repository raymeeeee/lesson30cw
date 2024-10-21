#pragma once
#include "Software.h"
class Shareware :
    public Software
{
protected:
    Date install;
    int days;
public:
    Shareware() {days = 0; };
    Shareware(string name, string company, Date install, int days) : Software(name, company) {
        this->install = install;
        this->days = days;
    };

    void setInstall(Date install) { this->install = install; };
    void setDays(Date install) { this->days = days; };

    Date getInstall()const { return install; };
    int getDays()const { return days; };

    void showInfo()const override { 
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Install: " << install << endl;
        cout << "Days: " << days << endl;
        cout << "License: " << ((this->isCheck()) ? "True" : "False") << endl;
    };
    bool isCheck()const override { 
        return install + days > Date();
        /*Date now;
        if (install + days > now) {
            return false;
        }
        else{
            return true;
        }*/
    };

    void load(ifstream& file) override {
        getline(file, name);
        getline(file, company);

        int d = 0, m = 0, y = 0;
        file >> d >> m >> y;
        install.setYear(y);
        install.setMonth(m);
        install.setDay(d);

        file >> days;
    };
};

