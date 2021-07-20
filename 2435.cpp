#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int sum = 0;
    queue<int> q;
    for (int i = 0; i < K; i++) {
        int temperature;
        cin >> temperature;

        q.push(temperature);
        sum += temperature;
    }
    int ans = max(-100 * K - 1, sum);
    for (int i = K; i < N; i++) {
        int temperature;
        cin >> temperature;

        sum = sum - q.front() + temperature;
        q.pop();
        q.push(temperature);
        ans = max(ans, sum);
    }
    cout << ans;
}