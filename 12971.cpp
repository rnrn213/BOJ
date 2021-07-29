#include <bits/stdc++.h>

using namespace std;

int solve(const vector< pair<int, int> >& PX) {
    int num = PX[0].second;
    while (num < 1000000000) {
        if (num % PX[1].first == PX[1].second && num % 
                PX[2].first == PX[2]. second) {
            return num;
        }
        num += PX[0].first;
    }
    return -1;
}

int main() {
    vector< pair<int, int> > PX(3);
    cin >> PX[0].first >> PX[1].first >> PX[2].first >>
                PX[0].second >> PX[1].second >> PX[2].second;
    sort(PX.begin(), PX.end(), greater< pair<int, int> >());
    
    cout << solve(PX);
}