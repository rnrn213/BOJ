#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K, cache[1000001];

int solve(int num)
{
    if (num == N) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    ret = INF;

    ret = min(ret, 1 + solve(num + 1));
    if (num > 1 && num + num / 2 <= N)
        ret = min(ret, 1 + solve(num + num / 2));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;

    if (solve(0) <= K) cout << "minigimbob";
    else cout << "water";
}