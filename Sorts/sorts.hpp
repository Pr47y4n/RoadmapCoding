#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>

namespace sorts {
    void bubbleSort(std::vector<int>& arr);
    void insertionSort(std::vector<int>& arr);
    void mergeSort(std::vector<int>& arr);
    void heapSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& arr);

    int binarySearch(const std::vector<int>& arr, int target);
}

#endif
