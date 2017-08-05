#include <stdexcept>

int find_Max(int* A, int i)
{
    if (i == 0)
        return A[0];

    int last_max = find_Max(A, i - 1);
    if (last_max <= 0)
        return A[i];
    else
        return last_max + A[i];
}

int max_subarray(int* A, int length)
{
    if (A == nullptr || length <= 0)
        throw std::runtime_error("invalid input!");

    int greatest = 0x80000000;
    for (int i = 0; i < length; i++) {
        int max_i = find_Max(A, i);
        greatest = greatest > max_i ? greatest: max_i;
    }

    return greatest;
}

/*
 *  动态规划：f[i] = f[i-1] > 0 ? f[i-1] + A[i]: A[i]
    上述是动态规划的递归代码，可以改为循环代码
*/

int max_subarray_cycle(int* A, int length)
{
    if (A == nullptr || length <= 0)
        throw std::runtime_error("invalid input!");

    int greatest = 0x80000000;
    int cursum_max = 0;  // 只用一个变量保存f[i-1]就行了
    for (int i = 0; i < length; i++) {
        if (cursum_max <= 0)
            cursum_max = A[i];
        else
            cursum_max = cursum_max + A[i];

        greatest = greatest > cursum_max ? greatest: cursum_max;
    }

    return greatest;
}
