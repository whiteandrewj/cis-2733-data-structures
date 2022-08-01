#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

bool isOdd(int num) {
    if (num % 2 == 1) { return true; }
    else { return false; }
}

int main()
{
    srand(time(0));
    
    //replace/remove problem #3
    int numberToRemove = 0;
    vector<int> numbers;
    for (int i = 0; i < 20; i++) {
        numbers.push_back(rand() % 100 +1);
    }
    sort(numbers.begin(),numbers.end());
    cout << "Please enter a number to remove from this sequence: ";
    for (int n : numbers) { cout << n << " "; }
    cout << endl << ": ";
    cin >> numberToRemove;
    remove(numbers.begin(),numbers.end(),numberToRemove);
    cout << "Resulting sequence: ";
    for (int n : numbers) { cout << n << " "; }
    cout << endl << endl;

    //replace/remove problem #4
    vector<int> numbers2;
    for (int i = 0; i < 30; i++) {
        numbers2.push_back(rand() % 100 +1);
    }
    sort(numbers2.begin(),numbers2.end());
    cout << "30 random numbers: ";
    for (int n : numbers2) { cout << n << " "; }
    cout << endl << "Removing odd numbers from sequence..." << endl;
    auto pos = remove_if(numbers2.begin(),numbers2.end(),isOdd);
    numbers2.erase(pos,numbers2.end());
    cout << "Remaining numbers: ";
    for (int n : numbers2) { cout << n << " "; }
    cout << endl << endl;

    //replace/remove problem #5
    vector<int> numbers3;
    for (int i = 0; i < 30; i++) {
        numbers3.push_back(rand() % 100 +1);
    }
    sort(numbers3.begin(),numbers3.end());
    cout << "30 random numbers: ";
    for (int n : numbers3) { cout << n << " "; }
    cout << endl << "Removing numbers between 0 and 49 from sequence..." << endl;
    auto pos2 = remove_if(numbers3.begin(),numbers3.end(),[](int n) { if (n < 50 && n > 0) { return true;} else { return false; } });
    numbers3.erase(pos2,numbers3.end());
    cout << "Remaining numbers: ";
    for (int n : numbers3) { cout << n << " "; }
    cout << endl << endl;

    return 0;
}