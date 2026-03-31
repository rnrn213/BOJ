#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y;

int main()
{
    cin >> x >> y;

    ll num = sqrt(x + y);
    while (num * (num + 1) < (x + y) * 2)
    {
        num++;
    }

    if (num * (num + 1) != (x + y) * 2) cout << -1;
    else
    {
        int cnt = 0;
        while (x)
        {
            if (x >= num)
            {
                x -= num;
                cnt++;
            }
            num--;
        }
        cout << cnt;
    }
}