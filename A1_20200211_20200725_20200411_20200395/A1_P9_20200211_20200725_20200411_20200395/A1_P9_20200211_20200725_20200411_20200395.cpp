#include <iostream>
#include <string>
#include <chrono>
#include<time.h>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;
using namespace std::chrono;
class Sorter{
public:
    virtual void sort(int arr[], int size) {};
};

class selectionSorter : public Sorter{
public:
    void sort(int arr[], int n){
        for (int i = 0, j, least; i < n - 1; i++){
            for (j = i + 1, least = i; j < n; j++)
                if (arr[j] < arr[least])
                    least = j;
           swap (arr[least], arr[i]);
        }
    }
};
class QuickSorter : public Sorter{
public:
    int partition(int a[], int left, int right){
        int piv = a[left];
        int i = left;
        int j = right;
        while (i < j){
            do {
                i++;
            }while (a[i] <= piv);
            do {
                j--;
            }while (a[j] > piv);
            if (i < j)
                swap(a[i], a[j]);
        }
        swap(a[left], a[j]);
        return j;
    }
    void quick_sort(int a[], int left, int right){
        if (left < right){
            int piv = partition(a, left, right);
            quick_sort(a, left, piv);
            quick_sort(a, piv + 1, right);
        }
    }
    void sort(int arr[], int size) {
        quick_sort(arr, 0, size - 1);
    }
};

class Testbed{
    Sorter* sorter;
public:
    Testbed(Sorter *s) {
        sorter = s;
    }
    void GenerateRandomList(int min, int max, int size){
        int randArray[size];
        for (int i = 0; i < size; i++){
            randArray[i] = (rand() % max) + min; // we put min here to determine from where i will start
        }
        cout << "before sorting: ";
        for (int i = 0; i < size; i++){
            cout << randArray[i] << " ";
        }
        cout << setw(20);
        clock_t start, finish;
        start = clock();
        sorter->sort(randArray, size);
        cout << "after sorting: ";
        for (int i = 0; i < size; i++){
            cout << randArray[i] << " ";
        }
        cout << setw(20);
        finish = clock();
        cout << "Time Taken: " << (((double)(finish - start))/CLOCKS_PER_SEC)*100000 << " msec" << endl;
    }
    void GenerateReverseOrderedList(int min, int max, int size){
        int randArray[size];
        for (int i = 0; i < size; i++){
            randArray[i] = (rand() % max) + min;
        }
        clock_t start, finish;
        start = clock();
        sorter->sort(randArray, size);
        for (int i = size - 1; i >= 0; i--){
            cout << randArray[i] << " ";
        }
        cout << setw(20);
        finish = clock();
        cout << "Time Taken: " << (((double)(finish - start))/CLOCKS_PER_SEC)*100000 << " msec" << endl;
    }
    void RunOnce(Sorter* sorter, int data[], int size){
        sorter->sort(data, size);
    }
    void RunAndAverage(Sorter* sorter, int type, int min, int max, int size, int sets_num){
        cout << "choose the type: " << endl;
        cout << "1. for Random list" << endl;
        cout << "2. for Reversed list" << endl;
        cout << "If you have chosen 1 the Sets Number will printed as random list, \n";
        cout << "And If you have chosen 2 the Sets Number will printed as reversed list.\n";
        cin >> type;
        switch(type){
            case 1:
                cout << "Random List:" << endl;
                break;
            case 2:
                cout << "Reversed Random List:" << endl;
                break;
        }
        cout << "Enter Number Of Sets: ";
        cin >> sets_num;
        cout << "Sets_num: " << sets_num << endl;
        clock_t start, finish;
        for (int i = 0; i < sets_num; i++) {
                if (type == 1) {
                    start = clock();
                    GenerateRandomList(min, max, size);
                    cout << endl;
                    finish = clock();
                }
                else if (type == 2) {
                    start = clock();
                    GenerateReverseOrderedList(min, max, size);
                    cout << endl;
                    finish = clock();
                }
        }
        cout << "Average Time: " << (((double)(finish - start))/CLOCKS_PER_SEC/sets_num)*100000 << " msec" << endl;
    }
    void RunExperient(Sorter* sorter, int type, int min, int max, int min_val, int max_val, int sets_num, int step) {
        for (int i = min_val; i <= max_val; i += step) {
            RunAndAverage(sorter, type, min, max, i, sets_num);
            cout << "Sets size = " << i << endl;
            cout << endl;
        }
    }
    void print(int arr[], int size){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Sorter * sorter;
    selectionSorter derivedSorter;
    sorter = &derivedSorter;
    Testbed ob(sorter);
    int sets_num = 0, type = 0;
    ob.RunExperient(sorter, type, 1, 11000, 10, 1000, sets_num, 50);
    //ob.RunAndAverage(sorter, type, 0, 10, 5, sets_num);
    //cout << endl;
    //ob.RunOnce(sorter, arr, size);
    return 0;
}
