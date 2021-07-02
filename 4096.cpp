#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string N) {
    int left = 0, right = N.size() - 1;
    while (left <= right) {
        if (N[left] != N[right]) return false;
        left++;
        right--;
    }
    return true;
}

void increaseN(string& N) {
    N[N.size() - 1]++;
    for (int i = N.size() - 1; i > 0; i--) {
        if (N[i] - '0' == 10) {
            N[i] = '0';
            N[i - 1]++;
        }
    }
}

int main() {
    string N;
    while (true) {
        cin >> N;
        if (N == "0") break;
        int cnt = 0;
        while (!isPalindrome(N)) {
            increaseN(N);
            cnt++;
        }
        cout << cnt << "\n";
    }
}