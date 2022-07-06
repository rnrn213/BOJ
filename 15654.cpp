#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;

void getProgression(vector<int>& v) {
    if (v.size() == M) {
        for (auto i: v) {
            cout << nums[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = 0; i < N; i++) {
        if (find(v.begin(), v.end(), i) == v.end()) {
            v.push_back(i);
            getProgression(v);
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
        getProgression(v);
    }
}