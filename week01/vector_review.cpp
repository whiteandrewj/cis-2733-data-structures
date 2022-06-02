#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void printVectorForward(vector<T> &vec) {
    for (T element : vec) {
        cout << element << " ";
    }
}

template <typename T>
void printVectorBackward(vector<T> &vec) {
    for (int i = vec.size()-1; i > -1; i--) {
        cout << vec[i] << " ";
    }
}

void printHighest(vector<int> &vec) {
    int highest = vec.at(0);
    for (int element : vec) {
        if (highest < element) { highest = element; }
    }
    cout << highest;
}

void printLowest(vector<int> &vec) {
    int lowest = vec.at(0);
    for (int element : vec) {
        if (lowest > element) { lowest = element; }
    }
    cout << lowest;
}

vector<string> populateStringVecUsr(int size) {
    vector<string> words;
    string word = "";
    for (int i = 0; i < size; i++) {
        cout << "Please enter a word: ";
        cin >> word;
        words.push_back(word);
    }
    return words;
}

void printLongest(vector<string> &vec) {
    string longest = vec.at(0);
    for (string element : vec) {
        if (longest.length() < element.length()) {
            longest = element;
        }
    }
    cout << longest;
}

vector<int> populateIntVecRand(int size, int floor, int ceiling) {
    default_random_engine defEngine(time(0));
    uniform_int_distribution<int> intDistro(floor,ceiling);
    vector<int> nums;
    for (int i = 0; i < size; i++) {
        nums.push_back(intDistro(defEngine));
    }
    return nums;
}

double getMedian(vector<int> nums) {
    int index, index2;
    double median;
    sort(nums.begin(),nums.end());
    //cout << "Numbers sorted..." << endl;
    //printVectorForward(nums);
    if ((nums.size() % 2) == 1) {
        index = nums.size()/2;
        //cout << endl << "odd index: " << index;
        median = nums.at(index);
    } else {
        index = (nums.size()/2)-1;
        //cout << endl << "even index 1: " << index;
        index2 = nums.size()/2;
        //cout << endl << "even index 2: " << index2;
        median = (nums.at(index) + nums.at(index2))/2.0;
    }
    return median;
}

int main() 
{
    //Exercise 1
    vector<string> names = {"Andrew","Daniel","Gabriel","Joshua","Nathanael"};
    cout << "Names in vector: ";
    for (string name : names ) {
        cout << name << " ";
    }
    cout << endl << "Names in vector reversed: ";
    for (int i = names.size()-1; i > -1; i--) {
        cout << names[i] << " ";
    }
    
    //Exercise 2
    cout << endl << "Names in vector (function): ";
    printVectorForward(names);
    cout << endl << "Names in vector reversed (function): ";
    printVectorBackward(names);

    //Exercise 3
    default_random_engine defEngine(time(0));
    uniform_int_distribution<int> intDistro(60,100);
    const int VECSIZE = 10;
    vector<int> grades;
    for (int i = 0; i < VECSIZE; i++) {
        grades.push_back(intDistro(defEngine));
    }
    cout << endl << "10 random grades: ";
    printVectorForward(grades);
    cout << endl << "Highest grade: ";
    printHighest(grades);
    cout << endl << "Lowest grade: ";
    printLowest(grades);

    //Exercise 4
    cout << endl << "Prompting user for strings to populate vector..." << endl;
    vector<string> words = populateStringVecUsr(5);
    cout << "The words entered were: ";
    printVectorForward(words);
    cout << endl << "The longest word was: ";
    printLongest(words);

    //Exercise 5
    cout << endl << "Creating a vector of 100 random numbers..." << endl;
    vector<int> numbers = populateIntVecRand(100,0,100);
    printVectorForward(numbers);
    cout << endl;
    cout << "Median # in vector: " << getMedian(numbers) << endl;

    return 0;
}