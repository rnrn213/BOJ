#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T) {
        int k;
        cin >> k;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        map<int, int> m;
        for (int i = 0; i < k; i++) {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') {
                maxHeap.push(n);
                minHeap.push(n);

                if (m.count(n) == 0)
                    m[n] = 1;
                else
                    m[n]++;
            }
            else if (op == 'D') {
                if (n == 1 && maxHeap.size() > 0) {
                    while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
                        maxHeap.pop();
                    }

                    if (!maxHeap.empty()) {
                        m[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                }
                else if (n == -1 && minHeap.size() > 0) {
                    while (!minHeap.empty() && m[minHeap.top()] == 0) {
                        minHeap.pop();
                    }

                    if (!minHeap.empty()) {
                        m[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }

        while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
            maxHeap.pop();
        }
        while (!minHeap.empty() && m[minHeap.top()] == 0) {
            minHeap.pop();
        }

        if (maxHeap.empty() || minHeap.empty())
            cout << "EMPTY\n";
        else
            cout << maxHeap.top() << " " << minHeap.top() << "\n";

        T--;
    }
}