#include <bits/stdc++.h>

using namespace std;

int getGCD(int x, int y) {
    if (x > y) return getGCD(y, x);

    vector<int> aliquot;
    for (int i = x; i >= 1; i--) {
        if (x % i == 0) aliquot.push_back(i);
    }
    for (auto n: aliquot) {
        if (y % n == 0) return n;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string s;
        getline(cin, s);
        istringstream ss(s);
        string stringBuffer;
        vector<int> nums;
        while (getline(ss, stringBuffer, ' ')) {
            nums.push_back(stoi(stringBuffer));
        }

        int gcd = 1;
        for (int j = 0; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                gcd = max(gcd, getGCD(nums[j], nums[k]));
            }
        }
        cout << gcd << "\n";
    }
}