// 정답 참고함. (출처 : https://hvvan.tistory.com/516)
#include <bits/stdc++.h>

using namespace std;

int T, n;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> s;

        int cnt[80], last[80];
        memset(cnt, 0, sizeof(cnt));
        memset(last, -1, sizeof(last));
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - '0';
            cnt[c]++;
            last[c] = i;
        }

        vector< pair<int, int> > p;
        for (int i = 0; i < 80; i++)
        {
            if (last[i] != -1)
                p.push_back(make_pair(last[i], i));
        }
        sort(p.begin(), p.end());

        int now = 0, ans = 0;
        for (int i = 0; i < p.size(); i++)
        {
            ans += (p[i].first - (now + cnt[p[i].second] - 1)) * 5 * cnt[p[i].second];
            now += cnt[p[i].second];
        }

        cout << ans << "\n";
    }
}