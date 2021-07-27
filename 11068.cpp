#include <bits/stdc++.h>

using namespace std;

vector<int> getBthSystem(int n, int b) {
    vector<int> ret;
    while (true) {
        ret.push_back(n % b);
        n /= b;
        if (n / b == 0) {
            ret.push_back(n);
            break;
        }
    }
    return ret;
}

bool isPalindrome(const vector<int>& num) {
    int left = 0, right = num.size() - 1;
    while (left < right) {
        if (num[left] != num[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, ans = 0;
        cin >> n;
        for (int j = 64; j >= 2; j--) {
            if (isPalindrome(getBthSystem(n, j))) {
                ans = 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}