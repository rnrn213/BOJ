#include <bits/stdc++.h>

using namespace std;



int main()
{
    string str;
    cin >> str;

    long long ans = 0;
    stack<int> s[200];
    int sIdx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            sIdx++;
        }
        else if (str[i] == ')')
        {
            int sum = 0;
            while (!s[sIdx].empty())
            {
                sum += s[sIdx].top();
                s[sIdx].pop();
            }

            sIdx = (sIdx - 1 < 0) ? 0 : sIdx - 1;
            s[sIdx].push(sum);
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            int num = s[sIdx].top() * (str[i] - '0');
            s[sIdx].pop();
            s[sIdx].push(num);
        }
        else
        {
            if (str[i] == 'H')
                s[sIdx].push(1);
            if (str[i] == 'C')
                s[sIdx].push(12);
            if (str[i] == 'O')
                s[sIdx].push(16);
        }
    }

    while (!s[0].empty())
    {
        ans += s[0].top();
        s[0].pop();
    }

    cout << ans;
}