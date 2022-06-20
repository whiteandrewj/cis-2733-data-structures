#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

string scrubString(string str) {
    string strCleaned = "";
    for (char c : str) {
        if (c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5'
        && c!='6' && c!='7' && c!='8' && c!='9' && c!='.' && c!=','
        && c!='!' && c!='?' && c!='"' && c!='(' && c!=')' && c!=';'
        && c!=':') {
            strCleaned.push_back(tolower(c));
        }
    }
    return strCleaned;
}

void parseStringToWords(string str, set<string> &words) {
    if (str!="") {
        string word = "";
        str.push_back(' ');
        for (char c : str) {
            if (c!=' ') {
                word.push_back(c);
            } else {
                if (word!="") {
                    words.insert(word);
                    word = "";
                }
            }
        }
    }
}

int main()
{
    set<string> words;
    ifstream inFile;
    string line;

    inFile.open("modest_proposal.txt");
    while (inFile.good()) {
        getline(inFile,line);
        line = scrubString(line);
        parseStringToWords(line, words);
    }
    inFile.close();

    for (string s : words) {
        cout << s << " ";
    }
    cout << endl << "Total number of unique words: " << words.size() << endl;

    return 0;
}