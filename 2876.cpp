#include <bits/stdc++.h>

using namespace std;

int N, desk[100001][2], cache[100001][6];

void initCache() {
    memset(cache, -1, 100001 * 6 * sizeof(int));
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        desk[i][0] = a;
        desk[i][1] = b;
    }
}

int solve(int index, int num) {
    if (index == N + 1) return 0;

    int& ret = cache[index][num];
    if (ret != -1) return ret;
    ret = 0;
    if (desk[index][0] == num || desk[index][1] == num) {
        ret += 1 + solve(index + 1, num);
    }
    return ret;
}

pair<int, int> getAnswer() {
    int count[6] = {-1, 0, 0, 0, 0, 0};

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= N; j++) {
            count[i] = max(count[i], solve(j, i));
        }
    }
    return make_pair(*max_element(count + 1, count + 6), static_cast<int>(max_element(count + 1, count + 6) - count));

}

int main() {
    initCache();
    input();
    pair<int, int> answer = getAnswer();
    cout << answer.first << " " << answer.second;
}