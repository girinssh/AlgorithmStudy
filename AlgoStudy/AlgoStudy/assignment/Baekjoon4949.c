#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int isBegan = 1;
	while (1) {
		char s1[101] = { 0 };
		char s[101] = { 0 };
		
		int state = 0;
		int EnterCnt = 0;
		
		char c = 0;
		while (1) {
			c = getc(stdin);
			if (c == '.')
				break;
			if (state != 1) {
				if (c == '\n') {
					if (!isBegan && EnterCnt == 0) {
						EnterCnt++;
						continue;
					}
				}
				s[strlen(s)] = c;
				int top = strlen(s1);
				if (c == '(' || c == '[') {
					s1[top] = c;
				}
				else if (c == ')' || c == ']') {
					if (top == 0)
						state = 1;
					else {
						if ((c == ')' && s1[top - 1] == '(')
							|| (c == ']' && s1[top - 1] == '['))
							s1[top - 1] = 0;
						else
							state = 1;
					}
				}
				else {}
			}
		}
		if (strlen(s) == 0)
			break;

		if (state == 1 || strlen(s1) != 0) 
			puts("no");
		else {
			puts("yes");
		}
		//fflush(stdin);
		isBegan = 0;
	}
	//system("pause");
	return 0;
}