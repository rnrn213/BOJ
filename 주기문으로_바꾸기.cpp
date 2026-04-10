#include <bits/stdc++.h>

using namespace std;

int M;
string S, ATGC = "ATGC";

int main()
{
    cin >> M >> S;

    int ans = 10000;
    for (int i = 1; i <= M; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            int cnt[4] = {0, 0, 0, 0};
            for (int k = j; k < S.size(); k += i)
            {
                for (int idx = 0; idx < 4; idx++)
                {
                    if (S[k] == ATGC[idx])
                    {
                        cnt[idx]++;
                        break;
                    }
                }
            }
            int temp = 0, maxCnt = 0;
            for (int idx = 0; idx < 4; idx++)
            {
                temp += cnt[idx];
                if (maxCnt < cnt[idx]) maxCnt = cnt[idx];
            }
            sum += temp - maxCnt;
        }

        if (ans > sum) ans = sum;
    }

    cout << ans;
}