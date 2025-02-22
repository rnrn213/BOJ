#include <bits/stdc++.h>

using namespace std;

int N, A[100001], Q, L[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        A[num] = 1;
    }

    for (int i = 1; i <= 100000; i++)
    {
        for (int j = 2; j <= 100000; j++)
        {
            if (i * j > 100000) break;
            A[i * j] += A[i];
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> L[i];
        cout << A[L[i]] << " ";
    }
}