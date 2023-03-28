#ifndef INGREDIANT_H
#define INGREDIANT_H

#include <string>

using namespace std;

class ingredient {
private:
    string name;
    double amount;
    bool isAlergy;

public:
    ingredient(string, bool);
    ingredient(string, double, bool);
    string getName();
    double getAmount();
    bool getIsAlergy();
    void setAmount(double);

    friend ostream& operator<<(ostream&, const ingredient&);
    friend bool operator==(const ingredient&, const ingredient&);
};

#endif // INGREDIANT_H
