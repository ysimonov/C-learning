#include <iostream>

void Swap(int* a, int* b) {
    /*
        swapping two values by reference
    */
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void QuickSort(int* arr, int left, int right) {
    int l = left;
    int r = right - 1;
    int size = right - left;

    if (size > 1) { 
        int pivot = arr[rand() % size + l];
        while (l < r) {
            while (arr[r] > pivot && r > l) {
                r--;
            }
            while (arr[l] < pivot && l <= r) {
                l++;
            }
            if (l < r) {
                Swap(&arr[l], &arr[r]);
                l++;
            }
        }
        QuickSort(arr, left, l);
        QuickSort(arr, r, right);
    }
}

int main() {

    unsigned int n;
    unsigned int i;

    std::cout << "Enter size of the array: ";
    std::cin >> n;

    int* arr = new int[n];

    for (i=0; i<n; i++) {
        arr[i] = rand() % 100; // generate a random number between 0 and 99
    }

    std::cout << "Before Sorting: " << std::endl;
    PrintArray(arr, n);

    QuickSort(arr, 0, n);

    std::cout << "After Sorting: " << std::endl;
    PrintArray(arr, n);

    delete[] arr;

    return EXIT_SUCCESS;
}