#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>    

using namespace std;


string cleanAndSort(string str) {
    string cleaned = "";
    
    
    for (char ch : str) {
        if (!isspace(ch)) {
            cleaned += tolower(ch);
        }
    }
    
   
    sort(cleaned.begin(), cleaned.end());
    return cleaned;
}

int main() {
    string word1, word2;

    cout << "Enter the first word/phrase: ";
    getline(cin, word1);

    cout << "Enter the second word/phrase: ";
    getline(cin, word2);

   
    if (cleanAndSort(word1) == cleanAndSort(word2)) {
        cout << "The strings are anagrams.\n";
    } else {
        cout << "The strings are NOT anagrams.\n";
    }

    return 0;
}