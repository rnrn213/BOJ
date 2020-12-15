#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N, R, G, B;
    cin >> N >> R >> G >> B;
    int sum[3] = {R, G, B};
    
    for (int i = 1; i < N; i++) {
        cin >> R >> G >> B;
        int temp0, temp1, temp2;
        temp0 = min(R + sum[1], R + sum[2]);
        temp1 = min(G + sum[0], G + sum[2]);
        temp2 = min(B + sum[0], B + sum[1]);
        sum[0] = temp0;
        sum[1] = temp1;
        sum[2] = temp2;
    }

    cout << *min_element(sum, sum + 3);
}