#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, ring;
    cin >> s;
    int N, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ring;
        ring += ring.substr(0, s.size() - 1);
        for (int j = 0; j <= ring.size() - s.size(); j++) {
            if (s == ring.substr(j, s.size())) {
                cnt++;
                break;
            }
        }
        
    }
    cout << cnt;
}