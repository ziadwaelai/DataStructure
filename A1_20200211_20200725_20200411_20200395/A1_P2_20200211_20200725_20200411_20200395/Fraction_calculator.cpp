#include <iostream>
using namespace std;
#include "Fraction.h"
#include "Fraction_calculator.h"
#include <vector>

fraction_calculator :: fraction_calculator(){}

void fraction_calculator::start() {


    while (true) {
        cout << "Welcome to fraction calculator" << endl;
        fraction f1,f2;
        cout << "Enter the first fraction" << endl;
        cin >> f1;
        cout << "Enter the second fraction" << endl;
        cin >> f2;

        cout << "choose one of this operation (+,-,*,/)" << endl;

        //vector<float> v1;
        string s;
        cin >> s;
        if (s == "+")
        {
            fraction f(f1 + f2);
//            for(auto f: v1)
//            v1.push_back(f);
            cout << "fraction 1 + fraction 2 = " << f << endl;
        }
        else if (s == "-")
        {
            fraction f(f1 - f2);
            cout << "fraction 1 - fraction 2 = " << f << endl;
        }
        else if (s == "*")
        {
            fraction f(f1 * f2);
            cout << "fraction 1 * fraction 2 =  " << f << endl;
        }
        else if (s == "/")
        {
            fraction f(f1 / f2);
            cout << "fraction 1 / fraction 2 =  " << f << endl;
        }
        else if (s == "0")
        {
            cout << "calculator turned off" << endl;
            break;
        }
        else
        {
            cout << "You entered invalid operation try again  or enter 0 to Exit" << endl;
        }
        cout << endl;
        cout << "if you want to finish the program Enter 0 or enter 1 to continue" << endl;
        int a; cin >> a;
        if(a == 0)
            break;
        else if (a == 1)
            continue;
        else
            cout << "Enter valid input" << endl;
            cin >> a;
    }

}