#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		deque<int> dq;
		bool isFront = true;
		bool isError = false;
		char* p = new char[100010];
		scanf("%s", p);
		//cout << "strlen(p) : " << strlen(p) << '\n';
		int n = 0;
		scanf("%d", &n);
		//cout << "n : " << n << '\n';
		int num = 0;
		char c;
		for (int j = 0; j < n; j++) {
			cin >> c >> num;
			dq.push_back(num);
			//printf("%d push", num);
		}
		if (n == 0) {
			cin >> c;
		}
		cin >> c;
		//printf("\n");
		
		for (int j = 0; j < strlen(p); j++) {
			if (p[j] == 'R') {
				if (isFront == true) {
					isFront = false;
				}
				else {
					isFront = true;
				}
			}
			if (p[j] == 'D') {
				if (dq.empty()) {
					isError = true;
				}
				if (isFront == true) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		
		if (isError) {
			printf("error\n");
		}
		else {
			printf("[");
			if (isFront) {
				while (dq.size() > 1) {
					printf("%d,", dq.front());
					dq.pop_front();
				}
				if (dq.size() == 1) {
					printf("%d", dq.front());
					dq.pop_front();
				}
				printf("]\n");
			}
			else {
				while (dq.size() > 1) {
					printf("%d,", dq.back());
					dq.pop_back();
				}
				if (dq.size() == 1) {
					printf("%d", dq.back());
					dq.pop_back();
				}
				printf("]\n");
			}
		}
		delete [] p;
	}
}
