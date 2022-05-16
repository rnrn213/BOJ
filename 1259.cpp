#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string num;
        cin >> num;
        if (num == "0")
            break;

        int left = 0, right = num.size() - 1;
        bool isPalindrome = true;
        while (left <= right) {
            if (num[left] != num[right]) {
                isPalindrome = false;
                break;
            }

            left++;
            right--;
        }

        if (isPalindrome)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}