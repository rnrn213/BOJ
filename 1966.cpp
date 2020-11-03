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
	int getPriority() {
		int priority = 0;
		for (int i = 0; i < q.size(); i++) {
			if (q[i] > priority) priority = q[i];
		}
		return priority;
	}
};

int main() {
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		myQueue q;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			q.push(num);
		}
		int count = 0;
		while (true) {
			int prior = q.getPriority();
			while (true) {
				if (q.front() == prior) break;
				q.push(q.pop());
				if (M == 0) M = q.size() - 1;
				else M--;
			}
			if (M == 0) {
				count++;
				break;
			}
			else {
				count++;
				q.pop();
				M--;
			}
		}
		cout << count << '\n';
	}
}
