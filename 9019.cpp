#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        vector<bool> isVisited(10000, false);
        queue< pair<int, string> > q;
        q.push(make_pair(A, ""));
        isVisited[A] = true;
        while (!q.empty()) {
            int num = q.front().first;
            string command = q.front().second;
            q.pop();

            if (num == B) {
                cout << command << "\n";
                break;
            }

            int afterD = (2 * num) % 10000;
            if (!isVisited[afterD]) {
                q.push(make_pair(afterD, command + "D"));
                isVisited[afterD] = true;
            }

            int afterS = (num == 0) ? 9999 : num - 1;
            if (!isVisited[afterS]) {
                q.push(make_pair(afterS, command + "S"));
                isVisited[afterS] = true;
            }

            int afterL = (num / 1000) + ((num % 1000) * 10);
            if (!isVisited[afterL]) {
                q.push(make_pair(afterL, command + "L"));
                isVisited[afterL] = true;
            }

            int afterR = ((num % 10) * 1000) + (num / 10);
            if (!isVisited[afterR]) {
                q.push(make_pair(afterR, command + "R"));
                isVisited[afterR] = true;
            }
        }
    }
}