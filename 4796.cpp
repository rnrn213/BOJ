#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, P, V;

    int i = 1, ans = 0;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0) 
            break;
        
        ans = (V / P) * L;
        ans += ((V % P) >= L) ? L : V % P;

        cout << "Case " << i++ << ": " << ans << "\n";
    }
}