#include <bits/stdc++.h>

using namespace std;

int N, cache[10001][3];
char score[100000][3];
int minScore = 100000000, maxScore = -1;
int start;

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            char num;
            cin >> num;
            score[i][j] = num - '0';
        }
    }
}

int solveMin(int depth, int idx) {
    if (depth == N) return 0;

    int& ret = cache[depth - start][idx];
    if (ret != -1) return ret;
    ret = score[depth][idx];

    int tempMinScore[3];
    if (idx == 0) {
        for (int i = 0; i < 2; i++)
            tempMinScore[i] = solveMin(depth+1, i);
        ret += min(tempMinScore[0], tempMinScore[1]);
    }
    else if (idx == 1) {
        for (int i = 0; i < 3; i++)
            tempMinScore[i] = solveMin(depth+1, i);
        ret += min({tempMinScore[0], tempMinScore[1], tempMinScore[2]});
    }
    else if (idx == 2) {
        for (int i = 1; i < 3; i++)
            tempMinScore[i] = solveMin(depth+1, i);
        ret += min(tempMinScore[1], tempMinScore[2]);
    }

    return ret;
}

int solveMax(int depth, int idx) {
    if (depth == N) return 0;

    int& ret = cache[depth - start][idx];
    if (ret != -1) return ret;
    ret = score[depth][idx];

    int tempMaxScore[3];
    if (idx == 0) {
        for (int i = 0; i < 2; i++)
            tempMaxScore[i] = solveMax(depth+1, i);
        ret += max(tempMaxScore[0], tempMaxScore[1]);
    }
    else if (idx == 1) {
        for (int i = 0; i < 3; i++)
            tempMaxScore[i] = solveMax(depth+1, i);
        ret += max({tempMaxScore[0], tempMaxScore[1], tempMaxScore[2]});
    }
    else if (idx == 2) {
        for (int i = 1; i < 3; i++) 
            tempMaxScore[i] = solveMax(depth+1, i);
        ret += max(tempMaxScore[1], tempMaxScore[2]);
    }

    return ret;
}

void solve() {
    int i = 1, flag = 1;
    while (true) {
        for (int j = 0; j < 3; j++) {
            if (N - 10000 * i < 0) {
                start = 0;
                minScore = min(minScore, solveMin(0, j));
                flag = 0;
            }
            else {
                start = N - 10000 * i;
                solveMin(N - 10000 * i, j);
            }
        }

        if (flag == 0) break;

        int temp[3];
        for (int j = 0; j < 3; j++) {
            temp[j] = cache[0][j];
        }
        init();
        for (int j = 0; j < 3; j++) {
            int next = (start >= 10000) ? 10000 : start;
            cache[next][j] = temp[j];
        }
        i++;
    }

    init();

    i = 1, flag = 1;
    while (true) {
        for (int j = 0; j < 3; j++) {
            if (N - 10000 * i < 0) {
                start = 0;
                maxScore = max(maxScore, solveMax(0, j));
                flag = 0;
            }
            else {
                start = N - 10000 * i;
                solveMax(N - 10000 * i, j);
            }
        }

        if (flag == 0) break;
        
        int temp[3];
        for (int j = 0; j < 3; j++) {
            temp[j] = cache[0][j];
        }
        init();
        for (int j = 0; j < 3; j++) {
            int next = (start >= 10000) ? 10000 : start;
            cache[next][j] = temp[j];
        }
        i++;
    }
}

void output() {
    cout << maxScore << " " << minScore;
}

int main() {
    init();
    input();
    solve();
    output();
}