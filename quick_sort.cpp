
int* partion(int* start, int* end)
{
    int pivoKey = *start;

    while (start < end) {
        while (start < end && *end > pivoKey) {
            end--;
        }

        *start = *end;  // 不用交换，只进行赋值就行了

        while(start < end && *start < pivoKey) {
            start++;
        }

        *end = *start;
    }

    *start = pivoKey;

    return start;  //中枢轴位置
}
