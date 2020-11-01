#include <bits/stdc++.h>

using namespace std;

class myStack {
private:
    vector<int> s;
public:
    myStack(): s() {}

    void push(int X) {
        s.push_back(X);
    }
    int pop() {
        if (s.size() == 0) return -1;
        else {
            int temp = s[s.size() - 1];
            s.erase(s.end() - 1);
            return temp;
        }
    }
    int size() {
        return s.size();
    }
    int top() {
        if (s.size() == 0) return -1;
        else return s[s.size() - 1];
    }
};

int main() {
    myStack s;
    int N;
    cin >> N;
    string order;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> order;
        if (order == "push") {
            cin >> num;
            s.push(num);
        }
        else if (order == "pop") {
            cout << s.pop() << '\n';
        }
        else if (order == "size") {
            cout << s.size() << '\n';
        }
        else if (order == "empty") {
            if (s.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (order == "top") {
            cout << s.top() << '\n';
        }
    }
}
