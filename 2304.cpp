#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > pillars;

int main() {
    cin >> N;
    pair<int, int> maxHeightPillar = make_pair(-1, 0);
    for (int i = 0; i < N; i++) {
        pair<int, int> pillar;
        cin >> pillar.first >> pillar.second;

        if (pillar.second > maxHeightPillar.second)
            maxHeightPillar = pillar;

        pillars.push_back(pillar);
    }
    sort(pillars.begin(), pillars.end());

    int minArea = 0;
    pair<int, int> leftPillar = pillars[0];
    for (int i = 0; i < N; i++) {
        if (pillars[i].first == maxHeightPillar.first) {
            minArea += pillars[i].second + (pillars[i].first - leftPillar.first) * leftPillar.second;
            leftPillar = pillars[i];
        }
        if (pillars[i].first < maxHeightPillar.first) {
            if (pillars[i].second > leftPillar.second) {
                minArea += (pillars[i].first - leftPillar.first) * leftPillar.second;
                leftPillar = pillars[i];
            }
        }
        if (pillars[i].first > maxHeightPillar.first) {
            int nextMaxHeightIdx = -1, nextMaxHeight = 0;
            for (int j = i; j < N; j++) {
                if (pillars[j].second > nextMaxHeight) {
                    nextMaxHeightIdx = j;
                    nextMaxHeight = pillars[j].second;
                }
            }
            i = nextMaxHeightIdx;
            minArea += (pillars[i].first - leftPillar.first) * pillars[i].second;
            leftPillar = pillars[i];
        }
    }

    cout << minArea;
}