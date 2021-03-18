#include <bits/stdc++.h>

using namespace std;

int invest(int H, int Y) {
    if (Y == 0) return H;
    if (Y < 0) return -1000000000;

    return max({invest(H * 1.35, Y - 5), invest(H * 1.20, Y -3), invest(H * 1.05, Y - 1)});
}

int main() {
    int H, Y;
    cin >> H >> Y;
    cout << invest(H, Y);
}