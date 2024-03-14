#include <bits/stdc++.h>

using namespace std;

const int INF = 5001;

int N, A[5000];
vector<int> v(400000, INF);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int idx = A[i] + A[j] + 200000;
            v[idx] = min(v[idx], j);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int idx = A[i] - A[j] + 200000;
            if (v[idx] < i) 
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}