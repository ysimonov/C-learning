
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

void InsertionSort(int arr[], int n) {
    unsigned int i, j;
    for (i=1; i<n; i++) {
        j = i;
        while (j>0 && arr[j-1]>arr[j]) {
            Swap(&arr[j], &arr[j-1]);
            j-=1;
        }
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

    InsertionSort(arr, n);

    std::cout << "After Sorting: " << std::endl;
    PrintArray(arr, n);

    delete[] arr;

    return EXIT_SUCCESS;
}