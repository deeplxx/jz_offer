char find_fist(char* A, int length)
{
    if (A == nullptr || length <= 0)
        return -1;

    unsigned int hashArray[256] = {};
//    for (int i = 0; i < length; i++) {
//        hashArray[int(A[i])] += 1;
//    }
    char* p = A;
    while (*p != '\0') {
        hashArray[*(p++)] += 1;
    }
    while (*p != '\0') {
        if (hashArray[*(p++)] == 1)
            return *p;
    }

    return '\0';
}
