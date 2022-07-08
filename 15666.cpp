#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;
vector< vector<int> > ans;

void dfs(int depth, vector<int>& v) {
    if (depth == M) {
        ans.push_back(v);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (nums[i] >= *(v.end() - 1)) {
            v.push_back(nums[i]);
            dfs(depth + 1, v);
            v.pop_back();
        }
    }

    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++) {
        vector<int> v = {nums[i]};
        dfs(1, v);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto progression: ans) {
        for (auto num: progression) {
            cout << num << " ";
        }
        cout << "\n";
    }
}