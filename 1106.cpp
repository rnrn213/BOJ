#include <bits/stdc++.h>

using namespace std;

int C, N, cache[1001];
vector< pair<int, int> > cities;

void initCache() {
    memset(cache, -1, 1001 * sizeof(int));
}

void input() {
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        int cost, customer;
        cin >> cost >> customer;
        cities.push_back(make_pair(cost, customer));
    }
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if ((static_cast<double>(a.first) / a.second) - (static_cast<double>(b.first) / b.second) > numeric_limits<double>::epsilon()) {
        return true;
    }
    else return false;
}

void sortCities() {
    sort(cities.begin(), cities.end(), compare);
}

int solve(int customer) {
    if (customer <= 0) return 0;

    int& ret = cache[customer];
    if (ret != -1) return ret;
    ret = 1000000000;
    for (int i = 0; i < N; i++) {
        ret = min(ret, cities[i].first + solve(customer - cities[i].second));
    }
    return ret;
}

int main() {
    initCache();
    input();
    sortCities();
    cout << solve(C);
}