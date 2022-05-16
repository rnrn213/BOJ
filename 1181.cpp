#include <bits/stdc++.h>

using namespace std;

bool cmp(string u, string v) {
    if (u.size() == v.size()) {
        return u < v;
    }
    else {
        return u.size() < v.size();
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), cmp);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (auto word: words) {
        cout << word << "\n";
    }
}