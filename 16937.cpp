#include <bits/stdc++.h>

using namespace std;

bool isValid(int H, int W, pair<int, int> s1, pair<int, int> s2) {
    if (s1.first <= H && s1.second <= W) {
        if ((s2.first <= H && s2.second <= W - s1.second) ||
                (s2.first <= H - s1.first && s2.second <= W))
            return true;
        if ((s2.second <= H && s2.first <= W - s1.second) ||
                (s2.second <= H - s1.first && s2.first <= W))
            return true;
    }
    if (s1.second <= H && s1.first <= W) {
        if ((s2.first <= H &&  s2.second <= W - s1.first) ||
                (s2.first <= H - s1.second && s2.second <= W))
            return true;
        if ((s2.second <= H && s2.first <= W - s1.first) ||
                (s2.second <= H - s1.second && s2.first <= W))
            return true;
    }

    return false;
}

int getArea(const pair<int, int> s1, const pair<int, int> s2) {
    return s1.first * s1.second + s2.first * s2.second;
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector< pair<int, int> > stickers(N);
    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        stickers[i] = make_pair(R, C);
    }

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isValid(H, W, stickers[i], stickers[j]))
                ans = max(ans, getArea(stickers[i], stickers[j]));
        }
    }
    
    cout << ans;
}