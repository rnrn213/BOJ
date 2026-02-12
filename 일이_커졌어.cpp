#include <bits/stdc++.h>

using namespace std;

int N, p[101];

int main()
{
    cin >> N;

    int i, num = N;
    if (N % 2 == 0) i = N - 1;
    else i = N;
    
    for (;i > 0; i -= 2)
    {
        p[i] = num--;
    }
    for (i = 2; i <= N; i += 2)
    {
        p[i] = num--;
    }

    for (i = 1; i <= N; i++)
    {
        cout << p[i] << " ";
    }
}