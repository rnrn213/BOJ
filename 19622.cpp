#include <bits/stdc++.h>

using namespace std;

int N, cache[100001];
vector<int> conference[3];

void init() {
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < 3; i++) {
        conference[i].push_back(-1);
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int start, end, people;
        cin >> start >> end >> people;
        conference[0].push_back(start);
        conference[1].push_back(end);
        conference[2].push_back(people);
    }
}

int solve(int idx) {
    if (idx == N) return cache[N] = conference[2][N];

    int& ret = cache[idx];
    if (ret != -1) return ret;
    return ret = max(solve(idx + 1), conference[2][idx] + solve(idx + 2));
}

int getAnswer() {
    cache[N] = conference[2][N];
    cache[N - 1] = max(conference[2][N], conference[2][N - 1]);
    for (int i = N - 2; i >= 1; i--) {
        solve(i);
    }
    return *max_element(cache + 1, cache + N + 1);
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    init();
    input();
    cout << getAnswer();
}