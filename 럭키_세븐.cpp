#include <bits/stdc++.h>

using namespace std;

int T, N, v[200000][2];
char op[200000][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> op[i][0] >> v[i][0] >> op[i][1] >> v[i][1];
        }

        vector<vector<int>> cache(N + 1, vector<int>(7, 0));
        cache[0][1] = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int m = 0; m < 2; m++)
                {
                    if (op[i][m] == '+')
                        cache[i + 1][(j + v[i][m]) % 7] |= cache[i][j];
                    else
                        cache[i + 1][(j * v[i][m]) % 7] |= cache[i][j];
                }
            }
        }

        if (cache[N][0]) cout << "LUCKY\n";
        else cout << "UNLUCKY\n";
    }
}