#include <bits/stdc++.h>

using namespace std;

int N, A[51];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    if (N < 3)
    {
        cout << N;
        return 0;
    }

    sort(A, A + N);

    int ans = 0;
    for (int l = 0; l < N - 1; l++)
    {
        for (int r = N - 1; r > l; r--)
        {
            if (A[l] + A[l + 1] > A[r] && ans < r - l + 1) ans = r - l + 1;
        }
    }
    
    cout << ans;
}