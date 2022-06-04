#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void printArrayTenCol(T arr[], int numElements) {
    int j = 0;
    for (int i = 0; i < numElements; i++) {
        cout << arr[i] << " ";
        j++;
        if ((j % 10) == 0) {
            cout << endl;
            j = 0;
        }
    }
    cout << endl;
}

double getMedian(int arr[], int numElements) {
    //for (int i = 0; i < numElements; i++) { cout << arr[i] << " "; }
    //cout << endl;
    sort(arr, arr+numElements);
    //for (int i = 0; i < numElements; i++) { cout << arr[i] << " "; }
    if ((numElements % 2) == 0) {
        return (arr[numElements/2] + arr[(numElements/2)-1])/2.0;
    } else {
        return arr[numElements/2];
    }
}

double getLowest2D(double arr[][5], int numRows, int numCols) {
    double lowest = arr[0][0];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (lowest > arr[i][j]) { 
                lowest = arr[i][j];
            }
        }
    }
    return lowest;
}

double getHighest2D(double arr[][5], int numRows, int numCols) {
    double highest = arr[0][0];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (highest < arr[i][j]) {
                highest = arr[i][j];
            }
        }
    }
    return highest;
}



int main()
{
    //Exercise 1
    default_random_engine defaultEngine(time(0));
    uniform_int_distribution<int> intDistro(0,100);
    const int SIZE = 20;
    int nums[SIZE];
    for (int i = 0; i < SIZE; i++) {
        nums[i] = intDistro(defaultEngine);
    }
    cout << SIZE << " randomly generated numbers: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl << endl;

    //Exercise 2
    cout << "Same " << SIZE << " numbers in rows of 10: " << endl;
    printArrayTenCol(nums,SIZE);

    //Exercise 3
    uniform_int_distribution<int> alphaAsciiCodes(97,122);
    uniform_int_distribution<int> wordLength(1,7);
    string words[SIZE];
    int length = 0, cnt = 0;

    for (string &w : words) {
        length = wordLength(defaultEngine);
        cnt = 0;
        w = ""; 
        do {
            w.push_back(alphaAsciiCodes(defaultEngine));
            cnt++;
        } while (cnt < length);
    }
    cout << SIZE << " random words: " << endl;
    for (string w : words) {
        cout << w << " ";
    }
    cout << endl;
    cout << "Same words in reverse order: " << endl;
    for (int i = SIZE-1; i > -1; i--) {
        cout << words[i] << " ";
    }
    cout << endl << endl;

    //Exercise 4
    const int SIZE2 = 100;
    int nums2[SIZE2];
    for (int i = 0; i < SIZE2; i++) {
        nums2[i] = intDistro(defaultEngine);
    }
    cout << SIZE2 << " randomly generated numbers:" << endl;
    for (int i = 0; i < SIZE2; i++) { cout << nums2[i] << " "; }
    cout << endl << "Median of set: " << getMedian(nums2, SIZE2) << endl << endl;

    //Exercise 5
    const int ROWS = 5;
    const int COLS = 5;
    double grades[ROWS][COLS];
    uniform_real_distribution<double> gradeDistro(60,100);
    double temp;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp = gradeDistro(defaultEngine);
            grades[i][j] = round(temp * 100.0)/100.0;
        }
    }
    cout << ROWS * COLS << " randomly generated grades: " << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Lowest grade in array: " << getLowest2D(grades, ROWS, COLS) << endl;
    cout << "Highest grade in array: " << getHighest2D(grades, ROWS, COLS) << endl;
    



    return 0;
}