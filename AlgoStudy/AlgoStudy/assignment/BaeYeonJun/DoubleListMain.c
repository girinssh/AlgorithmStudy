#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"



//DList* Init_DList(void);
//
//int DListAppendNode(DList* dlist, int data);
//int DListInsertNode(DList* dlist, int index, int data);
//
//void PrintDList(DList* dlist);
//
//int DListRemoveNode(DList* dlist, int index);

int main(void) {
	int n;

	printf("처음 리스트의 크기를 입력해주세요 : ");
	int _ = scanf("%d", &n);

	printf("리스트에 들어갈 숫자들을 입력해주세요 : ");

	//리스트 초기화 부분
	DList* a = Init_DList();
	for (int i = 0; i < n; i++) {
		int tmp;
		_ = scanf("%d", &tmp);
		DListAppendNode(a, tmp);
	}

	while (1) {
		int sel;
		{
			fflush(stdout);
			puts("1.노드추가");
			puts("2.노드삽입");
			puts("3.노드제거");
			puts("4.리스트출력");
			puts("5.종료");
			puts("6.화면 청소");
			printf("//> : ");
			_ = scanf("%d", &sel);
		}
		puts("");
		switch (sel) {
		case 1: {
			printf("데이터를 입력하세요 : ");
			int data;
			_ = scanf("%d", &data);

			int state = DListAppendNode(a, data);
			state == 1 ? puts("추가되었습니다.") : puts("오류가 발생했습니다.");
			break;
		}
		case 2: {
			printf("데이터를 입력하세요 : ");
			int data;
			_ = scanf("%d", &data);

			printf("인덱스를 입력하세요(0부터) : ");
			int index;
			_ = scanf("%d", &index);

			int state = DListInsertNode(a, index, data);
			state == 1 ? puts("추가되었습니다.") : puts("오류가 발생했습니다.");
			break;
		}
		case 3: {
			printf("인덱스를 입력하세요 : ");
			int index;
			_ = scanf("%d", &index);

			int state = DListRemoveNode(a, index);
			state == 1 ? puts("제거되었습니다.") : puts("오류가 발생했습니다.");
			break;
		}
		case 4: {
			PrintDList(a);
			break;
		}
		{
		case 6:
			system("cls");
			break;
		default:
			break;
		}
		}
		if (sel == 5)
			break;
		else if (sel == 6)
			continue;
		puts("");
	}
	system("pause");
	return 0;
}
//노드 삭제, 노드 추가, 노드 삽입, 리스트 출력, 종료