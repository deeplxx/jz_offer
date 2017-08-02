#include <stdexcept>

int* sort_age(int a[], int length)
{
    int ages[100];
    for (int i = 0; i < length; ++i)
        ages[i] = 0;

    for (int i = 0; i < length; ++i) {
        if (a[i] <= 0 || a[i] >= 100) {
            char* s;
            std::sprintf(s, "invalid input at %d", i);
            throw std::runtime_error(s);
        }
        ++ ages[a[i]];
    }

    int index = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < ages[i]; j++) {
            a[index] = i;
            index++;
        }
    }

    return a;
}

/*
    1.给有界（不大）的序列排序，可以考虑用统计每个数字出现的次数来排序
*/
