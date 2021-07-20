#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max = -1, ans;
    for (int i = 0; i < N; i++) {
        vector<int> nums(5);
        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];

        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 4; k++) {
                for (int n = k + 1; n < 5; n++) {
                    if ((nums[j] + nums[k] + nums[n]) % 10 >= max) {
                        max = (nums[j] + nums[k] + nums[n]) % 10;
                        ans = i + 1;
                    }
                }
            }
        }
    }
    cout << ans;
}