#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	int n;

	printf("ó�� ����Ʈ�� ũ�⸦ �Է����ּ��� : ");
	scanf("%d", &n);

	printf("����Ʈ�� �� ���ڵ��� �Է����ּ��� : ");

	//����Ʈ �ʱ�ȭ �κ�
	List a = Init_List();
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		AppendNode(&a, tmp);
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
			scanf("%d", &sel);
		}
		puts("");
		switch (sel) {
		case 1: {
			printf("�����͸� �Է��ϼ��� : ");
			int data;
			scanf("%d", &data);

			int state = AppendNode(&a, data);
			state == 1 ? puts("�߰��Ǿ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
			break;
		}
		case 2: {
			printf("�����͸� �Է��ϼ��� : ");
			int data;
			scanf("%d", &data);

			printf("�ε����� �Է��ϼ���(0����) : ");
			int index;
			scanf("%d", &index);

			int state = InsertNode(&a, index, data);
			state == 1 ? puts("�߰��Ǿ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
			break;
		}
		case 3: {
			printf("�ε����� �Է��ϼ��� : ");
			int index;
			scanf("%d", &index);

			int state = RemoveNode(&a, index);
			state == 1 ? puts("���ŵǾ����ϴ�.") : puts("������ �߻��߽��ϴ�.");
			break;
		}
		case 4: {
			PrintList(&a);
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