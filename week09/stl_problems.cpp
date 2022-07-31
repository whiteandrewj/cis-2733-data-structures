#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> genIntVector(int size) {
    srand(time(0));
    vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(rand() % 500 + 1);
    }
    return vec;
}
void printIntVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << " ";
    }
}



bool isLessThan50(int num) {
    if (num < 50) {
        cout << num;
        return true;
    } else { return false; }
}

int main()
{
    vector<int> numbers = genIntVector(200);
    printIntVector(numbers);
    for_each(numbers.begin(),numbers.end(),isLessThan50);
    //i need to use the iterator to find the position
    

    return 0;
}