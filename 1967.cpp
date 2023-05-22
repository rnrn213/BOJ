#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector< pair<int, int> > adj[10001];

struct Node {
    int num;
    vector< pair<Node*, int> > child;

} root;

void makeTree(Node* root) {
    for (int i = 0; i < adj[root->num].size(); i++) {
        int num = adj[root->num][i].first,
            w = adj[root->num][i].second;
        Node* node = new Node();
        node->num = num;
        root->child.push_back(make_pair(node, w));
        makeTree(root->child[i].first);
    }
}

int getDiameter(Node* node) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < node->child.size(); i++) {
        int length = node->child[i].second + getDiameter(node->child[i].first);
        if (length > max1) {
            max2 = max1;
            max1 = length;
        }
        else if (length > max2) max2 = length;
    }

    if (max1 + max2 > ans) ans = max1 + max2;

    return max1;
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    vector<Node*> v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back(make_pair(c, w));
    }

    root.num = 1;
    makeTree(&root);

    int d = getDiameter(&root);

    cout << max(d, ans);
}