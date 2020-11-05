#include <bits/stdc++.h>                              //iterator·Î ±¸Çö 

using namespace std;

list<char> editor;
list<char>::iterator cursor; 
void moveCursor(int direction) {
	if (direction == 1) {
		if (cursor != editor.end()) cursor++;
	}
	else {
		if (cursor != editor.begin()) cursor--;
	}
}

void eraseChar() {
	if (cursor == editor.begin()) return;
	else {
		cursor--;
		cursor = editor.erase(cursor);
	}
}

void insertChar(char c) {
	if (cursor == editor.end()) {
		editor.push_back(c);
		cursor = editor.end();
	}
	else {
		cursor = editor.insert(cursor, c);
		cursor++;
	}
}

int main() {
	string s;
	cin >> s;
	for (auto w: s) {
		editor.push_back(w);
	}
	cursor = editor.end();
	
	int M;
	char order;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf(" %c", &order);
		
		//clock_t start = clock();
		switch(order) {
			case 'L':
				moveCursor(-1);
				break;
			case 'D':
				moveCursor(1);
				break;
			case 'B':
				eraseChar();
				break;
			case 'P':
				char c;
				scanf(" %c", &c);
				insertChar(c);
				break;
			default:
				break;
		}
		//clock_t end = clock();
		//printf("%c Time: %lf\n", order, (double)(end - start)/CLOCKS_PER_SEC);
	}
	for (auto w: editor) {
		printf("%c", w);
	}
}
