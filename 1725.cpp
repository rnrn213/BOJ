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

    stack<int> s;
    long long minIndex = 0;
    long long area = 0;
    s.push(0);
    for (int i = 0; i < N; i++) {
        if (v[i] >= s.top()) {
            s.push(i);
        }
        else {
            int temp = s.top();
            while (!s.empty()) {
                if (area < v[s.top()] * (temp - s.top() + 1)) {
                    area = v[s.top()] * (temp - s.top() + 1);
                }
                s.pop();
            }

            if (v[i] < v[minIndex])
                minIndex = i;
            else {
                if (area < v[minIndex] * (i - minIndex + 1)) {
                    area = v[minIndex] * (i - minIndex + 1);
                }
            }
            s.push(i);
        }
    }
    cout << area;
}