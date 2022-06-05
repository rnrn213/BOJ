#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int sum = 0, cnt = 1, maxCnt = 0;
    vector<int> modes;
    for (int i = 0; i < N; i++) {
        sum += nums[i];

        if (i > 0 && nums[i - 1] != nums[i]) {
            if (cnt > maxCnt) {
                maxCnt = cnt;

                modes.clear();
                modes.push_back(nums[i - 1]);
            }
            else if (cnt == maxCnt) {
                modes.push_back(nums[i - 1]);
            }

            cnt = 1;
        }
        else if (i > 0 && nums[i - 1] == nums[i]) {
            cnt++;
        }
    }

    if (cnt > maxCnt) {
        modes.clear();
        modes.push_back(nums[N - 1]);
    }
    else if (cnt == maxCnt) {
        modes.push_back(nums[N - 1]);
    }


    sort(modes.begin(), modes.end());

    int arithmeticMean = round(static_cast<double>(sum) / N),
        median = nums[(N - 1) / 2],
        mode = (modes.size() == 1) ? modes[0] : modes[1],
        range = nums[N - 1] - nums[0];

    cout << arithmeticMean << "\n" << median << "\n" << mode << "\n" << range;
}