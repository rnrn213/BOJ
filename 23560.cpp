#include <bits/stdc++.h>

using namespace std;

int N, cache[3 * 15][3 * 15][3], med[3 * 15];

int solve(int start, int end, int time) {
    if (start == end)
        return 1;
    
    int &ret = cache[start][end][time % 3];
    if (ret != -1)
        return ret;
    ret = 0;

    if (time % 3 == 0) {
        if (med[start] == 1 || med[start] == 3) 
            ret += solve(start + 1, end, time + 1);
        if (med[end] == 1 || med[end] == 3)
            ret += solve(start, end - 1, time + 1);
    }
    else if (time % 3 == 1) {
        if (med[start] == 2)
            ret += solve(start + 1, end, time + 1);
        if (med[end] == 2)
            ret += solve(start, end - 1, time + 1);
    }
    else {
        if (med[start] == 1 || med[start] == 3)
            ret += solve(start + 1, end, time + 1);
        if (med[end] == 1 || med[end] == 3)
            ret += solve(start, end - 1, time + 1);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 0; i < 3 * N; i += 3) {
        for (int j = 0; j < 3; j++) {
            med[i + j] = j + 1;
        }
    }

    cout << solve(0, 3 * N - 1, 0);

}