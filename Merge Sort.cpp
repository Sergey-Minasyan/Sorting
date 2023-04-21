#include <vector>
#include <iostream>

void merge(std::vector<int>& arr, std::vector<int>& tmp, int lowerIndex, int middle, int upperIndex)
{
    int lowerStart = lowerIndex;
    int lowerStop = middle;
    int upperStart = middle + 1;
    int upperStop = upperIndex;
    int count = lowerIndex;

    while (lowerStart <= lowerStop && upperStart <= upperStop)
    {
        if (arr[lowerStart] < arr[upperStart])
        {
            tmp[count] = arr[lowerStart];
            ++count;
            ++lowerStart;
        }
        else
        {
            tmp[count] = arr[upperStart];
            ++count;
            ++upperStart;
        }
    }
    while (lowerStart <= lowerStop)
    {
        tmp[count] = arr[lowerStart];
        ++count;
        ++lowerStart;
    }
    while (upperStart <= upperStop)
    {
        tmp[count] = arr[upperStart];
        ++count;
        ++upperStart;
    }

    for (int i = lowerIndex; i <= upperIndex; ++i)
    {
        arr[i] = tmp[i];
    }
}

void mergesort(std::vector<int>& arr, std::vector<int>& tmp, int lowerIndex, int upperIndex)
{
    if (lowerIndex >= upperIndex)
    {
        return;
    }
    int middle = (lowerIndex + upperIndex) / 2;
    mergesort(arr, tmp, lowerIndex, middle);
    mergesort(arr, tmp, middle + 1, upperIndex);
    merge(arr, tmp, lowerIndex, middle, upperIndex);
}
