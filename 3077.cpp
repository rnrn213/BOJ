#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> answer(N);
    vector<int> hyunwoo(N);
    for (int i = 0; i < N; i++) {
        cin >> answer[i];
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int idx = 0;
        for (; idx < N; idx++) {
            if (answer[idx] == s) break;
        }
        hyunwoo[i] = idx;
    }

    int point = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (hyunwoo[i] < hyunwoo[j]) point++;
        }
    }

    cout << point << "/" << (N * (N - 1)) / 2;
}