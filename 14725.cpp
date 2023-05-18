#include <bits/stdc++.h>

using namespace std;

int N, K;

struct node {
    string name;
    vector<node*> c;
};
node root;

void printTree(node* node, int depth) {
    vector< pair<string, int> > v;
    for (int i = 0; i < node->c.size(); i++) {
        v.push_back(make_pair(node->c[i]->name, i));
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        string s = "";
        s.append(2 * depth, '-');
        s += v[i].first;
        cout << s << "\n";
        printTree(node->c[v[i].second], depth+1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        node* p = &root;

        cin >> K;
        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;
            
            bool isChild = false;
            for (int m = 0; m < p->c.size(); m++) {
                if (p->c[m]->name == s) {
                    p = p->c[m];
                    isChild = true;
                    break;
                }
            }

            if (!isChild) {
                node* n = new node();
                n->name = s;
                p->c.push_back(n);
                p = p->c.back();
            }
        }
    }

    printTree(&root, 0);
}