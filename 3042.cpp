#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > words;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;

            if (c != '.') {
                words.push_back(make_pair(i, j));
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < words.size() - 2; i++) {
        for (int j = i + 1; j < words.size() - 1; j++) {
            for (int k = j + 1; k < words.size(); k++) {
                if (words[i].first * words[j].second + words[j].first * words[k].second + words[k].first * words[i].second
                    - words[i].second * words[j].first - words[j].second * words[k].first - words[k].second * words[i].first == 0)
                    cnt++;
            }
        }
    }

    cout << cnt;
}