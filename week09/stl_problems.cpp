#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> genIntVector(int size) {
    vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back(rand() % 100 + 1);
    }
    return vec;
}
void printIntVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << " ";
    }
    cout << endl;
}
bool isLT50(int n) {
    if (n < 50) {
        return true;
    } else { return false; }
}
bool isEven(int n) {
    if (n % 2 == 0) { return true; }
    else { return false; }
}
bool isOdd(int n) {
    if (n % 2 == 1) { return true; }
    else { return false; }
}

int main()
{
    srand(time(0));
    //algo from STL problem #1
    vector<int> numbers = genIntVector(20);
    printIntVector(numbers);
    auto pos = find_if(numbers.begin(),numbers.end(),isLT50);
    cout << "first occurence less than 50 is '" << *pos << "' at position " << (pos - numbers.begin()) << endl << endl;

    //algo from STL problem #2
    numbers = genIntVector(20);
    printIntVector(numbers);
    pos = find_if(numbers.begin(),numbers.end(),[](int n) { if (n < 50) { return true; } else { return false; } });
    cout << "first occurence less than 50 is '" << *pos << "' at position " << (pos - numbers.begin()) << endl << endl;

    cout <<"-------------------------------------------------------------" << endl << endl;

    //algo from STL problem #3
    vector<int> evenNumbers1 = genIntVector(20);
    printIntVector(evenNumbers1);
    int cnt = count_if(evenNumbers1.begin(),evenNumbers1.end(),isEven);
    cout << "Number of even elements: " << cnt << endl << endl;

    //algo from STL problem #4
    vector<int> evenNumbers2 = genIntVector(20);
    printIntVector(evenNumbers2);
    cnt = count_if(evenNumbers2.begin(),evenNumbers2.end(),[](int n) { if (n % 2 == 0) { return true; } else { return false; }});
    cout << "Number of even elements: " << cnt << endl << endl;

    //algo from STL problem #5
    pos = remove_if(evenNumbers1.begin(),evenNumbers1.end(),isOdd);
    evenNumbers1.erase(pos,evenNumbers1.end());
    cout << cnt << " elements removed from first 'even' vector." << endl << "Resultant elements: ";
    printIntVector(evenNumbers1);

    //algo from STL problem #6
    pos = remove_if(evenNumbers2.begin(),evenNumbers2.end(),[](int n) { if (n % 2 == 1) { return true; } else { return false; }} );
    evenNumbers2.erase(pos,evenNumbers2.end());
    cout << cnt << " elements removed from second 'even' vector." << endl << "Resultant elements: ";
    printIntVector(evenNumbers2);

    return 0;
}