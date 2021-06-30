#include <bits/stdc++.h>

using namespace std;

vector<int> getAnswer(const vector<int>& partitions) {
    vector<int> ans = partitions;
    for (int i = 0; i < partitions.size() - 1; i++) {
        for (int j = i + 1; j < partitions.size(); j++) {
            ans.push_back(partitions[j] - partitions[i]);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main() {
    int W, P;
    cin >> W >> P;
    vector<int> partitions(P + 1, 0);
    for (int i = 0; i < P; i++) {
        cin >> partitions[i];
    }
    partitions[P] = W;

    vector<int> ans = getAnswer(partitions);
    for (auto num: ans) {
        cout << num << " ";
    }
}