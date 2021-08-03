#include <bits/stdc++.h>

using namespace std;

double getDistance(const pair<double, double>& a, const pair<double, double>& b) {
    return sqrt(pow(a.first - b.first,2 ) + pow(a.second - b.second, 2));
}

int main() {
    pair<double, double> yumi;
    cin >> yumi.first >> yumi.second;
    vector< pair<double, double> > point(3);
    for (int i = 0; i < 3; i++) {
        cin >> point[i].first >> point[i].second;
    }

    double minDist = 1000000.0;
    for (int i = 0; i < 3; i++) {
        double dist = getDistance(yumi, point[i]);
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                dist += getDistance(point[i], point[j]);
                for (int k = 0; k < 3; k++) {
                    if (i != k && j != k) {
                        dist += getDistance(point[j], point[k]);
                        if (minDist - dist > numeric_limits<double>::epsilon()) {
                            minDist = dist;
                        }
                        dist -= getDistance(point[j], point[k]);
                    }
                }
                dist -= getDistance(point[i], point[j]);
            }
        }
    }
    cout << static_cast<int>(floor(minDist));
}