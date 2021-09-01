#include <bits/stdc++.h>

using namespace std;

int minCost = 100;
vector< vector<int> > A(3, vector<int>(3)), arr(3, vector<int>(3));
vector< vector<int> > ans = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

void printArr(const vector< vector<int> >& arr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isMagicSquare(const vector< vector<int> >& arr) {
    vector<bool> isUsed(11, false);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isUsed[arr[i][j]]) return false;

            isUsed[arr[i][j]] = true;
        }
    }

    int diagonalSum1 = 0, diagonalSum2 = 0;
    for (int i = 0; i < 3; i++) {
        diagonalSum1 += arr[i][i];
        diagonalSum2 += arr[i][2 - i];

        int rowSum = 0, columnSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += arr[i][j];
            columnSum += arr[j][i];
        }
        if (rowSum != 15 || columnSum != 15) return false;
    }
    if (diagonalSum1 != 15 || diagonalSum2 != 15) return false;

    return true;
}

int getCost(const vector< vector<int> >& A, const vector< vector<int> >& arr) {
    int cost = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cost += abs(A[i][j] - arr[i][j]);
        }
    }

    return cost;
}

void solve(int idx, vector<int>& nums) {
    if (idx == 8) {
        arr[idx / 3][idx % 3] = nums[0];

        if (isMagicSquare(arr)) {
            int cost = getCost(A, arr);
            if (minCost > cost) {
                minCost = cost;
            }
        }
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        arr[idx / 3][idx % 3] = num;
        nums.erase(nums.begin() + i);
        solve(idx + 1, nums);
        nums.insert(nums.begin() + i, num);
    }

    return;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    solve(0, nums);

    cout << minCost;
}