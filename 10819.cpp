#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
vector<int> A;

int calculate(const vector<int>& picked) {
    int ret = 0;
    for (int i = 0; i < N - 1; i++)
        ret += abs(A[picked[i]] - A[picked[i + 1]]);
    return ret;
}

void solve(int N, vector<int>& picked, int toPick) {
    if (toPick == 0) {
        ans = max(ans, calculate(picked));
        return;
    }

    for (int i = 0; i < N; i++) {
        if (find(picked.begin(), picked.end(), i) == picked.end()) {
            picked.push_back(i);
            solve(N, picked, toPick - 1);
            picked.pop_back();
        }
    }
}

int main() {
    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    vector<int> picked;
    solve(N, picked, N);

    cout << ans;
}