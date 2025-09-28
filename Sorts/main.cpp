#include <iostream>
#include "sorts.hpp"

void printVector(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {64, 25, 12, 22, 11};

    std::cout << "Original array:\n";
    printVector(data);

    std::vector<int> arr1 = data;
    sorts::bubbleSort(arr1);
    std::cout << "Bubble Sort: ";
    printVector(arr1);

    std::vector<int> arr2 = data;
    sorts::insertionSort(arr2);
    std::cout << "Insertion Sort: ";
    printVector(arr2);

    std::vector<int> arr3 = data;
    sorts::mergeSort(arr3);
    std::cout << "Merge Sort: ";
    printVector(arr3);

    std::vector<int> arr4 = data;
    sorts::heapSort(arr4);
    std::cout << "Heap Sort: ";
    printVector(arr4);

    std::vector<int> arr5 = data;
    sorts::quickSort(arr5);
    std::cout << "Quick Sort: ";
    printVector(arr5);

    int target = 22;
    int index = sorts::binarySearch(arr5, target);
    if (index != -1)
        std::cout << "Found " << target << " at index " << index << "\n";
    else
        std::cout << target << " not found.\n";

    return 0;
}
