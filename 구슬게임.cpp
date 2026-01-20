#include <bits/stdc++.h>

using namespace std;

int b[3], cache[501][501];

int canWin(int k0, int k1) {
  if ((k0 < b[0] && k0 < b[1] && k0 < b[2]) &&
      (k1 < b[0] && k1 < b[1] && k1 < b[2]))
    return 0;

  int &ret = cache[k0][k1];
  if (ret != -1)
    return ret;
  ret = 0;

  for (int i = 0; i < 3; i++) {
    if (k0 >= b[i])
      ret = (ret | !(canWin(k0 - b[i], k1)));
    if (k1 >= b[i])
      ret = (ret | !(canWin(k0, k1 - b[i])));
  }

  return ret;
}

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  for (int T = 0; T < 5; T++) {
    memset(cache, -1, sizeof(cache));

    int k0, k1;
    cin >> k0 >> k1;

    if (canWin(k0, k1))
      cout << "A\n";
    else
      cout << "B\n";
  }
}
