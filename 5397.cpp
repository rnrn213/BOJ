#include <bits/stdc++.h>

using namespace std;

void getPassword(const char* const keylogger, list<char>& password) {
	list<char>::iterator cursor = password.begin();
	for (int i = 0; i < strlen(keylogger); i++) {
		if (keylogger[i] == '<') {
			if (cursor != password.begin()) cursor--;
		}
		else if (keylogger[i] == '>') {
			if (cursor != password.end() - 1) cursor++;
		}
		else if (keylogger[i] == '-') {
			
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		char* keylogger = new char[1000001];
		fgets(keylogger, sizeof(char)*1000001, stdin);
		for (int j = 0; j < strlen(keylogger); j++) {
			printf("%c", keylogger[j]);
		}
		printf("\n");
		
		list<char> password;
		
	}
}
