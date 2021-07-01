#include <bits/stdc++.h>

using namespace std;

string getEndTime(int N) {
    string et = "000000";
    et[0] = '0' + N / 10;
    et[1] = '0' + N % 10 + 1;
    return et;
}

bool isTContainK(string t, char K) {
    if (t.find(K) != string::npos) return true;
    else return false;
}

void increaseT(string& t) {
    t[5]++;
    if (t[5] - '0' == 10) {
        t[5] = '0';
        t[4]++;
        if (t[4] - '0' == 6) {
            t[4] = '0';
            t[3]++;
            if (t[3] - '0' == 10) {
                t[3] = '0';
                t[2]++;
                if (t[2] - '0' == 6) {
                    t[2] = '0';
                    t[1]++;
                    if (t[1] - '0' == 10) {
                        t[1] = '0';
                        t[0]++;
                    }
                }
            }
        }
    }
}

int main() {
    int N, K, cnt = 0;
    cin >> N >> K;

    string t = "000000", et = getEndTime(N);
    while (t != et) {
        if (isTContainK(t, '0' + K)) cnt++;

        increaseT(t);
    }
    cout << cnt;
}