#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    auto f = []() -> int { return rand() % 10000; };
    int arr[10000];
    // Fill up the vector


    auto arr_size = sizeof(arr) / sizeof(arr[0]);
    generate(arr, arr +arr_size, f);

    cout << "Given array is \n";
    printArray(arr, arr_size);
    auto start = high_resolution_clock::now();
    quickSort(arr,0,arr_size-1);
    auto stop = high_resolution_clock::now();
    cout << "\n\n\n\nSorted array is \n";
    printArray(arr, arr_size);

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n\n\n\nTime taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}
