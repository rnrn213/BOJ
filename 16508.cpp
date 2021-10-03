#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, string> > books;

int solve(string& T, int idx) {
    if (T.size() == 0)
        return 0;
    if (idx == N)
        return 2000000;

    string temp = T;
    bool isSelected = false;
    for (int i = 0; i < books[idx].second.size(); i++) {
        int findIdx = temp.find(books[idx].second[i]);
        if (findIdx != string::npos) {
            temp.erase(findIdx, 1);
            isSelected = true;
        }
    }

    if (isSelected) {
        return min(books[idx].first + solve(temp, idx + 1), solve(T, idx + 1));
    }
    else {
        return solve(T, idx + 1);
    }
}

int main() {
    string T;
    cin >> T;

    cin >> N;
    books = vector< pair<int, string> >(N);
    for (int i = 0; i < N; i++) {
        int price;
        string bookName;
        cin >> price >> bookName;

        books[i] = make_pair(price, bookName);
    }
    sort(books.begin(), books.end());

    int ans = solve(T, 0);
    if (ans == 2000000)
        cout << -1;
    else
        cout << ans;
}