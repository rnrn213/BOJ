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
    
    int ret = 0;
    for (int i = idx; i < N; i++) {
        if (arr[i] == val) ret = max(ret, 1 + solve(i + 1, val + 1));
    }
    return ret;
}

int main() {
    input();
    cout << solve(0, 1);
}