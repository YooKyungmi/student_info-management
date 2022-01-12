#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include < windows.h >
#include <time.h>
#include "timeMgr.h"
#include "structfile.h"
#include "bookAdmin.h"

#define IS ==

void menu(int a) {
	if (a IS 1) {
		Sleep(200);
		system("cls");
		printf("\n\t< MENU >\n");
		printf("    1. �����Է�\n    2. ���� �˻�\n    3. ���� ����&�ݳ�\n    4. ���� ����\n    5. ���� ����Ʈ\n    6. ����\n    >>");
	}
	else if (a IS 2) {
		Sleep(200);
		system("cls");
		printf("\n\t< SEARCH OPTION >\n");
		printf("      1. �����ڵ�� �˻�\n      2. ���������� �˻�\n      3. ���ڷ� �˻�\n      >>");
	}
	else {
		Sleep(200);
		system("cls");
		printf("\n\t< PRINT OPTION >\n");
		printf("      1. ��ü ���� ���\n      2. ���� ������ ���� ���\n      3. ���� ���� ���� ���\n      >>");
	}
}


void readFile(books* list, char text[20]) {
	FILE* fp = fopen(text, "rb");
	if (fp == NULL) 
		fp = fopen(text, "wb");

	element input;
	books* cur = list;
	while ((fread(&input, sizeof(input), 1, fp)) > 0) {
		books* newNode = (books*)malloc(sizeof(books));
		newNode->data = input;
		newNode->link = cur->link;
		cur->link = newNode;
		cur = cur->link;
	}
	fclose(fp);
}

void writeFile(char text[20], books* head) {
	FILE* fp = fopen(text, "wb");
	books* cur = head->link;
	element input;
	while (cur != NULL)
	{
		input = cur->data;
		fwrite(&input, sizeof(input), 1, fp);
		cur = cur->link;
	}
	fclose(fp);
}

void freeNode(books* head) {
	books* cur = head->link;
	while (cur != NULL)
	{
		books* next = cur->link;
		free(cur);
		cur = next;
	}
}


void addBook(books* list, char text[20]) {

	char ck;   //check
	char go = 'y';
	int code;
	FILE* fp = fopen(text, "ab");
	printf(" < ���� �Է� > \n");
	while (go IS 'y') {
		books* newBook = (books*)malloc(sizeof(books));
		element input;
		ck = 'n';
		while (ck IS 'n') {
			printf("\n�����ڵ� ���� : ");
			scanf("%u", &code);
			input.cd.cc.kubun = code;
			printf("�����ڵ� Ÿ�� : ");
			scanf("%u", &code);
			input.cd.cc.type = code;
			printf("�����ڵ� ��ȣ : ");
			scanf("%u", &code);
			input.cd.cc.number = code;
			printf("������: ");
			scanf("%s", input.bk_name);
			printf("���ڸ�: ");
			scanf("%s", input.bk_author);
			printf("��������: ");
			scanf("%d", &input.bk_cost);

			printf("%08x %s %s %d ----> (Y/N) : ", input.cd.bcode, input.bk_name, input.bk_author, input.bk_cost);
			while (getchar() != '\n');
			ck = getchar();
		}
		input.br.borrow = OFF;
		newBook->data = input;
		newBook->link = list->link;
		list->link = newBook;
		list = list->link;
		fwrite(&input, sizeof(input), 1, fp);

		printf("�߰� ���� �Է��� ���Ͻʴϱ�? (Y/N): ");
		while (getchar() != '\n');
		go = getchar();
	}

	fclose(fp);
}

