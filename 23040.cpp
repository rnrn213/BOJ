#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
string C;

struct Node {
    long long path = 0;
    int idx;
    char color;
    vector<Node*> child;
    Node* parent;
} root;

vector<bool> visited(100001, false);

void makeTree(Node* node) {
    for (int i = 0; i < adj[node->idx].size(); i++) {
        int next = adj[node->idx][i];
        if (!visited[next]) {
            visited[next] = true;
            Node *newNode = new Node();
            newNode->idx = next;
            newNode->color = C[next];
            newNode->parent = node;
            node->child.push_back(newNode);
        }
    }

    for (int i = 0; i < node->child.size(); i++) {
        makeTree(node->child[i]);
    }
}

long long getPath(Node *node) {
    for (int i = 0; i < node->child.size(); i++) {
        if (node->child[i]->color == 'R')
            node->path += 1 + getPath(node->child[i]);
        else
            getPath(node->child[i]);
    }

    return node->path;
}

long long ans = 0;

void traverse(Node *node) {
    long long res = 0;
    if (node->color == 'B') {
        Node *pNode = node;
        while (pNode->parent != NULL && pNode->parent->color == 'R')
            pNode = pNode->parent;
        if (pNode->color == 'R')
            res += 1 + pNode->path;
        for (int i = 0; i < node->child.size(); i++) {
            if (node->child[i]->color == 'R')
                res += 1 + node->child[i]->path;
        }
        
        ans += res;
    }

    for (int i = 0; i < node->child.size(); i++) {
        traverse(node->child[i]);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> C;
    C = to_string(0) + C;

    root.idx = 1; root.color = C[1];
    visited[1] = true;
    makeTree(&root);
    getPath(&root);
    traverse(&root);
    cout << ans;
}