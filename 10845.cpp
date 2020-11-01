#include <bits/stdc++.h>

using namespace std;

class myQueue {
private:
	vector<int> q;
public:
	myQueue() : q() {}
	
	void push(int X) {
		q.push_back(X);
	}
	int pop() {
		if (q.size() == 0) return -1;
		else {
			int temp = q[0];
			q.erase(q.begin());
			return temp;
		}
	}
	int size() {
		return q.size();
	}
	int front() {
		if (q.size() == 0) return -1;
		else return q[0];
	}
	int back() {
		if (q.size() == 0) return -1;
		else return q[q.size() - 1];
	}
};

int main() {
	myQueue q;
	int N;
	cin >> N;
	string order;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			cout << q.pop() << '\n';
		}
		else if (order == "size") cout << q.size() << '\n';
		else if (order == "empty") {
			if (q.size() == 0) cout << "1\n";
			else cout << "0\n";
		}
		else if (order == "front") cout << q.front() << '\n';
		else if (order == "back") cout << q.back() << '\n';
	}
}
