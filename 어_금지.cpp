#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, t[100001], b[100001], c[100001], prevV[100001];
pair< int, int > p[100002];
ll cache[100001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        b[i] = t[i] - x;

        p[i] = make_pair(b[i], i);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }

    sort(p + 1, p + 1 + N);
    p[N + 1] = make_pair(2000000000, -1);

    int j = 1;
    for (int i = 1; i <= N; i++)
    {
        while (p[i].first > t[j] && j <= N) j++;
        prevV[p[i].second] = j - 1;
    }

    for (int i = 1; i <= N; i++)
    {
        cache[i] = max(c[i] + cache[prevV[i]], cache[i - 1]);
    }

    cout << cache[N];
}