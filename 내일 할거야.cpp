#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> p[1000000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, t;
        cin >> d >> t;
        p[i].first = -t;
        p[i].second = d;
    }

    sort(p, p + n);

    int x = 1000000000;
    for (int i = 0; i < n; i++)
    {
        x = min(x, -p[i].first) - p[i].second;
    }

    cout << x;
}
