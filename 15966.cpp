#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
}

int solve(int idx, int val) {
    if (idx == N) return 0;

    int ret = 1;
    for (int i = idx + 1; i < N; i++) {
        if (arr[i] == val + 1) ret = max(ret, 1 + solve(i, arr[i]));
    }
    return ret;
}

int getAnswer() {
    int ans = 1;

    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i, arr[i]));
    }
    return ans;
}

int main() {
    input();
    cout << getAnswer();
}