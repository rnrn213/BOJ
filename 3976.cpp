#include <bits/stdc++.h>

using namespace std;

int c, n, l1, l2, s[2], pass[2][100000], dribble[2][100000], cache[2][100000];
vector< int > answers;

void initCache() {
    memset(cache, -1, 2 * 100000 * sizeof(int));
}

void input() {
    cin >> c;
}

int solve(int turn, int pos) {
    if (pos == n) return s[turn];

    int& ret = cache[turn][pos];
    if (ret != -1) return ret;
    int nextTurn = 0;
    if (turn == 0) nextTurn = 1;
    return ret = min(pass[turn][pos] + solve(nextTurn, pos + 1),
                    dribble[turn][pos] + solve(turn, pos + 1));
}

void getAnswer() {
    for (int i = 0; i < c; i++) {
        cin >> n >> l1 >> l2 >> s[0] >> s[1];
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k < n; k++) {
                cin >> pass[j][k];
            }
            for (int k = 1; k < n; k++) {
                cin >> dribble[j][k];
            }
        }

        int ans = min(l1 + solve(0, 1), l2 + solve(1, 1));
        answers.push_back(ans);

        initCache();
    }
}

void output() {
    for (auto ans: answers) {
        cout << ans << "\n";
    }
}

int main() {
    initCache();
    input();
    getAnswer();
    output();
}