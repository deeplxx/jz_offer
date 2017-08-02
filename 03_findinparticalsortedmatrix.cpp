# include <stdexcept>

bool find(int** A, int rows, int columns, int target)
{
    if (A == nullptr || rows <= 0 || columns <= 0)
        throw std::runtime_error("invalid error!");

    int row = 0;
    int column = columns - 1;
    while (row < rows && column >= 0) {
        if (A[row][column] == target)
            return true;
        if (A[row][column] < target) {
            row++;
        } else {
            column--;
        }
    }
    return false;
}
