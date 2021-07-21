#include <bits/stdc++.h>

using namespace std;

bool isValid(const vector<string>& words, const vector<string>& temp) {
    vector<string> tempWords = words;
    for (int i = 0; i < temp.size(); i++) {
        tempWords.erase(find(tempWords.begin(), tempWords.end(), temp[i]));
    }
    for (int i = 0; i < 3; i++) {
        string word = "";
        for (int j = 0; j < 3; j++) {
            word = word + temp[j][i];
        }
        auto it = find(tempWords.begin(), tempWords.end(), word);
        if (it != tempWords.end()) tempWords.erase(it);
    }
    if (tempWords.size() == 0) return true;
    else return false;
}

vector<string> getPuzzle(const vector<string>& words) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i != j) {
                for (int k = 0; k < 6; k++) {
                    if (i != k && j != k) {
                        vector<string> temp = {words[i], words[j], words[k]};
                        if (isValid(words, temp)) return temp;
                    }
                }
            }
        }
    }
    return vector<string>(0);
}

int main() {
    vector<string> ans, words;
    for (int i = 0; i < 6; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    ans = getPuzzle(words);
    if (ans.size() == 0) cout << 0;
    else {
        for (auto w: ans) {
            cout << w << "\n";
        }
    }
}