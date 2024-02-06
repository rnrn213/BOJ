#include <bits/stdc++.h>

using namespace std;

int N, A[50], B[50], S = 0;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
}

void solve()
{
    sort(A, A + N);
    sort(B, B + N, greater<>());

    for (int i = 0; i < N; i++)
    {
        S += A[i] * B[i];
    }
}

void output()
{
    cout << S;
}

int main()
{
    input();
    solve();
    output();
}