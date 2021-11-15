#include <bits/stdc++.h>

using namespace std;

int cache[25], N;
vector< pair< pair<int, int>, int > > meetings;

int solve(int idx) {
    if (idx >= N)
        return 0;

    int ret = cache[idx];
    if (ret != -1)
        return ret;
    
    return ret = max(meetings[idx].second + solve(idx + 2), solve(idx + 1));
}

int main() {
    memset(cache, -1, 25 * sizeof(int));

    cin >> N;
    meetings = vector< pair< pair<int, int>, int > >(N);
    for (int i = 0; i < N; i++) {
        int startTime, endTime, meetingPeople;
        cin >> startTime >> endTime >> meetingPeople;
        meetings[i] = make_pair(make_pair(startTime, endTime), meetingPeople);
    }

    cout << solve(0);
}