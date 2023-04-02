#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> parent(100);
vector< pair<double, double> > stars;

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    parent[a] = b;
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        
        double x, y;
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }

    vector< pair<double, pair<int, int> > > edges;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = sqrt(pow(stars[i].first - stars[j].first, 2) + pow(stars[i].second - stars[j].second, 2));
            edges.push_back(make_pair(dist, make_pair(i, j)));
        }
    }
    sort(edges.begin(), edges.end());

    double totalCost = 0.0;
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int v1 = edges[i].second.first, v2 = edges[i].second.second;

        if (merge(v1, v2))
            totalCost += cost;
    }

    cout << fixed;
    cout.precision(2);
    cout << totalCost;
}