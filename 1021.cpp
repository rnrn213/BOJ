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

class circularQueue {
	private:
		Node* head;
		Node* tail;
		int size;
	public:
		circularQueue() : head(NULL), tail(NULL), size(0) {}
		
		void insert(int data) {
			if (head == NULL) {
				Node* p = new Node(data);
				head = tail = p;
				size++;
			}
			else {
				Node* p = new Node(data);
				head->setPrev(p);
				p->setNext(head);
				p->setPrev(tail);
				head = p;
				tail->setNext(head);
				size++;
			}
		}
		int pop() {
			if (head == NULL) return -1;
			else if (size == 1) {
				Node* p = head;
				head = tail = NULL;
				int temp = p->getData();
				delete p;
				size--;
				return temp;
			}
			else {
				Node* p = head;
				head = head->getNext();
				head->setPrev(p->getPrev());
				p->getPrev()->setNext(head);
				int temp = p->getData();
				delete p;
				size--;
				return temp;
			}
		}
		int searchRight(int index) {
			int count = 0;
			Node* p = head;
			while (p) {
				if (p->getData() == index) break;
				p = p->getPrev();
				count++;
			}
			return count;
		}
		int searchLeft(int index) {
			int count = 0;
			Node* p = head;
			while (p) {
				if (p->getData() == index) break;
				p = p->getNext();
				count++;
			}
			return count;
		}
		int move(int index) {
			if (searchLeft(index) > searchRight(index)) {
				int min = searchRight(index);
				for (int i = 0; i < min; i++) {
					head = head->getPrev();
				}
				return min;
			}
			else {
				int min = searchLeft(index);
				for (int i = 0; i < min; i++) {
					head = head->getNext();
				}
				return min;
			}
		}
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	
	circularQueue cq;
	for (int i = N; i > 0; i--) {
		cq.insert(i);
	}
	
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int num;
		scanf(" %d", &num);
		ans += cq.move(num);
		cq.pop();
	}
	printf("%d", ans);
}
