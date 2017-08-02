#include <stdexcept>

int seq_sort(int a[], int start, int end)
{
    int min_num= a[start];
    for (int i = start + 1; i < end; i++) {
        min_num = (min_num < a[i]) ? min_num: a[i];
    }

    return min_num;
}

int binary_search(int a[], int length)
{
    if (length == 0)
        throw std::runtime_error("invalid input!");

    int start = 0;
    int end = length - 1;
    int mid = start;  // 应对未旋转情况

    while (a[start] >= a[end]) {
        if (end - start <= 1) {
            mid = end;
            break;
        }

        mid = (end + start) / 2;
//        if (a[mid] >= a[end])
//            start = mid;
//        else
//            end = mid;
        if (a[mid] == a[end] && a[mid] == a[start]) {
            return seq_sort(a, start, end);  // 此时只能顺序查找
        } else if (a[mid] >= a[end]) {
            start = mid;
        } else {
            end = mid;
        }

    }

    return a[mid];
}

/**
    1.当a[mid] == a[end]时，无法判断最小值在前半段还是在后半段
*/
