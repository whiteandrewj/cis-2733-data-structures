#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> genYWords() {
    vector<string> words;
    words.push_back("family");
    words.push_back("doggy");
    words.push_back("kitty");
    words.push_back("city");
    words.push_back("candy");
    words.push_back("froggy");
    words.push_back("library");
    words.push_back("study");
    words.push_back("bakery");
    return words;
}
vector<string> genMixedWords() {
    vector<string> words;
    words.push_back("family");
    words.push_back("house");
    words.push_back("foot");
    words.push_back("city");
    words.push_back("candy");
    words.push_back("kitty");
    words.push_back("library");
    words.push_back("station");
    words.push_back("bakery");
    return words;
}
string currentWord = "";
void setcurrentWord(string w) {
    currentWord = w;
}
bool isYWord(string word) {
    if (word.back() == 'y' && word == currentWord) {
        //cout << word << " ends in 'y'" << endl;
        return true;
    } else {
        //cout << word << " doesn't end in 'y'" << endl;
        return false;
    }
}
string pluralizeYWord(string word) {
    word.pop_back();
    word = word + "ies";
    return word;
}

int main()
{
    vector<string> yWords = genYWords();
    for (string w : yWords) { cout << w << " "; }
    for (string w : yWords) {
        replace(yWords.begin(),yWords.end(),w,pluralizeYWord(w));
    }
    for (string w : yWords) { cout << w << " "; }

    vector<string> mixedWords = genMixedWords();
    for (string w : mixedWords) { cout << w << " "; }
    for (string w : mixedWords) {
        setcurrentWord(w);
        replace_if(mixedWords.begin(),mixedWords.end(),isYWord,pluralizeYWord(w));
    }
    for (string w : mixedWords) { cout << w << " "; }
    

    return 0;
}