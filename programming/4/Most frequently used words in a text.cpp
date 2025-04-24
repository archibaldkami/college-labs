#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype> // Для tolower() не видаляй
#include <cassert>
#include <unordered_map>
#include <bits/stdc++.h> // deque

using namespace std;

string getText(string filename) {
    string result = "";
    fstream file(filename);
    string line;
    while (getline(file, line)) {
        result += line;
    }
    return result;
}

bool isCharAllowed(char character, const string& allowedList) {
    return allowedList.find(character) != string::npos;
}

vector<string> getCleanText(string& inputText) {
    const string allowedList = "abcdefghijklmnopqrstuvwxyz'-";
    vector<string> result;
    string word = "";
    for (int i = 0; i < inputText.size(); i++) {
        if (isCharAllowed(tolower(inputText[i]), allowedList)) word += tolower(inputText[i]);
        else {
            if (word.size()) {
                result.push_back(word);
                word = "";
            }
        }
    }
    return result;
}

void cvout(vector<string> inputVector, int maxLen = 50) {    // C++ Vector Out
    int n = 0;
    for (int i = 0; i < inputVector.size(); i++) {
        if ( n > maxLen ) {
            cout << endl;
            n = 0;
        }
        cout << inputVector[i] << " ";
        n += inputVector[i].size();
    }
    cout << endl;
}

void cumout(unordered_map<string, int> inputMap, int filter = 0) {     // C Unordered Map Out
    for (auto& [key, value] : inputMap) {
        if (value >= filter) cout << endl << "Key: " << key << endl << "Value: " << value << endl;
    }
}

unordered_map<string, int> getWordFrequency(vector<string> inputText) {
    unordered_map<string, int> wordFrequencyMap;
    for (int i = 0; i < inputText.size(); i++) wordFrequencyMap[inputText[i]]++;
    return wordFrequencyMap;
}

vector<string> getMostFrequentWords(string inputText) {

    unordered_map<string, int> inputUM = getWordFrequency(getCleanText(inputText));
    if (!inputUM.size()) return {};

    deque<int> intResult = {0, 0, 0};
    deque<string> stringResult = {"&", "&", "&"};

    for (auto& [word, frequency] : inputUM) {
        if (frequency > intResult[0]) {
            intResult.push_front(frequency);
            stringResult.push_front(word);

        } else if (frequency > intResult[1]) {
            intResult.insert(intResult.begin() + 1, frequency);
            stringResult.insert(stringResult.begin() + 1, word);

        } else if (frequency > intResult[2]) {
            intResult.insert(intResult.begin() + 2, frequency);
            stringResult.insert(stringResult.begin() + 2, word);
        } else continue;

        if (intResult.size() > 3) intResult.pop_back();
        if (stringResult.size() > 3) stringResult.pop_back();
    }


    if (stringResult[1] == "&") return {stringResult[0]};
    else if (stringResult[2] == "&") return {stringResult[0], stringResult[1]};
    
    return {stringResult[0], stringResult[1], stringResult[2]};
}

void testIt(string In, vector<string> supposedOut) {
    assert(getMostFrequentWords(In) == supposedOut);
}

int main() {

    string example_1 = getText("example_1.txt"); 
    string example_2 = getText("example_2.txt"); 
    string example_3 = "e e e e DDD ddd DdD: ddd ddd aa aA Aa, bb cc cc e e e";
    string example_4 = "  //wont won't won't";

    testIt(example_1, {"a", "of", "on"});
    testIt(example_2, {"their", "and", "the"});
    testIt(example_3, {"e", "ddd", "aa"});
    testIt(example_4, {"won't", "wont"});

    cout << "All tests \033[1;32mpassed\033[0m :3" << endl;
    return 0;
}