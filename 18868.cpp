#include <bits/stdc++.h>

using namespace std;

int M, N;
int** planets;

bool isValid(int p1, int p2, int i, int j) {
    if (planets[p1][i] < planets[p1][j] && planets[p2][i] < planets[p2][j])
        return true;
    else if (planets[p1][i] == planets[p1][j] && planets[p2][i] == planets[p2][j])
        return true;
    else if (planets[p1][i] > planets[p1][j] && planets[p2][i] > planets[p2][j])
        return true;
    return false;
}

bool compareTwoPlanets(int p1, int p2) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!isValid(p1, p2, i, j))
                return false;
        }
    }
    return true;
}

int main() {
    cin >> M >> N;
    planets = new int*[M + 1];
    for (int i = 1; i <= M; i++) {
        planets[i] = new int[N + 1];
        for (int j = 1; j <= N; j++) {
            cin >> planets[i][j];
        }
    }
    int cnt = 0;
    for (int p1 = 1; p1 < M; p1++) {
        for (int p2 = p1 + 1; p2 <= M; p2++) {
            bool isEqual = compareTwoPlanets(p1, p2);
            if (isEqual) cnt++;
        }
    }
    cout << cnt;
}