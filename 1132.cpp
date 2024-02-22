#include <bits/stdc++.h>

using namespace std;

int N;
vector<bool> canZero(10, true), isValid(10, true);
vector< pair<long long, int> > arr;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(make_pair(0, i));
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int idx = 0;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (j == 0) canZero[s[j] - 'A'] = false;
            arr[s[j] - 'A'].first += pow(10, idx);
            idx++;
        }
    }

    sort(arr.begin(), arr.end());

    vector<bool> isValid(10, true);
    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0 && !canZero[arr[i].second]) continue;
            if (isValid[j])
            {
                ans += j * arr[i].first;
                isValid[j] = false;
                break;
            }
        }
    }

    cout << ans;
}