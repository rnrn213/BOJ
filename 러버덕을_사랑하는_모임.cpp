#include <bits/stdc++.h>

using namespace std;

int N, P, E, xsum = 0, ysum = 0, xs = -1, ys = -1, x[21], y[21];
vector<bool> isUsed(21, false), ans;

void solve(int idx, int cnt)
{
    if (cnt == 0)
    {
        if (xsum <= E && E <= ysum) 
        {
            ans = isUsed;
            xs = xsum;
            ys = ysum;
        }
        return;
    }
    if (idx == N) return;

    for (int i = idx; i < N; i++)
    {
        if (!isUsed[i])
        {
            xsum += x[i];
            ysum += y[i];
            isUsed[i] = true;
            solve(i + 1, cnt - 1);
            xsum -= x[i];
            ysum -= y[i];
            isUsed[i] = false;
        }
    }
}

int main()
{
    cin >> N >> P >> E;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    solve(0, P);

    if (xs == -1) cout << -1;
    else
    {
        E -= xs;
        for (int i = 0; i < N; i++)
        {
            if (!ans[i]) cout << 0;
            else
            {
                int a = min(E, y[i] - x[i]);
                cout << x[i] + a;
                E -= a;
            }
            cout << " ";
        }
    }
}