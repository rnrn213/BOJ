#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, wordSize;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    wordSize = words[0].size();

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            vector<char> v(26);
            vector<bool> isUsed(26, false), isSelected(26, false);

            bool isPair = true;
            for (int k = 0; k < wordSize; k++) {
                if (isUsed[words[i][k] - 'a']) {
                    if (words[j][k] != v[words[i][k] - 'a']) {
                        isPair = false;
                        break;
                    }
                }
                else {
                    if (isSelected[words[j][k] - 'a']) {
                        isPair = false;
                        break;
                    }

                    v[words[i][k] - 'a'] = words[j][k];
                    isUsed[words[i][k] - 'a'] = isSelected[words[j][k] - 'a'] = true;
                }
            }

            if (isPair) {
                cnt++;
            }
        }
    }

    cout << cnt;
}