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

	printf("ó�� ����Ʈ�� ũ�⸦ �Է����ּ��� : ");
	int _ = scanf("%d", &n);

	printf("����Ʈ�� �� ���ڵ��� �Է����ּ��� : ");

	//����Ʈ �ʱ�ȭ �κ�
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
			puts("1.����߰�");
			puts("2.������");
			puts("3.�������");
			puts("4.����Ʈ���");
			puts("5.����");
			puts("6.ȭ�� û��");
			printf("//> : ");
			_ = scanf("%d", &sel);
		}
		puts("");
		switch (sel) {
		case 1: {
			printf("�����͸� �Է��ϼ��� : ");
			int data;
			_ = scanf("%d", &data);

			int state = DListAppendNode(a, data);
			state == 1 ? puts("�߰��Ǿ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
			break;
		}
		case 2: {
			printf("�����͸� �Է��ϼ��� : ");
			int data;
			_ = scanf("%d", &data);

			printf("�ε����� �Է��ϼ���(0����) : ");
			int index;
			_ = scanf("%d", &index);

			int state = DListInsertNode(a, index, data);
			state == 1 ? puts("�߰��Ǿ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
			break;
		}
		case 3: {
			printf("�ε����� �Է��ϼ��� : ");
			int index;
			_ = scanf("%d", &index);

			int state = DListRemoveNode(a, index);
			state == 1 ? puts("���ŵǾ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
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
//��� ����, ��� �߰�, ��� ����, ����Ʈ ���, ����