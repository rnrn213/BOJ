#include <bits/stdc++.h>

using namespace std;

char solve(int N) {
    int start = 1, end = 10, i = 1;
    bool isValid = false;
    while (true) {
        int num;
        for (num = start; num < end; num++) {
            N -= i;
            if (N <= 0) {
                N += i;
                isValid = true;
                break;
            }
        }
        
        if (isValid) {
            string s = to_string(num);
            return s[N - 1];
        }

        start = end;
        i++;
        end = pow(10, i);
    }
    return '-';
}

int main() {
    int N;
    cin >> N;
    cout << solve(N);
}