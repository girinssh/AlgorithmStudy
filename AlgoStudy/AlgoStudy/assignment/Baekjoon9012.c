#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n = 0;
	scanf("%d", &n);
	
	while (n--) {
		char s[51];
		scanf("%s", s);
		fflush(stdin);
		int cnt = 0;
		int state = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '(') {
				cnt++;
				continue;
			}
			else if (s[i] == ')') {
				cnt--;
			}
			if (cnt < 0) {
				state = 1;
				break;
			}
		}
		if (state || cnt != 0) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	//system("pause");
	return 0;
}