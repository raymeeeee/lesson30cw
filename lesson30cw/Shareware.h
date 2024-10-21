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
};

