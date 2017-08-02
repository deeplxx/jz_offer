#include <stdexcept>

int* jo_sort(int a[], int length)
{
    if (length < 2)
        return a;

    int i = 0, j = length - 1;
    while (i < j) {
        bool change = false;
        if (a[i] % 2 != 0) {
            i++;
            change = true;
        }
        if (a[j] % 2 == 0) {
            j--;
            change = true;
        }
        if (change) continue;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    return a;
}
