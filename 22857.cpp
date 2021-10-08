#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> S, oddNumIndex;

vector<int> getOddNumIndex() {
    vector<int> ret = {-1};

    for (int i = 0; i < N; i++) {
        if (S[i] % 2 == 1)
            ret.push_back(i);
    }
    ret.push_back(N);

    return ret;
}

int main() {
    cin >> N >> K;
    S = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    oddNumIndex = getOddNumIndex();

    int ans = 0;
    for (int d = 0; d <= K; d++) {
        int maxLength = 0;
        for (int i = 0; i < oddNumIndex.size() - 1 - d; i++) {
            if (oddNumIndex[i + d + 1] - oddNumIndex[i] - d - 1 > maxLength) {
                maxLength = oddNumIndex[i + d + 1] - oddNumIndex[i] - d - 1;
            }
        }
        if (maxLength > ans) {
            ans = maxLength;
        }
    }

    cout << ans;
}