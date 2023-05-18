#include <bits/stdc++.h>

using namespace std;

int N;

struct Trie {
    int count = 0;
    bool finish;
    Trie* child[26];

    Trie() : finish(false) {
        memset(child, 0, sizeof(child));
    }

    string insert(const string& s, int i, bool isPrefix) {
        string ret = "";
        if (i == s.size()) {
            finish = true;
            count++;
            if (isPrefix && count > 1)
                ret += to_string(count);
        }
        else {
            if (isPrefix)
                ret += s[i];
            int cur = s[i] - 'a';
            if (child[cur] == NULL) {
                child[cur] = new Trie();
                isPrefix = false;
            }
            ret += child[cur]->insert(s, i+1, isPrefix);
        }

        return ret;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    Trie *root = new Trie();
    cin >> N;
    for (int i = 0; i < N; i++) {
        string nickname;
        cin >> nickname;
        cout << root->insert(nickname, 0, true) << "\n";
    }
}