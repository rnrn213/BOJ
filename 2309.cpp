#include <bits/stdc++.h>

using namespace std;

vector<int> heights(9, 0), ans, tempAns;

void getMaxHeightSum(int count, int heightSum) {
    if (count == 7) {
        if (heightSum == 100) ans = tempAns;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (heights[i] == -1) continue;
        int temp = heights[i];
        tempAns.push_back(heights[i]);
        heights[i] = -1;
        getMaxHeightSum(count + 1, heightSum + temp);
        heights[i] = temp;
        tempAns.pop_back();
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
    }

    getMaxHeightSum(0, 0);

    sort(ans.begin(), ans.end());
    for (auto h: ans) {
        cout << h << "\n";
    }
}