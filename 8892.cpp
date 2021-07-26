#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string word) {
    int front = 0, back = word.size() - 1;
    while (front < back) {
        if (word[front] != word[back]) return false;
        front++;
        back--;
    }
    return true;
}

string getPalindrome(const vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i != j && isPalindrome(words[i] + words[j])) {
                return words[i] + words[j];
            }
        }
    }
    return "0";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int k;
        cin >> k;
        vector<string> words(k);
        for (int j = 0; j < k; j++) {
            cin >> words[j];
        }
        cout << getPalindrome(words) << "\n";
    }
}