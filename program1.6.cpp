#include <iostream>
#include <string>
#include <sstream> 
#include <vector>  

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    cout << "Reversed word order: ";
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) {
            cout << " "; 
        }
    }
    cout << "\n";

    return 0;
}
