#include <stdexcept>

double power_unsigned(double base, unsigned int expon);
bool equal_double(double a, double b);

double power(double base, int expon)
{
    if (equal_double(base, 0) && expon < 0)  // double因为精度问题，判断相等不能直接用 ==
        throw std::runtime_error("invalud input");

    if (expon < 0)
        return 1 / power_unsigned(base, (unsigned int)(-expon));

    return power_unsigned(base, (unsigned int)expon);
}

double power_unsigned(int base, unsigned int expon)
{
    if (expon == 1)
        return base;
    if (expon == 0)
        return 1;

    double result = 1;
    result = power_unsigned(base, expon >> 1);
    result *= result;

    if (expon & 0x1)
        result *= base;

    return result;
}

bool equal_double(double a, double b)
{
    if ( a - b < 1e-5 && a - b > -1e-5)
        return true;
    else
        return false;
}
