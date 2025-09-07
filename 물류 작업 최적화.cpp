#include <bits/stdc++.h>

using namespace std;

const int INF = -300000001;

int N, A[300001], cache[300001][2];
int d[] = {-1, 1};

int solve(int idx, int direction) {
  if (idx == 0 || idx == N + 1)
    return 0;

  int &ret = cache[idx][direction];
  if (ret != INF)
    return ret;

  return ret = A[idx] + max(0, solve(idx + d[direction], direction));
}

int main() {
  for (int i = 0; i <= 300000; i++) {
    for (int j = 0; j < 2; j++) {
      cache[i][j] = INF;
    }
  }

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  solve(N, 0);
  solve(1, 1);

  for (int i = 1; i <= N; i++) {
    cout << cache[i][0] + cache[i][1] - A[i] << " ";
  }
}
