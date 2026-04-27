#include <bits/stdc++.h>

using namespace std;

int T, N;
string s[2];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> s[0] >> s[1];

        int sum = 0;
        for (int i = 0; i < s[0].size(); i++)
        {
            sum += s[0][i] - '0';
        }

        if (sum % 3 != 0) cout << sum / 3 + 1 << "\n";
        else cout << sum / 3 << "\n";
    }
}