#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> nums(5, 0);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }

    int i = 1, cnt = 0;
    while (true) {
        cnt = 0;
        for (auto num: nums) {
            if (i % num == 0) cnt++;
        }
        if (cnt >= 3) break;

        i++;
    }
    cout << i;
}