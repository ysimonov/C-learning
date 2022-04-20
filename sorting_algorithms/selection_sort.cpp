
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

void SelectionSort(int arr[], int n) {
    unsigned int i, j, k;
    unsigned int idx_min; // index of the smallest element
    for (k=0; k<n-1; k++) {
        idx_min = k;
        for (j=k+1; j<n; j++) {
            if (arr[j] < arr[idx_min]) {
                idx_min = j;
            }
        }
        Swap(&arr[idx_min], &arr[k]);
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

    SelectionSort(arr, n);

    std::cout << "After Sorting: " << std::endl;
    PrintArray(arr, n);

    delete[] arr;

    return EXIT_SUCCESS;
}