books* searchBook(books* list) {
	books* cur = list;
	char search[40];
	int s_cd;
	char ck;
	int num;

	menu(2);
	scanf("%d", &num);
	switch (num) {
	case 1:
		printf("\n\n�����ڵ�: ");
		scanf("%x", &s_cd);

		while (cur->link != NULL) {
			if (s_cd IS cur->link->data.cd.bcode) {
				if (cur->link->data.br.borrow == ON)
					printf("[ %08x %s %s %d ���� �� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				else
					printf("[ %08x %s %s %d ���� ���� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				while (getchar() != '\n');
				ck = getchar();
				if (ck == 'y') break;
			}
			cur = cur->link;
			if (cur->link == NULL) printf(">> �˻��� ������ ã�� �� �����ϴ�.\n");
		}
		system("pause");
		return cur;

	case 2:
		printf("\n\n������: ");
		scanf("%s", search);

		while (cur->link != NULL) {
			if (strcmp(search, cur->link->data.bk_name) IS 0) {
				if (cur->link->data.br.borrow == ON)
					printf("[ %08x %s %s %d ���� �� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				else
					printf("[ %08x %s %s %d ���� ���� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				while (getchar() != '\n');
				ck = getchar();
				if (ck == 'y') break;
			}
			cur = cur->link;
			if (cur->link == NULL) printf(">> �˻��� ������ ã�� �� �����ϴ�.\n");
		}
		system("pause");
		return cur;

	case 3:
		printf("\n\n���ڸ�: ");
		scanf("%s", search);

		while (cur->link != NULL) {
			if (strcmp(search, cur->link->data.bk_author) IS 0) {
				if (cur->link->data.br.borrow IS ON)
					printf("[ %08x %s %s %d ���� �� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				else
					printf("[ %08x %s %s %d ���� ���� ] -----> (Y/N): ", cur->link->data.cd.bcode, cur->link->data.bk_name, cur->link->data.bk_author, cur->link->data.bk_cost);
				while (getchar() != '\n');
				ck = getchar();
				if (ck IS 'y') break;
			}
			cur = cur->link;
			if (cur->link == NULL) printf(">> �˻��� ������ ã�� �� �����ϴ�.\n");
		}
		system("pause");
		return cur;

	default:
		printf("�߸��� �Է��Դϴ�.\n");
		return cur;
		break;

	}
}

void deleteBook(books* list) {
	books* list2 = searchBook(list);
	if (list2 IS NULL)
		return;

	books* deleted = list2->link;
	list2->link = deleted->link;
	free(deleted);
	printf("���� �Ϸ�\n");
	system("pause");
}

void printBook(books* list) {
	int num;
	menu(3);
	scanf("%d", &num);
	books* cur = list->link;
	switch (num) {
	case 1:
		printf("\n\n");
		while (1)
		{
			printf("[ %08x %s %s %d ] \n", cur->data.cd.bcode, cur->data.bk_name, cur->data.bk_author, cur->data.bk_cost);
			cur = cur->link;
			if (cur == NULL) break;
		}
		break;

	case 2:
		printf("\n\n");
		while (1)
		{
			if (cur->link->data.br.borrow == OFF)
				printf("[ %08x %s %s %d ] \n", cur->data.cd.bcode, cur->data.bk_name, cur->data.bk_author, cur->data.bk_cost);
			cur = cur->link;
			if (cur == NULL) break;
		}
		break;

	case 3:
		printf("\n\n");
		while (1)
		{
			if (cur->link->data.br.borrow == ON) {
				printf("[ %08x %s %s %d ] \n", cur->data.cd.bcode, cur->data.bk_name, cur->data.bk_author, cur->data.bk_cost);
				timeMgr(cur->link->data.br.dateOfBorrowing, 0);
				printf("\n");
			}
			cur = cur->link;
			if (cur == NULL) break;
		}
		break;
	}
	system("pause");
}

void borrowBook(books* list) {
	time_t tm;
	char name[40];
	books* a = searchBook(list);
	books* bor = a->link;
	if (bor IS NULL)
		return;

	tm = time(NULL);
	bor->data.br.dateOfBorrowing = tm;
	printf("������ �̸��� �Է��ϼ���: ");
	scanf("%s", name);
	strcpy(bor->data.br.borrower,name );
	bor->data.br.borrow = ON;

	printf("�������⳯¥ : ");
	timeMgr(tm, 0);
	printf("\n");
}

void returnBook(books* list) {
	time_t tm, term;
	char name[20];
	int fee;
	books* bor = list->link;
	tm = time(NULL);
	
	printf("�������� �̸��� �Է��ϼ���: ");
	scanf("%s", name);
	while (bor != NULL) {
		if (strcmp(name, bor->data.br.borrower) IS 0) {
			tm = time(NULL);
			bor->data.br.dateOfReturning = tm;
			strcpy(bor->data.br.borrower,"");
			bor->data.br.borrow = OFF;
			printf("���� ��ȯ ��¥: ");
			timeMgr(tm, 0);
			printf("\n");
			term = tm - bor->data.br.dateOfBorrowing;
			printf("���� ����: ");
			timeMgr(term, 1);
			printf("\n");
			fee = (int)(term / 10) * 100;
			printf("%s�� �������� %d���Դϴ�.\n", name, fee);
			break;
		}
		bor = bor->link;
	}
	if (bor == NULL) printf("�����ڸ� ã�� �� �����ϴ�.\n");
	system("pause");
}