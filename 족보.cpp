#include <bits/stdc++.h>

using namespace std;

int n, d, arr[100001];

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        arr[c]++;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        while (arr[i] > d)
        {
            arr[i] -= d - 1;
            ans++;
        }
    } 
    cout << ans;
}