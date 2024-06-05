#include <bits/stdc++.h>

using namespace std;

int N, arr[100000], minSum = 2100000000, ans[2];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int lo = 0, hi = N - 1;
    while (lo < hi)
    {
        int sum = abs(arr[lo] + arr[hi]);
        if (sum < minSum)
        {
            minSum = sum;
            ans[0] = arr[lo]; ans[1] = arr[hi];
        }

        int nextlo = -1, nexthi = -1, nextSum = abs(arr[lo + 1] + arr[hi]);
        if (nextSum < sum)
        {
            sum = nextSum;
            nextlo = lo + 1;
            nexthi = hi;
        }
        nextSum = abs(arr[lo] + arr[hi - 1]);
        if (nextSum < sum)
        {
            sum = nextSum;
            nextlo = lo;
            nexthi = hi - 1;
        }

        if (nextlo == -1)
        {
            nextlo = lo + 1;
            nexthi = hi - 1;
        }

        lo = nextlo;
        hi = nexthi;
    }

    cout << ans[0] << " " << ans[1];
}