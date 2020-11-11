#include <bits/stdc++.h>

using namespace std;

int searchTop(int* tops, int current) {
	int result = -1;
	for (int i = current - 1; i > 0; i--) {
		if (tops[i] >= tops[current]) {
			result = i;
			break;
		}
	}
	return result;
}

int getVal(vector< pair<int, int> >& tops, int current, int num) {
	int result = 0;
	while (true) {
		if (tops[current].first >= num) {
			result = current;
			break;
		}
		else {
			if (tops[current].second == 0) {
				result = 0;
				break;
			}
			else {
				current = tops[current].second;
			}
		}
	}
	return result;
}

int main() {
	int N, num;
	scanf("%d", &N);
	
	vector< pair<int, int> > tops(N + 1);
	tops[0] = make_pair(-1, -1);
	scanf("%d", &num);
	tops[1] = make_pair(num, 0);
	//clock_t start = clock();
	for (int i = 2; i <= N; i++) {
		scanf(" %d", &num);
		tops[i] = make_pair(num, getVal(tops, i - 1, num));
	}
	for (int i = 1; i < tops.size(); i++) {
		printf("%d ", tops[i].second);
	}
	//printf("\n");
	//clock_t end = clock();
	//printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}
