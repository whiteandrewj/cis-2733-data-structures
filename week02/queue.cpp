#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
    queue<char> letters;
    string line = "", upperLine = "";
    ifstream inFile;
    ofstream outFile;

    inFile.open("lowercase.txt");
    while(inFile.good()) {
        getline(inFile,line);
        for (char c : line) {
            letters.push(toupper(c));
        }
        letters.push('\n');
    }
    inFile.close();

    outFile.open("UPPERCASE.txt");
    while (!letters.empty()) {
        outFile << letters.front();
        letters.pop();
    }
    outFile.close();

    return 0;
}