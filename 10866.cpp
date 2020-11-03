#include <bits/stdc++.h>

using namespace std;

class Node {
private:
	int data;
	Node* prev;
	Node* next;
public:
	Node(int _data=0) : data(_data), prev(NULL), next(NULL) {}
	int getData() {
		return data;
	}
	Node* getPrev() {
		return prev;
	}
	Node* getNext() {
		return next;
	}
	void setPrev(Node* p) {
		prev = p;
	}
	void setNext(Node* p) {
		next = p;
	}
};

class myDeque {
private:
	Node* head;
	Node* tail;
	int size;
public:
	myDeque() : head(NULL), tail(NULL) { size = 0; }
	void push_front(int X) {
		if (head == NULL) {
			head = tail = new Node(X);
			size++;
		}
		else {
			Node* p = head;
			head->setPrev(new Node(X));
			head = head->getPrev();
			head->setNext(p);
			size++;
		}
	}
	void push_back(int X) {
		if (tail == NULL) {
			tail = head = new Node(X);
			size++;
		}
		else {
			Node* p = tail;
			tail->setNext(new Node(X));
			tail = tail->getNext();
			tail->setPrev(p);
			size++;
		}
	}
	int pop_front() {
		if (head == NULL) return -1;
		else if (head == tail) {
			int result = head->getData();
			delete head;
			head = tail = NULL;
			size--;
			return result;
		}
		else {
			int result = head->getData();
			Node* p = head;
			head = head->getNext();
			delete p;
			size--;
			return result;
		}
	}
	int pop_back() {
		if (tail == NULL) return -1;
		else if (tail == head) {
			int result = tail->getData();
			delete tail;
			tail = head = NULL;
			size--;
			return result;
		}
		else {
			int result = tail->getData();
			Node* p = tail;
			tail = tail->getPrev();
			delete p;
			size--;
			return result;
		}
	}
	int getSize() {
		return size;
	}
	int front() {
		if (head == NULL) return -1;
		else return head->getData();
	}
	int back() {
		if (tail == NULL) return -1;
		else return tail->getData();
	}
};
int main() {
	int N;
	cin >> N;
	
	myDeque dq;
	string order;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (order == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (order == "pop_front") cout << dq.pop_front() << '\n';
		else if (order == "pop_back") cout << dq.pop_back() << '\n';
		else if (order == "size") cout << dq.getSize() << '\n';
		else if (order == "empty") {
			if (dq.getSize() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (order == "front") cout << dq.front() << '\n';
		else if (order == "back") cout << dq.back() << '\n';
	}
}
