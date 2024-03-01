#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v(26, 0);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = s.size() - 1; j >= 0; j--)
        {
            v[s[j] - 'A'] += (int)pow(10, s.size() - 1 - j);
        }
    }

    sort(v.begin(), v.end(), greater<>());

    int ans = 0, x = 9;
    for (int i = 0; i < 10; i++)
    {
        ans += x * v[i];
        x--;
    }

    cout << ans;
}
