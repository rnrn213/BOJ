#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > points;

int getDistance(const pair<int, int>& A, const pair<int, int>& B) {
    return pow(A.first - B.first, 2) + pow(A.second - B.second, 2);
}

int solve(int left, int right) {
    if (left == right)
        return 800000001;

    int mid = (left + right) / 2;

    int ret = min(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    int dist = getDistance(points[lo], points[hi]);
    ret = min(ret, dist);
    while (left < lo || hi < right) {
        if (hi < right) {
            if (lo == left) {
                ret = min(ret, getDistance(points[lo], points[hi+1]));
                hi++;
            }
            else {
                int loMin = getDistance(points[lo-1], points[hi]),
                    hiMin = getDistance(points[lo], points[hi+1]);
                if (loMin < hiMin) {
                    ret = min(ret, loMin);
                    lo--;
                }
                else {
                    ret = min(ret, hiMin);
                    hi++;
                }
            }
        }
        else {
            ret = min(ret,getDistance(points[lo-1], points[hi]));
            lo--;
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    sort(points.begin(), points.end());

    cout << solve(0, n - 1);
}