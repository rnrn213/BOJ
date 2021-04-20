#include <bits/stdc++.h>

using namespace std;

long long cache[250000];
vector<int> profit;
vector<long long> answers;

void initCache() {
    memset(cache, -1, sizeof(cache));
}

bool input() {
    int N;
    cin >> N;
    if (N == 0) return false;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        profit.push_back(num);
    }
    return true;
}

long long solve(int idx) {
    if (idx == profit.size()) return 0;

    long long& ret = cache[idx];
    if (ret != -1) return ret;
    ret = profit[idx];
    return ret = max(ret, ret + solve(idx + 1));
}

void getAnswer() {
    while (input()) {
        initCache();
        solve(0);
        sort(cache, cache + profit.size(), greater<long long>());
        answers.push_back(cache[0]);
        profit.clear();
    }
}

void output() {
    for (auto ans: answers) {
        cout << ans << '\n';
    }
}

int main() {
    getAnswer();
    output();
}