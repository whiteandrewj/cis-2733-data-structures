#include <iostream>
#include <map>

using namespace std;

void popDictUsr(multimap<string, string> *dict) {
    string cont = "y";
    string word, definition;
    while (cont == "y") {
        cout << "Please enter a word: ";
        getline(cin, word);
        cout << "Please enter the word's definition: ";
        getline(cin, definition);
        dict->insert({word,definition});
        cout << "Add another? (y/n): ";
        getline(cin, cont);
    }
}

void popDictHrdCd(multimap<string, string> *dict) {
    dict->insert({"abstract","not material/concrete"});
    dict->insert({"abstract","a summary"});
    dict->insert({"right","direction. opposite of left"});
    dict->insert({"right","correct"});
    dict->insert({"arm","upper appendage"});
    dict->insert({"arm","to take up a weapon or make ready for war"});
    dict->insert({"lie","to lay down"});
    dict->insert({"lie","to tell an untruth"});
}

void displayDictionary(multimap<string, string> *dict) {
    for (auto iter = dict->begin(); iter !=dict->end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}

void displayDefinitions(multimap<string, string> *dict, string word) {
    for (auto iter = dict->lower_bound(word); iter != dict->upper_bound(word); iter++) {
        cout << "  " << iter->second << endl;
    }
}

int main()
{
    //Assignment #1, Dictionary
    multimap<string, string> dictionary;
    string word = "";
    popDictHrdCd(&dictionary);
    popDictUsr(&dictionary);
    cout << endl << "Contents of dictionary..." << endl;
    displayDictionary(&dictionary);
    cout << endl << "Enter a word to look up: ";
    getline(cin,word);
    cout << "Definitions of " << word << "..." << endl;
    displayDefinitions(&dictionary, word);
   
    return 0;
}