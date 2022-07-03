#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    /*
    code modeled after examples found at 
        https://www.geeksforgeeks.org/measure-execution-time-function-cpp/, 
        https://www.geeksforgeeks.org/how-to-sort-an-array-using-stl-in-c/,
        https://appdividend.com/2022/01/19/bubble-sort-in-cpp/
    */
    const int SZ = 100000;
    srand(time(0));
    int numbers[SZ];
    for (int &n : numbers) { n = rand() % 1000 + 1; }
    //for (int n : numbers) { cout << n << " "; } 
    auto start = chrono::high_resolution_clock::now();
    sort(numbers, numbers + SZ);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Duration of STL sort algo in milliseconds: " << duration.count() << endl;


    int numbers2[SZ];
    int temp;
    for (int &n : numbers2) { n = rand() % 1000 + 1; }
    //for (int n : numbers2) { cout << n << " "; }
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < SZ-1; i++) {
        for (int j = 0; j < SZ-i-1; j++) {
            if (numbers2[j] > numbers2[j+1]) {
                temp = numbers2[j];
                numbers2[j] = numbers2[j+1];
                numbers2[j+1] = temp;
            }
        }
    }
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Duration of bubble sort in milliseconds: " << duration.count() << endl;

    return 0;
}
