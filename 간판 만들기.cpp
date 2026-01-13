#include <bits/stdc++.h>

using namespace std;

const long long INF = 10000000000;

int N, a[300001];
long long arr[6][300001];
string S, U = "UOSPC";

int main()
{
    cin.tie();
    ios_base::sync_with_stdio(false);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= 5; i++)
    {
        arr[i][0] = INF;
        for (int j = 1; j <= N; j++)
        {
            if (S[j - 1] == U[i - 1]) arr[i][j] = min(a[j - 1] + arr[i - 1][j], arr[i][j - 1]);
            else arr[i][j] = arr[i][j - 1];
        }
    }

    if (arr[5][N] == INF) cout << -1;
    else cout << arr[5][N];
}
