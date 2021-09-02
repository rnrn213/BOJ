#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > polygon;

double getTriangleArea(const pair<int, int>& A, const pair<int, int>& B, const pair<int, int>& C) {
    return fabs((A.first*B.second + B.first*C.second + C.first*A.second) - (B.first*A.second + C.first*B.second + A.first*C.second)) / 2;
}

double solve() {
    double maxTriangleArea = 0.0;

    for (int i = 0; i < polygon.size() - 2; i++) {
        for (int j = i + 1; j < polygon.size() - 1; j++) {
            for (int k = j + 1; k < polygon.size(); k++) {
                double area = getTriangleArea(polygon[i], polygon[j], polygon[k]);
                if (area - maxTriangleArea > numeric_limits<double>::epsilon()) {
                    maxTriangleArea = area;
                }
            }
        }
    }

    return maxTriangleArea;
}

int main() {
    cin >> N;
    polygon = vector< pair<int, int> >(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        polygon[i] = make_pair(x, y);
    }

    cout << fixed;
    cout.precision(1);
    cout << solve();

}