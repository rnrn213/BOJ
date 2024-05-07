#include <bits/stdc++.h>

using namespace std;

int N, H[1000002], ans = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (H[num] == 0)
        {
            ans++;
        }
        else
        {
            H[num]--;
        }

        H[num - 1]++;
    }

    cout << ans;
}