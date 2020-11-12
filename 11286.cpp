#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	priority_queue< int, vector<int>, greater<int> > ppq;
	priority_queue< int, vector<int> > npq;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		
		if (num == 0) {
			if (ppq.empty() && npq.empty()) printf("0\n");
			else if (ppq.empty()) {
				printf("%d\n", npq.top());
				npq.pop();
			}
			else if (npq.empty()) {
				printf("%d\n", ppq.top());
				ppq.pop();
			}
			else if (ppq.top() == abs(npq.top())) {
				printf("%d\n", npq.top());
				npq.pop();
			}
			else {
				if (ppq.top() > abs(npq.top())) {
					printf("%d\n", npq.top());
					npq.pop();
				}
				else {
					printf("%d\n", ppq.top());
					ppq.pop();
				}
			}
		}
		else if (num > 0) {
			ppq.push(num);
		}
		else {
			npq.push(num);
		}
	}
}
