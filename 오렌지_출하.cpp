#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll)1000000000 * 20001;

int N, M;
ll K, A[20001];
ll cache[20001];

ll solve(int idx)
{
    if (idx == N) return 0;

    ll& ret = cache[idx];
    if (ret != -1) return ret;
    ret = min(INF, K + solve(idx + 1));

    ll maxSize = A[idx], minSize = A[idx];
    for (int i = 1; i < M; i++)
    {
        if (idx + i == N) break;
        
        if (A[idx + i] > maxSize) maxSize = A[idx + i];
        if (A[idx + i] < minSize) minSize = A[idx + i];
        ret = min(ret, K + (i + 1) * (maxSize - minSize) + solve(idx + i + 1));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << solve(0);
}