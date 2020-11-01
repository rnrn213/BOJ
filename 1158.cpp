#include <bits/stdc++.h>

using namespace std;

class Node {
private:
	int data;
	Node* link;
public:
	Node(int _data) : data(_data), link(NULL) {}
	int getData() {
		return data;
	}
	Node* getLink() {
		return link;
	}
	void setLink(Node* p) {
		link = p;
	}
};

class myQueue {
private:
	Node* head;
	Node* tail;
public:
	myQueue(int N) {
		head = tail = new Node(1);
		for (int i = 2; i <= N; i++) {
			tail->setLink(new Node(i));
			tail = tail->getLink();
		}
	}
	
	bool isEmpty() {
		return head == NULL;
	}
	
	void insert(int val) {
		if (head == NULL) {
			head = tail = new Node(val);
		}
		else {
			tail->setLink(new Node(val));
			tail = tail->getLink();
		}
	}
	
	int pop() {
		if (head == NULL) return -1;
		if (head == tail) {
			Node* p = head;
			int val = head->getData();
			head = tail = NULL;
			delete p;
			return val;
		}
		else {
			Node* p = head;
			int val = head->getData();
			head = head->getLink();
			delete p;
			return val;
		}
	}
	
	void print() {
		while(head) {
			cout << head->getData() << " ";
			head = head->getLink();
		}
		cout << endl;
	}
	
};

int main() {
	int N, K;
	cin >> N >> K;
	myQueue q(N);
	
	int count = 1;
	cout << "<";
	while(true) {
		if (count == K) {
			cout << q.pop();
			if (!q.isEmpty()) cout << ", ";
			else break;
			count = 1;
		}
		else {
			int val = q.pop();
			q.insert(val);
			count++;
		}
	}
	cout << ">";
}
