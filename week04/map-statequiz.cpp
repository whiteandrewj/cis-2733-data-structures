#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

void popCapitals(map<string, string> *capitals) {
    capitals->insert({"Alabama","Montgomery"});
    capitals->insert({"Alaska","Juneau"});
    capitals->insert({"Arizona","Phoenix"});
    capitals->insert({"Arkansas","Little Rock"});
    capitals->insert({"California","Sacramento"});
    capitals->insert({"Colorado","Denver"});
    capitals->insert({"Connecticut","Hartford"});
    capitals->insert({"Delaware","Dover"});
    capitals->insert({"Florida","Tallahassee"});
    capitals->insert({"Georgia","Atlanta"});
    capitals->insert({"Hawaii","Honolulu"});
    capitals->insert({"Idaho","Boise"});
    capitals->insert({"Illinois","Springfield"});
    capitals->insert({"Indiana","Indianapolis"});
    capitals->insert({"Iowa","Des Moines"});
    capitals->insert({"Kansas","Topeka"});
    capitals->insert({"Kentucky","Frankfort"});
    capitals->insert({"Louisiana","Baton Rouge"});
    capitals->insert({"Maine","Augusta"});
    capitals->insert({"Maryland","Annapolis"});
    capitals->insert({"Massachusetts","Boston"});
    capitals->insert({"Michigan","Lansing"});
    capitals->insert({"Minnesota","Saint Paul"});
    capitals->insert({"Mississippi","Jackson"});
    capitals->insert({"Missouri","Jefferson City"});
    capitals->insert({"Montana","Helena"});
    capitals->insert({"Nebraska","Lincoln"});
    capitals->insert({"Nevada","Carson City"});
    capitals->insert({"New Hampshire","Concord"});
    capitals->insert({"New Jersey","Trenton"});
    capitals->insert({"New Mexico","Santa Fe"});
    capitals->insert({"New York","Albany"});
    capitals->insert({"North Carolina","Raleigh"});
    capitals->insert({"North Dakota","Bismarck"});
    capitals->insert({"Ohio","Columbus"});
    capitals->insert({"Oklahoma","Oklahoma City"});
    capitals->insert({"Oregon","Salem"});
    capitals->insert({"Pennsylvania","Harrisburg"});
    capitals->insert({"Rhode Island","Providence"});
    capitals->insert({"South Carolina","Columbia"});
    capitals->insert({"South Dakota","Pierre"});
    capitals->insert({"Tennessee","Nashville"});
    capitals->insert({"Texas","Austin"});
    capitals->insert({"Utah","Salt Lake City"});
    capitals->insert({"Vermont","Montpelier"});
    capitals->insert({"Virginia","Richmond"});
    capitals->insert({"Washington","Olympia"});
    capitals->insert({"West Virginia","Charleston"});
    capitals->insert({"Wisconsin","Madison"});
    capitals->insert({"Wyoming","Cheyenne"});
}

void popStates(map<string, string> stateCapitals,  string states[]) {
    int counter = 0;
    for (pair<string, string> capital : stateCapitals) {
        states[counter] = capital.first;
        counter++;
    }
}

int main()
{
   //Assignment #2, state capital quiz
    map<string, string> stateCapitals;
    popCapitals(&stateCapitals);
    
    string states[stateCapitals.size()];
    popStates(stateCapitals, states);

    srand(time(0));
    string cont = "y", answer, state, capital;
    while (cont == "y") {
        state = states[rand() % (stateCapitals.size() - 1)];
        capital = stateCapitals.at(state);
        cout << "What is the capital of " << state << "? " ;
        getline(cin,answer);
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        transform(capital.begin(), capital.end(), capital.begin(), ::tolower);
        if (answer == capital) {
            cout << "Correct! "; 
        } else {
            cout << "Sorry, that's incorrect. ";
        }
        cout << "The capital of " << state << " is " << stateCapitals.at(state) << endl;
        cout << "Answer another? (y/n) : ";
        getline(cin, cont);
    }
    return 0;
}