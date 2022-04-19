#include "StudentName.h"
#include <iostream>
using namespace std;
StudentName::StudentName(string _name)
{
    int noSpace = no_space(_name);
    if (noSpace == 0)
    {
        name += ' ' + _name + ' ' + _name + ' ' + _name;
    }
    else if (noSpace == 1)
    {
        string secName = "";
        string firName = "";

        for (int i = 0; i < _name.length(); i++)
        {

            if (_name[i] == ' ')
            {

                for (int j = i + 1; j < _name.length(); j++)
                {
                    secName += _name[j];
                }
                break;
            }
            else
            {
                firName += _name[i];
            }
        }
        name += firName + ' ' + secName + ' ' + secName;
    }
    else
    {
        name = _name;
    }
};

int StudentName::no_space(string s)
{
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            c++;
        }
    }
    return c;
}
void StudentName::  print()
{
    if(name[0]==' ')
    {
        name.erase(0,1);
    }
    name += ' ';
    string tempName = "";
    int c = 1;
    for (int i = 0; i < name.length(); i++)
    {
        tempName += name[i];
        if (name[i] == ' ')
        {
            cout << c << ")" << tempName << endl;
            c++;
            tempName = "";
        }
    }
    name.erase(name.length() - 1, 1);
}
bool StudentName::  replace(int f, int s)
{
    f--;
    s--;
    int n = no_space(name) + 1;
    if (f <= n && s <= n && f>=0 && s>=0)
    {
        string arr[n];
        string temp = "";
        name += ' ';
        int c = 0;
        for (int i = 0; i < name.length(); i++)
        {
            temp += name[i];
            if (name[i] == ' ')
            {
                arr[c] = temp;
                c++;
                temp = "";
            }
        }
        swap(arr[f], arr[s]);
        name = "";
        for (int i = 0; i < n; i++)
        {
            name += arr[i];
        }
        name.erase(name.length() - 1, 1);
        return true;
    }
    else
    {
        return false;
    }
}
