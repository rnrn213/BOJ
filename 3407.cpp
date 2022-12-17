#include <bits/stdc++.h>

using namespace std;

vector<string> periodicTable = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv"};

int adj[26][26], T, cache[50001];
string word;

void initGraph() {
    for (int i = 0; i < periodicTable.size(); i++) {
        if (periodicTable[i].size() == 1) {
            adj[periodicTable[i][0]- 'a'][periodicTable[i][0]- 'a'] = 1;
        }
        else {
            adj[periodicTable[i][0]- 'a'][periodicTable[i][1]- 'a'] = 1;
        }
    }
}

int solve(int idx) {
    if (idx == word.size()) return 1;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 0;

    if (adj[word[idx] - 'a'][word[idx] - 'a'])
        ret = ret || solve(idx + 1);
    
    if (idx + 1 < word.size() && adj[word[idx] - 'a'][word[idx + 1] - 'a'])
        ret = ret || solve(idx + 2);

    return ret;
}

int main() {
    memset(adj, 0, sizeof(adj));
    initGraph();
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        memset(cache, -1, sizeof(cache));

        cin >> word;

        if (solve(0)) cout << "YES\n";
        else cout << "NO\n";
    }
}