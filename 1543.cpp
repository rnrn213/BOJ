#include <bits/stdc++.h>

using namespace std;

string s, word;



int main() {
    getline(cin, s);
    getline(cin, word);

    vector<int> countWord(s.size() + 1, 0);
    for (int i = s.size() - word.size(); i >= 0; i--) {
        bool isValid = true;
        for (int j = 0; j < word.size(); j++) {
            if (s[i + j] != word[j]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            countWord[i] = 1 + countWord[i + word.size()];
        }
        else {
            countWord[i] = countWord[i + 1];
        }
    }

    cout << *max_element(countWord.begin(), countWord.end());
}