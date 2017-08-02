#include <stdexcept>

/*
    从末尾开始，begin和begin之后的每一个元素都交换一次，注意，每次递归返回都需要把未交换情况打印一次，即pch从begin开始、
    本来正常循环是从头开始，但是使用递归后，begin直到递归到最后一个元素才开始打印，然后逐层返回并打印
*/
void permutation(char* pstr, char* begin)
{
    if (*begin == '\0')
        printf("%s\n", pstr);

    for (auto pch = begin; *pch != '\0'; pch++) {
        auto tmp = *begin;
        *pch = tmp;
        *begin = *pch;

        permutation(pstr, begin + 1);

        tmp = *begin;
        *pch = tmp;
        *begin = *pch;
    }
}


void permutation(char* pstr)
{
    if (pstr == nullptr)
        throw std::runtime_error("invalid input!");

    permutation(pstr, pstr);
}
