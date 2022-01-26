#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int minBeforePenguin = 1000000001, minAfterPenguin = 1000000001;
    bool isAfterPenguin = false;
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            isAfterPenguin = true;
            continue;
        }
        
        if (!isAfterPenguin) {
            if (A[i] < minBeforePenguin) {
                minBeforePenguin = A[i];
            }
        }
        else {
            if (A[i] < minAfterPenguin) {
                minAfterPenguin = A[i];
            }
        }
    }

    cout << minBeforePenguin + minAfterPenguin;
}