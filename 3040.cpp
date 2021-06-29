#include <bits/stdc++.h>

using namespace std;

vector<int> nums(9, 0), ans, tempAns;

void findDwarfs(int count, int sum) {
    if (count == 7) {
        if (sum == 100) ans = tempAns;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (nums[i] != -1) {
            int num = nums[i];
            nums[i] = -1;
            tempAns.push_back(num);
            findDwarfs(count + 1, sum + num);
            tempAns.pop_back();
            nums[i] = num;
        }
    }
}

void printDwarfs() {
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> nums[i];
    }
    findDwarfs(0, 0);
    printDwarfs();
}