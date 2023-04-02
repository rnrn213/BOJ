#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > X, Y, Z;
vector< pair<int, pair<int, int> > > planets(100000);
vector<bool> added(100000, false);

// long long prim() {
//     long long ret = 0;

//     priority_queue< pair<int, int>, vector< pair<int, int> >, greater<>> pq;
//     int v = 0;
//     added[0] = true;
//     for (int i = 0; i < N; i++) {
//         int idx = planets[v].first;
//         int left = idx - 1, right = idx + 1, cost;
//         while (left >= 0 || right < N) {
//             if (left >= 0 && !added[left]) {
//                 cost = abs(X[idx].first - X[left].first);
//                 pq.push(make_pair(cost, X[left].second));
//                 left = -1;
//             }
//             if (right < N && !added[right]) {
//                 cost = abs(X[idx].first - X[right].first);
//                 pq.push(make_pair(cost, X[right].second));
//                 right = N;
//             }

//             if (left != -1) left--;
//             if (right != N) right++;
//         }

//         idx = planets[v].second.first;
//         left = idx - 1, right = idx + 1;
//         while (left >= 0 || right < N) {
//             if (left >= 0 && !added[left]) {
//                 cost = abs(Y[idx].first - Y[left].first);
//                 pq.push(make_pair(cost, Y[left].second));
//                 left = -1;
//             }
//             if (right < N && !added[right]) {
//                 cost = abs(Y[idx].first - Y[right].first);
//                 pq.push(make_pair(cost, Y[right].second));
//                 right = N;
//             }

//             if (left != -1) left--;
//             if (right != N) right++;
//         }

//         idx = planets[v].second.second;
//         left = idx - 1, right = idx + 1;
//         while (left >= 0 || right < N) {
//             if (left >= 0 && !added[left]) {
//                 cost = abs(Z[idx].first - Z[left].first);
//                 pq.push(make_pair(cost, Z[left].second));
//                 left = -1;
//             }
//             if (right < N && !added[right]) {
//                 cost = abs(Z[idx].first - Z[right].first);
//                 pq.push(make_pair(cost, Z[right].second));
//                 right = N;
//             }

//             if (left != -1) left--;
//             if (right != N) right++;
//         }

//         ret += pq.top().first;
//         v = pq.top().second;
//         added[v] = true;
//         pq.pop();
//     }

//     return ret;
// }

vector<int> parent(100000);

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    parent[u] = v;
    return true;
}

long long kruskal() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }


    long long ret = 0;
    int cnt = 0;
    for (int interval = 1; interval < N; interval++) {
        vector< pair<int, pair<int, int> > > edges;

        for (int i = 0; i + interval < N; i++) {
            int cost = abs(X[i].first - X[i + interval].first);
            int u = X[i].second, v = X[i + interval].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));

            cost = abs(Y[i].first - Y[i + interval].first);
            u = Y[i].second, v = Y[i + interval].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));

            cost = abs(Z[i].first - Z[i + interval].first);
            u = Z[i].second, v = Z[i + interval].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }

        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); i++) {
            int cost = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;

            if (merge(u, v)) {
                ret += cost;
                cnt++;
            }

            if (cnt == N - 1) return ret;
        }
    }

    return -1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
        Z.push_back(make_pair(z, i));
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N; i++) {
        planets[X[i].second].first = i;
        planets[Y[i].second].second.first = i;
        planets[Z[i].second].second.second = i;
    }

    //cout << prim();
    cout << kruskal();
}