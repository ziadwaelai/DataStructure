#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> vect;
void RecPermute(string soFar, string rest)
{
    bool flag = false;
    // if word is exist
    if (rest == "")
    {
        for (int i = 0; i < vect.size(); i++)
        {
            // if value already stored then break this if
            if (soFar == vect[i])
            {
                flag = true;
                break;
            }
        }
        // if value is not stored yet then push this value back vector
        if (flag == false)
        {
            cout << soFar << endl;
            vect.push_back(soFar);
        }
    }
    // No more characters
    // Print the word
    else  // Still more chars
    {
        // For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}
// "wrapper" function
void ListPermutations(string s)
{
    RecPermute("", s);
}

int main()
{
    string sofar, rest, s;
    cin >> s;
    RecPermute(sofar, rest);
    ListPermutations(s);
    return 0;
}
