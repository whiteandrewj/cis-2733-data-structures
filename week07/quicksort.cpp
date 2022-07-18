#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;


int partition(int arr[], int start, int end) {
    int pivot = arr[start];

    //get correct position of pivot element
    int count = 0; //"count" is # of elements in the array that are smaller than the pivot element
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) { count++; }
    }
    int pivotIndex = start + count;


    //cout << "partitioning on " << pivotIndex << endl;

    //move pivot element to correct positon
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) { i++; }
        while (arr[j] > pivot) { j--; }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    /*
    cout << "arr after swaps: ";
    for (int i = 0; i < 6; i++) { cout << arr[i] << " "; }
    cout << endl;
    */
    return pivotIndex;

}

void quickSort(int arr[], int start, int end) {
    /*
    cout << "qs iteration from pos " << start << " to " << end << " { ";
    for (int i = start; i < end+1; i++) { cout << arr[i] << " "; }
    cout << "}" << endl;
    */

    if (start >= end) { 
        //cout << "    partition cannot be sorted further" << endl;
        return; 
    } //for when recursive call has sub-segment completely sorted

    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1); //sorting left part
    quickSort(arr, p + 1, end); //sorting right part
}

int main()
{
    const int SZ = 100000;
    int numbers[SZ];
    for (int &n : numbers) { n = rand() % 1000 + 1; }
    auto start = chrono::high_resolution_clock::now();
    sort(numbers, numbers + SZ);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Duration of STL sort algo in milliseconds: " << duration.count() << endl;

    int numbers2[SZ];
    for (int &n : numbers2) { n = rand() % 1000 + 1; }
    start = chrono::high_resolution_clock::now();
    quickSort(numbers2, 0, SZ-1);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Duration of quicksort in milliseconds: " << duration.count() << endl;


    return 0;
}

