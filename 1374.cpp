#include <bits/stdc++.h>

using namespace std;

bool cmp(const tuple<int, int, int>& u, const tuple<int, int, int>& v) {
    if (get<1>(u) == get<1>(v))
        return get<2>(u) < get<2>(v);
    return get<1>(u) < get<1>(v);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector< tuple<int, int, int> > lecture(N);
    for (int i = 0; i < N; i++) {
        int lectureNum, lectureStartTime, lectureEndTime;
        cin >> lectureNum >> lectureStartTime >> lectureEndTime;
        get<0>(lecture[i]) = lectureNum;
        get<1>(lecture[i]) = lectureStartTime;
        get<2>(lecture[i]) = lectureEndTime;
    }

    sort(lecture.begin(), lecture.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(get<2>(lecture[0]));
    int lectureRoomCnt = 1;
    for (int i = 1; i < N; i++) {
        if (get<1>(lecture[i]) < pq.top()) {
            lectureRoomCnt++;
        }
        else {
            pq.pop();
        }

        pq.push(get<2>(lecture[i]));
    }

    cout << lectureRoomCnt;
}