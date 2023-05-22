#include <bits/stdc++.h>

using namespace std;

int N, longest, ans;
vector<int> adj[100001], visited(100001, 0);

struct Node {
    int num;
    vector<Node*> child;
} root;

void makeTree(Node* root) {
    for (int i = 0; i < adj[root->num].size(); i++) {
        int c = adj[root->num][i];
        if (!visited[c]) {
            visited[c] = 1;
            Node* newNode = new Node();
            newNode->num = c;
            root->child.push_back(newNode);
            makeTree(newNode);
        }
    }
}

int height(Node* root) {
    vector<int> heights;
    for (int i = 0; i < root->child.size(); i++) 
        heights.push_back(height(root->child[i]));
    if (heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    if (heights.size() >= 2) {
        int diameter = 2 + heights[heights.size() - 2] +
                                heights[heights.size() - 1];
        if (longest < diameter) {
            longest = diameter;
            if (diameter % 2 == 1) diameter++;
            ans = diameter / 2;
        }
    }
    return heights.back() + 1;
}

int solve(Node* root) {
    longest = 0;
    int h = height(root);
    if (h > longest) {
        if (h % 2 == 1) h++;
        ans = h / 2;
    }
    return ans;
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> N;
    int start;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root.num = 1;
    visited[1] = 1;
    makeTree(&root);

    cout << solve(&root);
}