#include <bits/stdc++.h>

using namespace std;

int N, A[1001], cache[1001], arr[1001], ans;

int solve(int idx)
{
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;

    for (int i = idx + 1; i < N; i++)
    {
        if (A[idx] < A[i])
        {
            int len = 1 + solve(i);
            if (ret < len)
            {
                arr[idx] = i;
                ret = len;
            }
        }
    }

    if (ans < ret)
        ans = ret;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    memset(arr, -1, sizeof(arr));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        solve(i);
    }

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        temp.push_back(A[i]);
        int j = i;
        while (arr[j] >= 0)
        {
            temp.push_back(A[arr[j]]);
            j = arr[j];
        }
        if (temp.size() == ans)
            v = temp;
    }

    cout << ans << "\n";
    for (int num : v)
    {
        cout << num << " ";
    }
}