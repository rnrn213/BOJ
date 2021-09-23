#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;
    vector<string> files(N);
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }

    string front = pattern.substr(0, pattern.find('*')), 
            back = pattern.substr(pattern.find('*') + 1, string::npos);
    for (int i = 0; i < N; i++) {
        if (files[i].size() < front.size() + back.size()) {
            cout << "NE\n";
            continue;
        }

        if (files[i].substr(0, front.size()) == front && 
                files[i].substr(files[i].size() - back.size(), string::npos) == back)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
}