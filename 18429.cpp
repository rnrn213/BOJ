#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;

int solve(vector<int>& isUsed, int num) {
    if (isUsed.size() == N)
        return 1;
    
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (find(isUsed.begin(), isUsed.end(), i) == isUsed.end() &&
            num + A[i] - K >= 0) {
                isUsed.push_back(i);
                ret += solve(isUsed, num + A[i] - K);
                isUsed.pop_back();
            }
    }

    return ret;
}

int main() {
    cin >> N >> K;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> isUsed;

    cout << solve(isUsed, 0);
}