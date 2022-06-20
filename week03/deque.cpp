#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main()
{
    deque<char> letters;
    string line;
    ifstream inFile;
    ofstream outFile;

    inFile.open("lowercase.txt");
    while (inFile.good()) {
        getline(inFile,line);
        for (char c : line) {
            letters.push_back(toupper(c));
        }
        letters.push_back('\n');
    }
    inFile.close();

    outFile.open("UPPERCASE.txt");
    while (!letters.empty()) {
        outFile << letters.front();
        letters.pop_front();
    }
    outFile.close();

    return 0;
}