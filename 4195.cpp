#include <bits/stdc++.h>

using namespace std;

int T, F;
vector< pair<int, int> > parent;

pair<int, int> find(int a) {
    if (parent[a].first == a) return parent[a];
    return parent[a] = find(parent[a].first);
}

int merge(int a, int b) {
    a = find(a).first;
    b = find(b).first;

    if (a == b) return parent[a].second;

    parent[a].first = parent[b].first;
    return parent[b].second += parent[a].second;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        cin >> F;

        parent.clear();
        for (int i = 0; i < 2 * F; i++) {
            parent.push_back(make_pair(i, 1));
        }

        map<string, int> nameToIndex;
        int cnt = 0;
        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;
            
            if (nameToIndex.find(a) == nameToIndex.end())
                nameToIndex.insert(make_pair(a, cnt++));
            if (nameToIndex.find(b) == nameToIndex.end())
                nameToIndex.insert(make_pair(b, cnt++));
            
            cout << merge(nameToIndex[a], nameToIndex[b]) << "\n";
        }
    }
}