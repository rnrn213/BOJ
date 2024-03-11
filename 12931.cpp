#include <bits/stdc++.h>

using namespace std;

int N, A[50], B[50];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    sort(B, B + N, greater<>());

    int cnt1 = 0, maxCnt2 = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt2 = 0;
        while (B[i] > 0)
        {
            if (B[i] % 2 == 0)
            {
                B[i] /= 2;
                cnt2++;
            }
            else
            {
                B[i] -= 1;
                cnt1++;
            }
        }
        
        if (cnt2 > maxCnt2) maxCnt2 = cnt2;
    }

    cout << cnt1 + maxCnt2;
}