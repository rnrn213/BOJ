#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> crosswalk(n + 1), left(n + 1), right(n + 1);
    long long rightDist = 0;
    for (int i = 1; i <= n; i++) {
        cin >> crosswalk[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> left[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> right[i];
        rightDist += right[i];
    }

    int crosswalkIdx = -1;
    long long minDist = 10100000000, leftDist = 0;
    for (int i = 1; i <= n; i++) {
        long long d = leftDist + crosswalk[i] + rightDist;

        if (d < minDist) {
            minDist = d;
            crosswalkIdx = i;
        }

        leftDist += left[i];
        rightDist -= right[i];
    }

    cout << crosswalkIdx << " " << minDist;
}