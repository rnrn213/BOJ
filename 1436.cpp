#include <bits/stdc++.h>

using namespace std;

bool is666(int num) {
    bool before6 = false;
    int cnt6 = 0;
    while (num) {
        if (num % 10 == 6) {
            if (before6) {
                cnt6++;
                if (cnt6 == 3) return true;
            }
            else {
                cnt6 = 1;
                before6 = true;
            }
        }
        else before6 = false;

        num /= 10;
    }
    return false;
}

vector<int> getAnswer() {
    vector<int> ret(1, -1);
    int num = 1;
    while (ret.size() <= 10001) {
        if (is666(num)) ret.push_back(num);
        num++;
    }
    return ret;
}

int main() {
    vector<int> answers = getAnswer();

    int N;
    cin >> N;
    cout << answers[N];
}