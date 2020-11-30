#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N, r, c;
    cin >> N >> r >> c;

    int startX = 0;
    int startY = 0;
    int maxX = static_cast<int>(pow(2, N)) - 1;
    int maxY = static_cast<int>(pow(2, N)) - 1;
    int midX = maxX / 2;
    int midY = maxY / 2;
    long long count = 0;
    while (maxX - startX != 1 && maxY - startY != 1) {
        if (r <= midX && c <= midY) {
            maxX = midX;
            maxY = midY;
        }
        else if (r <= midX && c > midY) {
            count += (midX - startX + 1) * (midY - startY + 1);
            maxX = midX;
            startY = midY + 1;
        }
        else if (r > midX && c <= midY) {
            count += 2 * (midX - startX + 1) * (midY - startY + 1);
            maxY = midY;
            startX = midX + 1;
        }
        else {
            count += 3 * (midX - startX + 1) * (midY - startY + 1);
            startX = midX + 1;
            startY = midY + 1;
        }
        midX = startX + (maxX - startX) / 2;
        midY = startY + (maxY - startY) / 2;
    }
    count += 2 * (r - startX) + (c - startY);

    cout << count;
}