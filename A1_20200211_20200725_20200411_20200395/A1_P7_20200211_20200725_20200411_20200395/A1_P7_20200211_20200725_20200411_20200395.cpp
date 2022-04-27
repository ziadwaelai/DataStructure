#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void BiasedSort(vector<string> &v)
{
	int index = 0;
	string temp;
	for (int i = 0; i < v.size(); i++)
	{

		if (v[i] == "Untitled")
		{
			swap(v[index], v[i]);

			index++;
		}
		for (int j = index; j < v.size() - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}
int main()
{
	string a;
	vector<string> vec = {"Sehert El Leil", "Khesert Koul El Nass", "Untitled", "EL Bakht", "Untitled", "i love you", "Untitled", "Keify keda"};
	cout << "If You Want To Add More Songs Enter (Yes) Else Enter (No) :" << endl;
	cin >> a;
	if (a == "yes" || a == "YES")
	{
		int num;
		cout << "Enter Number of Songs you Want to Add " << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "Enter Song Name:" << endl;
			cin >> a;
			vec.push_back(a);
		}
		BiasedSort(vec);
		for (auto it : vec)
		{
			cout << it << endl;
		}
	}
	else
	{
		BiasedSort(vec);
		for (auto it : vec)
		{
			cout << it << endl;
		}
	}
	vec.clear();
}
