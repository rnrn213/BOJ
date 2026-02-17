#include <bits/stdc++.h>

using namespace std;

string o, m;

int main()
{
    cin >> o >> m;
    int start, i = 0, j = 0, ans = 0;
    while (i < o.size() && j < m.size())
    {
        if (o[i] != m[j])
        {
            int ii = o.size() - 1, jj = m.size() - 1;
            while (ii >= i && jj >= j && o[ii] == m[jj])
            {
                ii--; jj--;
            }
            ans = jj - j + 1;
            break;
        }
        i++;
        j++;
    }
    if (i == o.size() && j < m.size()) ans = m.size() - j;
    cout << ans;
}