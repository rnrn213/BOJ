#include <bits/stdc++.h>

using namespace std;

int white = 0;
int blue = 0;
int wb[] = {0, 0, 0};

int paper(int** A, int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) {
        return A[startY][startX];
    }

    int leftTop = paper(A, startX, startY, startX + (endX - startX) / 2, startY + (endY - startY) / 2);
    int rightTop = paper(A, startX + (endX - startX) / 2 + 1, startY, endX, startY + (endY - startY) / 2);
    int leftBottom = paper(A, startX, startY + (endY - startY) / 2 + 1, startX + (endX - startX) / 2, endY);
    int rightBottom = paper(A, startX + (endX - startX) / 2 + 1, startY + (endY - startY) / 2 + 1, endX, endY);

    if (leftTop == 1 && leftTop == rightTop && rightTop == leftBottom && leftBottom == rightBottom) {
        return 1;
    }
    else if (leftTop == 0 && leftTop == rightTop && rightTop == leftBottom && leftBottom == rightBottom) {
        return 0;
    }
    else {
        wb[leftTop]++;
        wb[rightTop]++;
        wb[leftBottom]++;
        wb[rightBottom]++;
        return 2;
    }
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int** A = new int*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            A[i][j] = num;
        }
    }

    int res = paper(A, 0, 0, N - 1, N - 1);
    if (res == 0 || res == 1) {
        wb[res]++;
    }
    cout << wb[0] << '\n' << wb[1];
}