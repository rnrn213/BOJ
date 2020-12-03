#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> v;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    long long area = 0;
    stack<int> s;
    for (int i = 0; i < N; i++) {
        while (!s.empty() && v[s.top()] >= v[i]) {
            int temp = s.top();
            s.pop();

            int w;
            if (s.empty()) {
                w = i;
            }
            else {
                w = i - s.top() - 1;
            }
            area = max(area, v[temp] * w);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        int w = N;
        if (!s.empty()) {
            w -= s.top() + 1;
        }
        area = max(area, v[temp] * w);
    }
    cout << area;
}