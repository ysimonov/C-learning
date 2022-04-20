
#include <iostream>

void PrintArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Merge(int* arr, int from, int to, int mid) {
    
    int i = from;
    int j = mid + 1;
    int k = 0;

    int* temp = new int[to-from+1];

    // merge two parts into temp
    while (i<=mid && j <= to) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++; i++;
        } else {
            temp[k] = arr[j];
            k++; j++;
        }
    }

    // insert all the remaining values from i to mid into temp[]
    while (i<=mid) {
        temp[k] = arr[i];
        k++; i++;
    }

    // insert all the remaining values from j to to into temp[]
    while (j <= to) {
        temp[k] = arr[j];
        k++; j++;
    }

    // assign sorted data stored in temp[] to arr[]
    for (i=from; i<=to; i++) {
        arr[i] = temp[i-from];
    }

    delete[] temp;
}

void MergeSort(int* arr, int from, int to) {
    int mid;
    if (from < to) {
        mid = (from+to)/2;        
        MergeSort(arr, from, mid);
        MergeSort(arr, mid+1, to);
        Merge(arr, from, to, mid);
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

    MergeSort(arr, 0, n-1);

    std::cout << "After Sorting: " << std::endl;
    PrintArray(arr, n);

    delete[] arr;

    return EXIT_SUCCESS;
}