#include <bits/stdc++.h>

using namespace std;

int N, h[100001], sum = 0, odd = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        sum += h[i];
        if (h[i] % 2 == 1) odd++;
    }

    string ans;
    if (sum % 3 != 0)
    {
        ans = "NO";
    }
    else 
    {
        int x = sum / 3;
        if ((x >= odd) && ((x - odd) % 2 == 0)) ans = "YES";
        else ans = "NO";
    }

    cout << ans;
}
