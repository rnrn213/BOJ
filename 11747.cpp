#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

vector<int> makeNonNegativeIntegerVector() {
    vector<int> ret;
    
    for (int d = 0; d < 3; d++) {
        for (int i = 0; i < N - d; i++) {
            int n = nums[i] * pow(10, d), tempI = i + 1;
            for (int tempD = d - 1; tempD >= 0; tempD--) {
                n += nums[tempI++] * pow(10, tempD);
            }
            ret.push_back(n);
        }
    }
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
}

int getAnswer() {
    vector<int> ret;
    for (int d = 0; d < 10; d++) {
        for (int i = 0; i < N - d; i++) {
            int n = nums[i] * pow(10, d), tempI = i + 1;
            for (int tempD = d - 1; tempD >= 0; tempD--) {
                n += nums[tempI++] * pow(10, tempD);
            }
            ret.push_back(n);
        }

        int i = (d == 0) ? 0 : pow(10, d);
        for (; i < pow(10, d + 1); i++) {
            if (find(ret.begin(), ret.end(), i) == ret.end())
                return i;
        }
        ret.clear();
    }

    return -1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << getAnswer();
}