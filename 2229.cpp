#include <bits/stdc++.h>

using namespace std;

int N, cache[1001], score[1001];

int solve(int x) {
    if (x == N) 
        return 0;

    int& ret = cache[x + 1];
    if (ret != -1)
        return ret;
    ret = 0;

    int nowScore = (x == -1) ? score[0] : score[x];
    int minValue = nowScore, maxValue = nowScore;
    for (int i = x + 1; i < N; i++) {
        if (score[i] > maxValue) maxValue = score[i];
        if (score[i] < minValue) minValue = score[i];
        
        ret = max(ret, maxValue - minValue + solve(i + 1));
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    cout << solve(-1);
}