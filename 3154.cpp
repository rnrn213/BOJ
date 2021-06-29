#include <bits/stdc++.h>

using namespace std;

int coordinate[10][2] = {{1, 3}, {0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}, 
                         {2, 1}, {0, 2}, {1, 2}, {2, 2}};

int effort(int a, int b) {
    return abs(coordinate[a][0] - coordinate[b][0]) + 
            abs(coordinate[a][1] - coordinate[b][1]);
}

int getEffort(string t) {
    return effort(t[0] - '0', t[1] - '0') + effort(t[1] - '0', t[3] - '0')
            + effort(t[3] - '0', t[4] - '0');
}

bool isMaxHour(string t) {
    t[0] += 2;
    t[1] += 4;
    if (t[1] > '9') {
        t[1] -= 10;
        t[0]++;
    }
    if (t[0] > '9') return true;
    else return false;
}

bool isMaxMinute(string t) {
    t[3] += 6;
    if (t[3] > '9') return true;
    else return false;
}

int main() {
    string t;
    cin >> t;

    string ans;
    int minEffort = 1000000;
    while (true) {
        if (t[1] > '9') {
            t[1] -= 10;
            t[0]++;
        }

        int nowEffort = getEffort(t);
        if (nowEffort < minEffort) {
                ans = t;
                minEffort = nowEffort;
        }
        
        if (!isMaxMinute(t)) {
            t[3] += 6;
            nowEffort = getEffort(t);
            if (nowEffort < minEffort) {
                ans = t;
                minEffort = nowEffort;
            }
            if (isMaxHour(t)) {
                break;
            }
            else {
                t[0] += 2;
                t[1] += 4;
                t[3] -= 6;
            }
        }
        else {
            if (isMaxHour(t)) {
                break;
            }
            else {
                t[0] += 2;
                t[1] += 4;
            }
        }
    }
    cout << ans;
}