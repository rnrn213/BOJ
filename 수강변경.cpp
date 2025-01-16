#include <bits/stdc++.h>

using namespace std;

int N, A[1000001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        A[num]++;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        if (A[num] == 0) cnt++;
        else A[num]--;
    }

    cout << cnt;
}