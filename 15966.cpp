#include <bits/stdc++.h>

using namespace std;

int N, cache[100000];
vector< pair<int, int> > arr;
vector< pair<int, pair<int, int> > > v;

void initCache() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(make_pair(num, i));
    }
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void makeV() {
    int i = 1, val = arr[0].first, start = arr[0].second, end = arr[0].second;
    while (i < arr.size()) {
        if (val == arr[i].first) {
            end = arr[i].second;
        }
        else {
            v.push_back(make_pair(val, make_pair(start, end)));

            start = end = arr[i].second;
            val = arr[i].first;
        }
        i++;
    }
    v.push_back(make_pair(val, make_pair(start, end)));
}

int solve(int idx) {
    if (idx == v.size()) return 0;
    if (idx == v.size() - 1) return 1;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;
    if (v[idx].first + 1 == v[idx + 1].first && 
            v[idx].second.first < v[idx + 1].second.second)
        ret = max(ret, 1 + solve(idx + 1));
    return ret;
}

int getAnswer() {
    int ans = 0;
    for (int i = v.size() - 1; i >=0; i--) {
        ans = max(ans, solve(i));
    }
    return ans;
}

int main() {
    initCache();
    input();
    sort(arr.begin(), arr.end(), compare);
    makeV();
    cout << getAnswer();
}