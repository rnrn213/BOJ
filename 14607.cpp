#include <bits/stdc++.h>

using namespace std;

long long N, ans;

int main()
{
    cin >> N;

    ans = (N * (N - 1)) / 2;
    cout << ans;
}