#include <bits/stdc++.h>

using namespace std;

string S, P;

int main()
{
    cin >> S >> P;

    int i = 0, ans = 0;
    while (i < P.size())
    {
        int len = 0;
        for (int j = 0; j < S.size(); j++)
        {
            if (P[i] == S[j])
            {
                int ii = i, jj = j;
                while (ii < P.size() && jj < S.size() && P[ii] == S[jj])
                {
                    ii++; jj++;
                }
                if (len < ii - i) len = ii - i;
            }
        }

        i += len;
        ans++;
    }

    cout << ans;
}