#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	int N, M;
	cin >> N >> M;
	
	map<int, string> m1;
	map<string, int> m2;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m1.insert(make_pair(i + 1, s));
		m2.insert(make_pair(s, i + 1));
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (s[0] >= 49 && s[0] <= 57) {
			cout << m1.find(stoi(s))->second << '\n';
		}
		else {
			cout << m2.find(s)->second << '\n';
		}
	}
}
