#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ans;
    int max = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> temp = {N, i};
        while (true) {
            int num = temp[temp.size() - 2] - temp[temp.size() - 1];
            if (num < 0) break;

            temp.push_back(num);
        }
        if (temp.size() > max) {
            ans = temp;
            max = temp.size();
        }
    }
    cout << ans.size() << "\n";
    for (auto n: ans) {
        cout << n << " ";
    }
}