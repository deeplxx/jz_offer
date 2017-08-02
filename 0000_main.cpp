#include <iostream>
#include <string>
#include <vector>
#include "quick_sort.cpp"

using namespace std;

int main()
{
    int arr[10] = {
        12, 2, 23, 11, 33, 50, 21, 1, 34, 2
    };
    cout << 10 << endl;
    int* j = partion(arr, arr + 9);
    cout << j[10] << endl;
}
