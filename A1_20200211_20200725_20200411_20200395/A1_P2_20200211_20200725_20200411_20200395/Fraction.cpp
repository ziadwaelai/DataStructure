#include <iostream>
#include "Fraction.h"
using namespace std;

    fraction::fraction() {}


    fraction fraction :: operator+(const fraction& ob) {

        // num2 = dominator
        fraction f;
        f.num1 = num1 * ob.num2 + num2 * ob.num1;
        f.num2 = num2 * ob.num2;
        f.simplify();
        return f;
    }
    fraction fraction :: operator-(const fraction& ob) {

        // num2 = dominator
        fraction f;
        f.num1 = num1 * ob.num2 - num2 * ob.num1;
        f.num2 = num2 * ob.num2;
        f.simplify();
        return f;
    }
    fraction fraction :: operator*(const fraction& ob) {

        // num2 = dominator
        fraction f;
        f.num1 = num1 * ob.num1;
        f.num2 = num2 * ob.num2;
        f.simplify();
        return f;
    }
    fraction fraction :: operator/(const fraction& ob) {

        // num2 = dominator
        fraction f;
        f.num1 = num1 * ob.num2;
        f.num2 = num2 * ob.num1;
        f.simplify();
        return f;
    }
     ostream& operator<<(ostream& out, fraction& obj)
     {
        if (obj.num1 == obj.num2)
            out << 1 << endl;

        else if (obj.num1 == 0)
            out << 0 << endl;

        else if (obj.num2 == 0)
            out << "You can not divide by zero" << endl;

        else
        out << obj.num1 << "/" << obj.num2 << endl;
        return out;
    }
     istream& operator>>(istream& in, fraction& obj) {

        cout<<"enter the nominator:" << endl;
        in >> obj.num1;
        cout<<"enter the dominator:" << endl;
        in >> obj.num2;
        return in;
    }


    bool fraction :: operator>(const fraction& obj)
    {
        return (num1 > obj.num1 && num2 > obj.num2);
    }
    bool fraction :: operator>=(const fraction& obj)
    {
        return (num1 >= obj.num1 && num2 >= obj.num2);
    }

    bool fraction ::  operator<(const fraction& obj)
    {
        return (num1 < obj.num1&& num2 < obj.num2);
    }
    bool fraction :: operator<=(const fraction& obj)
    {
        return (num1 <= obj.num1 && num2 <= obj.num2);
    }

    bool fraction :: operator==(const fraction& obj)
    {
        return (num1 == obj.num1 && num2 == obj.num2);
    }

    bool fraction :: operator!=(const fraction& obj)
    {
        return (num1 != obj.num1 && num2 != obj.num2);
    }


int fraction ::gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void fraction :: simplify()
{

    int s = gcd(num1,num2);
    num1 = num1 / s;
    num2 = num2 / s;
}

