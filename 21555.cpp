#include <bits/stdc++.h>

using namespace std;

int N, K;
long long cost[2][200000], cache[2][200000];
const long long MAXCOST = 200000 * pow(10, 9) + 1;

long long solve(int isA, int idx) {
    if (idx == N)
        return 0;
    
    long long& ret = cache[isA][idx];
    if (ret != -1)
        return ret;

    return ret = min(cost[isA][idx] + solve(isA, idx+1), cost[isA][idx] + K + solve(!isA, idx+1));;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    solve(0, 0);
    solve(1, 0);

    cout << min(cache[0][0], cache[1][0]);
}