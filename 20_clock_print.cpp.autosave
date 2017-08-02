#include <stdexcept>
#include <iostream>

void print_cicle(int** a, int rows, int columns, int start)
{
    int endX = rows - start;
    int endY = columns - start;

    for (int i = start; i < endY; i++) {
        std::cout << a[start][i] << " ";
    }
    if (start < endX) {
        for (int i = start + 1; i < endX; i++) {
            std::cout << a[i][endY - 1] << " ";
        }
    }

    if (endY > start + 1 && endX > start) { //执行此行建立在上个 if 语句执行的基础上
        for (int i = endY - 2; i >= start; i--) {
            std::cout << a[endX - 1][i] << " ";
        }
    }
    if (endX > start + 2 && endY > start + 1) {
        for (int i = endX - 2; i >= start + 1; i--) {
            std::cout << a[i][start] << " ";
        }
    }

}

void clock_print(int** a, int rows, int columns)
{
    if (a == nullptr || rows <=0 || columns <= 0)
        throw std::runtime_error("invalid input!");

    int start = 0;
    while (rows > 2 * start && columns > 2 * start) {
        print_cicle(a, rows, columns, start);
        start++;
    }
}


