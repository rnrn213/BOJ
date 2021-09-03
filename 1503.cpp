#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums(1500);
    for (int i = 1; i <= 1500; i++) {
        nums[i - 1] = i;
    }
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        nums.erase(find(nums.begin(), nums.end(), num));
    }

    int minValue = 1000000000;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            for (int k = 0; k < nums.size(); k++) {
                int xyz = nums[i] * nums[j] * nums[k];

                if (abs(N - xyz) < minValue)
                    minValue = abs(N - xyz);

                if (xyz >= N)
                    break;
            }
        }
    }

    cout << minValue;
}