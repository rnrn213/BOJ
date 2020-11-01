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
	int T;
	cin >> T;
	string ps;
	for (int i = 0; i < T; i++) {
		cin >> ps;
		myStack s;
		bool isVPS = true;
		for (int j = 0; j < ps.size(); j++) {
			if (ps[j] == '(') {
				s.push(1);
			}
			else {
				int temp = s.pop();
				if (temp == -1) isVPS = false;
			}
		}
		string result;
		if (s.size() != 0) isVPS = false;
		if (!isVPS) result = "NO\n";
		else result = "YES\n";
		cout << result;
	}
}
