#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> points;

int getStartIndex(int point) {
    int left = 0, right = N - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (points[mid] == point)
            return mid;
        else if (points[mid] < point)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

int getEndIndex(int point) {
    int left = 0, right = N - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (points[mid] == point)
            return mid;
        else if (points[mid] < point)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        points.push_back(num);
    }
    sort(points.begin(), points.end());

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        cout << getEndIndex(end) - getStartIndex(start) + 1 << "\n";
    }
}