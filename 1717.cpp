#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int>** sets = new set<int>*[n + 1](NULL);   //∫§≈Õ Ω·∫∏±‚ 
	/*for (int i = 0; i <= n; i++) {
		sets[i] = NULL;
	}*/
	
	for (int i = 0; i < m; i++) {
		int order, a, b;
		cin >> order >> a >> b;
		
		if (order == 0) {
			if (sets[a] == NULL && sets[b] == NULL) {
				set<int>* s = new set<int>;
				s->insert(a);
				s->insert(b);
				sets[a] = sets[b] = s;
			}
			else if (sets[a] == NULL) {
				sets[b]->insert(a);
				sets[a] = sets[b];
			}
			else if (sets[b] == NULL) {
				sets[a]->insert(b);
				sets[b] = sets[a];
			}
			else {
				/* set<int>* s = new set<int>;
				merge(sets[a]->begin(), sets[a]->end(),
						sets[b]->begin(), sets[b]->end(),
						inserter(*s, s->begin()));
				set<int>* pa = sets[a]; */
				if (sets[a]->size() > sets[b]->size()) {
					set<int>* pb = sets[b];
					sets[a]->insert(sets[b]->begin(), sets[b]->end());
					sets[b] = sets[a];
					delete pb;
				}
				else {
					set<int>* pa = sets[a];
					sets[b]->insert(sets[a]->begin(), sets[a]->end());
					sets[a] = sets[b];
					delete pa;
				}
				/*set<int>* pb = sets[b];
				delete pa, pb;*/
			}
		}
		else if (order == 1) {
			if (sets[a] == NULL || sets[b] == NULL) cout << "NO\n";
			else if (sets[a] == sets[b]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
