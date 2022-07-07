#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;
vector< vector<int> > ans;

void dfs(int depth, vector<int>& v) {
    if (depth == M) {
        vector<int> temp;
        for (auto i: v) {
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
        return;
    }

    
    for (int i = 0; i < N; i++) {
        if (find(v.begin(), v.end(), i) == v.end()) {
            v.push_back(i);
            dfs(depth + 1, v);
            v.pop_back();
        }
    }
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
        vector<int> v = {i};
        dfs(1, v);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto v: ans) {
        for (auto num: v) {
            cout << num << " ";
        }
        cout << "\n";
    }
}