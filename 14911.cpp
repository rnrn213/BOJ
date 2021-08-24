#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    vector< pair<int, int> > ans;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - 1; j++) {
            if (i != j && nums[i] + nums[j] == *(nums.end() - 1) && nums[i] <= nums[j]) ans.push_back(make_pair(nums[i], nums[j]));
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto a: ans) {
        cout << a.first << " " << a.second << "\n";
    }
    cout << ans.size();
}