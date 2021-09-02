#include <bits/stdc++.h>

using namespace std;

bool isFight(int kim, int lim) {
    if (abs(kim - lim) == 1 && 
            ((kim % 2 == 0 && kim > lim) || (lim % 2 == 0 && lim > kim)))
        return true;
    
    return false;
}

int solve(int N, int kim, int lim) {
    int round = 1;
    while (N > 1) {
        if (isFight(kim, lim))
            return round;

        N = N / 2 + N % 2;
        if (kim % 2 == 1) {
            if (kim == N)
                kim = N / 2 + 1;
            else
                kim = (kim + 1) / 2;
        }
        else 
            kim /= 2;
        if (lim % 2 == 1) {
            if (lim == N)
                lim = N / 2 + 1;
            else
                lim = (lim + 1) / 2;
        }
        else
            lim /= 2;
        round++;
    }

    return -1;
}

int main() {
    int N, kim, lim;
    cin >> N >> kim >> lim;

    cout << solve(N, kim, lim);
}