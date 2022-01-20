#include <bits/stdc++.h>

using namespace std;

double adj[4][4], cache[11][4][4], ans[4];

void initCache() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cache[i][j][k] = -1.0;
            }
        }
    }
}

void initAdj() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            adj[i][j] = -1.0;
        }
    }
}

void init() {
    initCache();
    initAdj();
}

double shopping(int time, int start, int end) {
    if (time == 1 && adj[start][end] > numeric_limits<double>::epsilon())
        return adj[start][end];
    else if (time == 1)
        return 0.0;
    
    double &ret = cache[time][start][end];
    if (ret > numeric_limits<double>::epsilon())
        return ret;
    ret = 0.0;

    for (int next = 0; next < 4; next++) {
        if (adj[start][next] > numeric_limits<double>::epsilon()) {
            ret += adj[start][next] * shopping(time - 1, next, end);
        }
    }
    
    return ret;
}

int main() {
    init();

    int time, M;
    cin >> time >> M;
    for (int i = 0; i < M; i++) {
        char start, end;
        double p;
        cin >> start >> end >> p;
        adj[start - 'A'][end - 'A'] = p;
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            ans[j] += (1.0 / 4) * shopping(time, i, j);
        }
    }

    cout << fixed;
    cout.precision(2);
    for (int i = 0; i < 4; i++)
        cout << ans[i] * 100 << "\n";
}