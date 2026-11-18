#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main() {
    string s;
    int vowels = 0;
    int consonants = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);
    for (char ch : s) {
        if (isalpha(ch)) {
            char lowerCh = tolower(ch);

            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    cout << "Vowels: " << vowels << "\n";
    cout << "Consonants: " << consonants << "\n";

    return 0;
}