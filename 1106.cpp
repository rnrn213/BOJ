#include <bits/stdc++.h>

using namespace std;

int C, N, cache[1001];
vector< pair<int, int> > cities;

void input() {
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        int cost, customer;
        cin >> cost >> customer;
        cities.push_back(make_pair(cost, customer));
    }
}

int solve(int customer) {
    if (customer <= 0) return 0;

    int ret = 1000000000;
    for (int i = 0; i < N; i++) {
        ret = min(ret, cities[i].first + solve(customer - cities[i].second));
    }
    return ret;
}

int solveA(int cost, int customer) {
    if (customer <= 0) return cost;

    int& ret = cache[customer];
    if (ret != -1) return ret = min(ret, cost);
    ret = cost;
    for (int i = 0; i < N; i++) {
        solveA(cost + cities[i].first, customer - cities[i].second);
    }
    return ret;
}

int main() {
    input();
    cout << solve(C);
    cout << '\n' << solveA(0, C);
}