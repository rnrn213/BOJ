#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector< vector<string> > words(26);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words[word[0] - 'a'].push_back(word);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;

        for (int j = 0; j < words[word[0] - 'a'].size(); j++) {
            if (word.size() <= words[word[0] - 'a'][j].size() && 
                word == words[word[0] - 'a'][j].substr(0, word.size())) {
                cnt++;
                break;
            }
        }
    }
    
    cout << cnt;
}