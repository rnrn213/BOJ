#include <bits/stdc++.h>

using namespace std;

int F, R, N;

int getMinDist(const vector< vector<bool> >& officeLED, int floor) {
    int dist = 0, left = 1, right = officeLED[floor].size() - 1, 
            prevLeft = 0, prevRight = officeLED[floor].size();
    
    while (left <= right) {
        while (!officeLED[floor][left] || !officeLED[floor][right]) {
            if (!officeLED[floor][left])
                left++;
            if (!officeLED[floor][right])
                right--;
            if (left > right)
                return dist * 2;
        }

        if (left - prevLeft <= prevRight - right) {
            dist += left - prevLeft;
            prevLeft = left;
            left++;
        }
        else {
            dist += prevRight - right;
            prevRight = right;
            right--;
        }
    }

    return dist * 2;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> F >> R >> N;
        vector< vector<bool> > officeLED(F + 1, vector<bool>(R + 1, false));
        for (int j = 0; j < N; j++) {
            int a, b;
            cin >> a >> b;
            officeLED[a][b] = true;
        }

        int ans = F * 2 + R + 1;
        for (int j = 1; j <= F; j++) {
            ans += getMinDist(officeLED, j);
            //cout << j << " : " << ans << "\n"; 
        }

        
        cout << ans << "\n";
    }
}