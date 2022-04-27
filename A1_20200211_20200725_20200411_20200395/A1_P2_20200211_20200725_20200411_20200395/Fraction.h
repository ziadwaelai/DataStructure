#ifndef PROBLEM2_FRACTION_H
#define PROBLEM2_FRACTION_H
#include <iostream>

using namespace std;

class fraction{

protected:
    int num1,num2;
public:
    fraction();

    fraction operator + (const fraction& ob);
    fraction operator - (const fraction& ob);
    fraction operator * (const fraction& ob);
    fraction operator / (const fraction& ob);

    bool operator<(const fraction& obj);
    bool operator>(const fraction& obj);
    bool operator <= (const fraction& ob);
    bool operator >= (const fraction& ob);
    bool operator == (const fraction& ob);
    bool operator != (const fraction& ob);

    friend istream& operator >> (istream& in, fraction& obj);
    friend ostream& operator << (ostream& out, fraction& obj);

    void simplify();
    int gcd(int x ,int y);
};


#endif //PROBLEM2_FRACTION_H

