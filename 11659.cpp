#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<int> nums(N), partialSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        partialSum[i + 1] += partialSum[i] + nums[i];
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << partialSum[end] - partialSum[start - 1] << "\n";
    }
}