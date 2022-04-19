#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <iostream>
using namespace std;

class StudentName
{
private:
    string name;
    int no_space(string s);

public:
    StudentName(string _name);
    void print();
    bool replace(int f, int s);
};

#endif // STUDENTNAME_H
