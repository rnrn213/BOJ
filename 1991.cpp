#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node *leftChildNode;
    Node *rightChildNode;
};

void Preorder(const vector< pair<char, char> >& nodes, char data) {
    cout << data;
    if (nodes[data - 'A'].first != '.')
        Preorder(nodes, nodes[data - 'A'].first);
    if (nodes[data - 'A'].second != '.')
        Preorder(nodes, nodes[data - 'A'].second);
}

void Inorder(const vector< pair<char, char> >& nodes, char data) {
    if (nodes[data - 'A'].first != '.')
        Inorder(nodes, nodes[data - 'A'].first);
    cout << data;
    if (nodes[data - 'A'].second != '.')
        Inorder(nodes, nodes[data - 'A'].second);
}

void Postorder(const vector< pair<char, char> >& nodes, char data) {
    if (nodes[data - 'A'].first != '.')
        Postorder(nodes, nodes[data - 'A'].first);
    if (nodes[data - 'A'].second != '.')
        Postorder(nodes, nodes[data - 'A'].second);
    cout << data;
}

int main() {
    int N;
    cin >> N;
    vector< pair<char, char> > nodes(N);
    for (int i = 0; i < N; i++) {
        char node, leftChild, rightChild;
        cin >> node >> leftChild >> rightChild;
        nodes[node - 'A'].first = leftChild;
        nodes[node - 'A'].second = rightChild;
    }

    Preorder(nodes, 'A');
    cout << "\n";
    Inorder(nodes, 'A');
    cout << "\n";
    Postorder(nodes, 'A');
}