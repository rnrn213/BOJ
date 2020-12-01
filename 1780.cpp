#include <bits/stdc++.h>

using namespace std;

void paper(int** A, int &a, int &b, int &c, int startX, int startY, int endX, int endY) {
    if (endX - startX == 2 && endY - startY == 2) {
        for (int i = startY; i <= endY; i++) {
            for (int j = startX; j <= endX; j++) {
                if (A[i][j] == -1) {
                    a++;
                }
                else if (A[i][j] == 0) {
                    b++;
                }
                else {
                    c++;
                }
            }
        }
        if (b == 0 && c == 0)
            a = 1;
        else if (a == 0 && c == 0)
            b = 1;
        else if (a == 0 && b == 0)
            c = 1;
        return;
    }

    vector<int> aa(9, 0);
    vector<int> bb(9, 0);
    vector<int> cc(9, 0);

    int gap = (endX + 1 - startX) / 3;
    paper(A, aa[0], bb[0], cc[0], startX, startY, startX + gap - 1, startY + gap - 1);
    paper(A, aa[1], bb[1], cc[1], startX + gap, startY, startX + 2 * gap - 1, startY + gap - 1);
    paper(A, aa[2], bb[2], cc[2], startX + 2 * gap, startY, startX + 3 * gap - 1, startY + gap - 1);
    paper(A, aa[3], bb[3], cc[3], startX, startY + gap, startX + gap - 1, startY + 2 * gap - 1);
    paper(A, aa[4], bb[4], cc[4], startX + gap, startY + gap, startX + 2 * gap - 1, startY + 2 * gap - 1);
    paper(A, aa[5], bb[5], cc[5], startX + 2 * gap, startY + gap, startX + 3 * gap - 1, startY + 2 * gap - 1);
    paper(A, aa[6], bb[6], cc[6], startX, startY + 2 * gap, startX + gap - 1, startY + 3 * gap - 1);
    paper(A, aa[7], bb[7], cc[7], startX + gap, startY + 2 * gap, startX + 2 * gap - 1, startY + 3 * gap - 1);
    paper(A, aa[8], bb[8], cc[8], startX + 2 * gap, startY + 2 * gap, startX + 3 * gap - 1, startY + 3 * gap - 1);

    for (int i = 0; i < 9; i++) {
        if (bb[i] == 0 && cc[i] == 0) {
            a++;
        }
        else if (aa[i] == 0 && cc[i] == 0) {
            b++;
        }
        else if (aa[i] == 0 && bb[i] == 0) {
            c++;
        }
        else {
            a += aa[i];
            b += bb[i];
            c += cc[i];
        }
    }
    if (b == 0 && c == 0)
            a = 1;
    else if (a == 0 && c == 0)
        b = 1;
    else if (a == 0 && b == 0)
        c = 1;
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N == 1) {
        int num;
        cin >> num;
        if (num == -1) {
            cout << 1 << '\n' << 0 << '\n' << 0;
        }
        else if (num == 0) {
            cout << 0 << '\n' << 1 << '\n' << 0;
        }
        else {
            cout << 0 << '\n' << 0 << '\n' << 1;
        }
        return 0;
    }

    int** A = new int*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            A[i][j] = num;
        }
    }

    int a = 0;
    int b = 0;
    int c = 0;
    paper(A, a, b, c, 0, 0, N - 1, N - 1);

    cout << a << '\n' << b << '\n' << c;
}