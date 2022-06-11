#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums(50);
    vector<char> operators(50);

    int turn = 0, tempSum = 0, ans = 0;
    bool isMinusBefore = false;
    while (true) {
        if (turn % 2 == 0) {
            cin >> nums[turn / 2];
            
            if (isMinusBefore)
                tempSum += nums[turn / 2];
            else
                ans += nums[turn / 2];
        }
        else {
            if (!(cin >> operators[turn / 2])) {
                ans -= tempSum;
                break;
            }
            
            if (operators[turn / 2] == '-') {
                if (isMinusBefore) {
                    ans -= tempSum;
                    tempSum = 0;
                }

                isMinusBefore = true;
            }
        }
        
        turn++;
    }
    
    cout << ans;
}