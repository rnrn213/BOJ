#include <bits/stdc++.h>

using namespace std;

int N, num[1001], K, cache[50002];

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        cache[num[i]] = 1;
    }
    cin >> K;

    int x = 1;
    while (x <= 50001) {
        if (cache[x] == -1) {
            cache[x] = 51;
            for (int i = N; i >= 1; i--) {
                if (x - num[i] > 0 && cache[x - num[i]] < K) {
                    cache[x] = min(cache[x], 1 + cache[x - num[i]]);
                }
            }
            if (cache[x] == 51)
                break;
        }
        x++;
    }

    if (x % 2 == 0) 
        cout << "holsoon ";
    else
        cout << "jjaksoon ";
    
    cout << "win at " << x;
}