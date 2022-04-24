#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include <string>
using namespace std;


class BigInt
{

private:
    string num;
public:
    BigInt(string _num);
    BigInt();
    BigInt(const int &_num);
    BigInt operator-(BigInt &b);
    BigInt operator+(BigInt &b);
    bool operator==(BigInt const &b);
    friend bool isBiger(string a, string b);
    friend bool isEqule(string a, string b);
    int size();
    friend ostream &operator<<(ostream &output, BigInt a);
};
#endif
