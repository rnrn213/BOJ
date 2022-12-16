#include <bits/stdc++.h>

using namespace std;

int N, L, pos[1000], tapeEnd = -1;

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    sort(pos, pos + N);

    int tapeCnt = 0;
    for (int i = 0; i < N; i++) {
        if (pos[i] > tapeEnd) {
            tapeCnt++;
            tapeEnd = pos[i] + L - 1;
        }
    }

    cout << tapeCnt;
}