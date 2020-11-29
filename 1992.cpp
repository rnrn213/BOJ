#include <bits/stdc++.h>

using namespace std;

string init(char** A, int startX, int startY, int endX, int endY) {
    string s = "";
    if (endX - startX == 1 && endY - startY == 1) {
        if (A[startX][startY] == A[endX][startY] && A[endX][startY] == A[startX][endY] && A[startX][endY] == A[endX][endY]) {
            s += A[startX][startY];
        }
        else {
            string temp{A[startX][startY], A[startX][endY], A[endX][startY], A[endX][endY]};
            s += "(" + temp + ")";
        }
        return s;
    }

    string leftTop = init(A, startX, startY, startX + (endX - startX) / 2, startY + (endY - startY) / 2);
    string rightTop = init(A, startX, startY + (endY - startY) / 2 + 1, startX + (endX - startX) / 2, endY);
    string leftBottom = init(A, startX + (endX - startX) / 2 + 1, startY, endX, startY + (endY - startY) / 2);
    string rightBottom = init(A, startX + (endX - startX) / 2 + 1, startY + (endY - startY) / 2 + 1, endX, endY);

    if (leftTop.size() == 1 && leftTop == rightTop && rightTop == leftBottom && leftBottom == rightBottom) {
        return leftTop;
    }
    else {
        s += "(" + leftTop + rightTop + leftBottom + rightBottom + ")";
        return s;
    }
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N == 1) {
        string s;
        cin >> s;
        cout << s;
        return 0;
    }
    char** A = new char*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new char[N];
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            A[i][j] = s[j];
        }
    }

    string ans = init(A, 0, 0, N - 1, N - 1);
    cout << ans;
}