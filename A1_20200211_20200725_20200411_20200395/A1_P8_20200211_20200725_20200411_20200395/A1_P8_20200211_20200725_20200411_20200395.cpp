#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;


void linerinsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Complexity  of average case and worst case = o(n^2)
    // Complexity  of best case = o(n)
    
}



int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ?
        (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item,mid + 1, high);
    return binarySearch(a, item, low,mid - 1);
}

void binaryinsertionSort(int a[], int n)
{
    int i, location, j, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        location = binarySearch(a, selected, 0, j);
        while (j >= location)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }

   // Complexity of average case and worst case = o(n^2)
   // Complexity of best case = o(nlog(n))

}




int main(){
     
}