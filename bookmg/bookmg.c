#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include < windows.h >
#include "timeMgr.h"
#include "structfile.h"
#include "bookAdmin.h"

int main(int argc, char* argv[]) {
	char text[20];
	strcpy(text, argv[1]);
	strcat(text, ".bin");
	int num;
	books* head = (books*)malloc(sizeof(books));
	head->link = NULL;
	printf(" \n[ �������� ���α׷� ]\n\n");
	readFile(head, text);
	Sleep(2000);
	//1. �����Է�\n 2. ���� �˻�\n 3. ���� ����&�ݳ�\n 4. ���� ����\n 5. ���� ����Ʈ\n 6. ����
	while (1) {
		menu(1);
		scanf("%d", &num);
		switch (num) {
		case 1:
			addBook(head, text);
			break;
		case 2:
			searchBook(head);
			break;
		case 3:
			printf("1. ����   2. �ݳ�\n >>");
			scanf("%d", &num);
			if (num == 1) borrowBook(head);
			else if (num == 2) returnBook(head);
			else printf("�߸��� �Է��Դϴ�.\n");
			break;
		case 4:
			deleteBook(head);
			break;
		case 5:
			printBook(head);
			break;
		case 6:
			printf("�̿����ּż� �����մϴ�.\n");
			writeFile(text, head);
			freeNode(head);
			free(head);
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}
}