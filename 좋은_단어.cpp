#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        stack<char> s;
        string w;
        cin >> w;
        for (int j = 0; j < w.size(); j++)
        {
            if (!s.empty())
            {
                if (s.top() == w[j])
                    s.pop();
                else
                    s.push(w[j]);
            }
            else
            {
                s.push(w[j]);
            }
        }
        if (s.empty())
            cnt++;
    }

    cout << cnt;
}