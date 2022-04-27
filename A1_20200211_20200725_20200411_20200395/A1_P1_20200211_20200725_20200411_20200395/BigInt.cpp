#include "BigInt.h"
#include <iostream>
using namespace std;

void reverseStr(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
void removeleftzeros(string &a)
{
    if (a[0] == '0')
    {
        int i = 0;
        while (a[i] == '0')
            i++;

        if (i == (a.length()))
            a.erase(0, i - 1);
        else
            a.erase(0, i);
    }
}

BigInt::BigInt(string _num)
{
    num = _num;
};
BigInt::BigInt(){};
BigInt::BigInt(const int &_num)
{
    num = to_string(_num);
};

bool isBiger(string a, string b)
{
    long long len = 0;
    a.length() >= b.length() ? len = a.length() : len = b.length();

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] > b[i])
        {
            return true;
        }
        else if (a[i] < b[i])
        {
            return false;
        }
    }
}
bool isEqule(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

BigInt BigInt::operator+(BigInt &b)
{
    if (num[0] != '-' && b.num[0] != '-')
    {
        bool isfirst = false;
        int lenBiger = 0, lensmaller = 0;
        isfirst = isBiger(num, b.num);
        isfirst ? lenBiger = num.length() : lenBiger = b.num.length();
        !isfirst ? lensmaller = num.length() : lensmaller = b.num.length();
        string tempNums;
        if (b.num.length() < num.length())
        {
            tempNums = b.num;
            reverseStr(tempNums);
            // cout<<lenBiger-lensmaller;
            for (int i = 0; i < abs(lenBiger - lensmaller); i++)
            {
                tempNums += '0';
            }
            reverseStr(tempNums);
            b.num = tempNums;
        }
        else
        {
            tempNums = num;
            reverseStr(tempNums);
            for (int i = 0; i < abs(lenBiger - lensmaller); i++)
            {
                tempNums += '0';
            }
            reverseStr(tempNums);
            num = tempNums;
        }
        string tempNum;
        // cout << num << endl;
        // cout << b.num << endl;

        bool isCarray = false;
        for (int i = lenBiger - 1; i > -1; i--)
        {

            int tempInt = isCarray ? (num[i] - '0') + (b.num[i] - '0') + 1 : (num[i] - '0') + (b.num[i] - '0');

            if (tempInt > 9)
            {

                tempNum += (tempInt % 10) + '0';
                isCarray = true;
            }
            else
            {
                tempNum += tempInt + '0';
                isCarray = false;
            }
        }
        if (isCarray)
        {
            tempNum += "1";
        }
        reverseStr(tempNum);
        removeleftzeros(tempNum);
        return BigInt(tempNum);
    }
    else if ((num[0] != '-' && b.num[0] == '-') || (num[0] == '-' && b.num[0] != '-'))
    {
        if (num[0] != '-' && b.num[0] == '-')
        {
            b.num.erase(0, 1);
            BigInt n1(num), n2(b.num);
            reverseStr(b.num);
            b.num += '-';
            reverseStr(b.num);
            return n1 - n2;
        }
        else
        {
            BigInt n1(num), n2(b.num);
            return n2 - n1;
        }
    }
    else
    {
        num.erase(0, 1);
        b.num.erase(0, 1);
        BigInt n1(num), n2(b.num);
        BigInt r = n1 + n2;
        reverseStr(r.num);
        r.num += '-';
        reverseStr(r.num);
        reverseStr(num);
        reverseStr(b.num);
        num += '-';
        b.num += '-';
        reverseStr(num);
        reverseStr(b.num);

        return r;
    }
}
int BigInt::size()
{
    return num.length();
}

ostream &operator<<(ostream &output, BigInt a)
{
    cout << a.num;
    return output;
}
BigInt BigInt::operator-(BigInt &b)
{
    if (num[0] != '-' && b.num[0] != '-')
    {

        int numLen = num.length(), blen = b.num.length();
        int len = abs(numLen - blen);
        if (num.length() > b.num.length())
        {
            reverseStr(b.num);
            for (int i = 0; i < len; i++)
            {
                b.num += '0';
            }
            reverseStr(b.num);
        }
        else if (num.length() < b.num.length())
        {
            reverseStr(num);
            for (int i = 0; i < len; i++)
            {
                num += '0';
            }
            reverseStr(num);
        }
        bool isNagtive = false;
        if (!isBiger(num, b.num))
        {
            swap(num, b.num);
            isNagtive = true;
        }
        string tempString = "";
        for (int i = num.length() - 1; i > -1; i--)
        {
            int tempNum;

            // cout<<i<<" "<<num[i]<<" "<<b.num[i]<<endl;
            if (num[i] < b.num[i])
            {
                int j = i - 1;
                while (num[j] - '0' == 0 && j > 0)
                {
                    num[j] = ((num[j] - '0') + 9) + '0';

                    j--;
                }
                num[j] = ((num[j] - '0') - 1) + '0';
                tempNum = (num[i] - '0' + 10) - (b.num[i] - '0');
            }
            else
            {
                tempNum = (num[i] - '0') - (b.num[i] - '0');
            }
            tempString += tempNum + '0';
        }
        reverseStr(tempString);
        removeleftzeros(tempString);
        if (isNagtive && tempString[0] != '0')
        {
            reverseStr(tempString);
            tempString += '-';
            reverseStr(tempString);
            swap(num, b.num);
        }
        return BigInt(tempString);
    }
    else if ((num[0] != '-' && b.num[0] == '-') || (num[0] == '-' && b.num[0] != '-'))
    {
        if ((num[0] != '-' && b.num[0] == '-'))
        {
            b.num.erase(0, 1);
            BigInt n1(num), n2(b.num);
            return n1 + n2;
        }
        else
        {
            num.erase(0, 1);
            b.num.erase(0, 1);

            BigInt n1(num), n2(b.num);
            BigInt r = n1 + n2;
            reverseStr(r.num);
            r.num += '-';
            reverseStr(num);
            reverseStr(b.num);
            num += '-';
            b.num += '-';
            reverseStr(num);
            reverseStr(b.num);
            reverseStr(r.num);
            return r;
        }
    }
    else
    {
        b.num.erase(0, 1);
        num.erase(0, 1);
        BigInt n1(num), n2(b.num);
        reverseStr(num);
        reverseStr(b.num);
        num += '-';
        b.num += '-';
        reverseStr(num);
        reverseStr(b.num);
        return n2 - n1;
    }
}
bool BigInt::operator==(BigInt const &b)
{
    if (isEqule(num, b.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}
