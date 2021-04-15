#include <bits/stdc++.h>

using namespace std;

int N, cache[300001];
vector<int> tetrahedron;

void input() {
    cin >> N;
}

int sum(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    return sum;
}

void init() {
    for (int i = 0; i <= 300000; i++) {
        cache[i] = 1000000;
    }

    int num = 1, i = 1;
    while (num <= 300000) {
        tetrahedron.push_back(num);
        num += sum(++i);
    }
}

int getIndex(int num) {
    int i = tetrahedron.size() - 1;
    while (tetrahedron[i] > num) {
        i--;
    }
    return i;
}

int solve(int num) {
    if (num == 0) return 0;

    int& ret = cache[num];
    if (ret != 1000000) return ret;
    int initialIndex = getIndex(num);
    ret = min(ret, 1 + solve(num - tetrahedron[initialIndex]));
    for (int i = initialIndex - 1; i >= 0 && tetrahedron[i] > num - tetrahedron[initialIndex]; i--) {
        ret = min(ret, 1 + solve(num - tetrahedron[i]));
    }
    return ret;
}

int main() {
    input();
    init();
    cout << solve(N);
}