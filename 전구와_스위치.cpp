#include "bits/stdc++.h"

using namespace std;

const int INF = 2100000000;

int N;
string A, B;

int main()
{
    cin >> N >> A >> B;
    A.append("0"); B.append("0");

    int ans = INF, cnt = 0;
    string temp = A;
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] != B[i - 1])
        {
            for (int j = i - 1; j <= i + 1; j++)
            {
                if (A[j] == '0') A[j] = '1';
                else A[j] = '0';
            }
            cnt++;
        }
    }
    if (A.substr(0, N) == B.substr(0, N)) ans = cnt;

    A = temp;
    for (int i = 0; i <= 1; i++)
    {
        if (A[i] == '0') A[i] = '1';
        else A[i] = '0';
    }
    cnt = 1;
    for (int i = 1; i < N; i++)
    {
            if (A[i - 1] != B[i - 1])
        {
            for (int j = i - 1; j <= i + 1; j++)
            {
                if (A[j] == '0') A[j] = '1';
                else A[j] = '0';
            }
            cnt++;
        }
    }
    if (A.substr(0, N) == B.substr(0, N)) ans = min(ans, cnt);

    if (ans == INF) ans = -1;

    cout << ans;
}