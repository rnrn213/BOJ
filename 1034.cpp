#include <bits/stdc++.h>

using namespace std;

int N, M, K, ans = 0;
vector<string> lamps(50);
vector<bool> isOpen(50, true);

void solve()
{
    for (int i = 0; i < N; i++)
    {
        int cnt0 = 0;
        for (int j = 0; j < M; j++)
        {
            if (lamps[i][j] == '0') cnt0++;
        }

        if (cnt0 <= K && cnt0 % 2 == K % 2)
        {
            int rowCnt = 0;
            for (int j = 0; j < N; j++)
            {
                if (lamps[i] == lamps[j]) rowCnt++;
            }

            if (rowCnt > ans) ans = rowCnt;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> lamps[i];
    }
    cin >> K;

    solve();

    cout << ans;
}