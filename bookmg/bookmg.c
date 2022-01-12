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
	printf(" \n[ 도서관리 프로그램 ]\n\n");
	readFile(head, text);
	Sleep(2000);
	//1. 도서입력\n 2. 도서 검색\n 3. 도서 대출&반납\n 4. 도서 삭제\n 5. 도서 리스트\n 6. 종료
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
			printf("1. 대출   2. 반납\n >>");
			scanf("%d", &num);
			if (num == 1) borrowBook(head);
			else if (num == 2) returnBook(head);
			else printf("잘못된 입력입니다.\n");
			break;
		case 4:
			deleteBook(head);
			break;
		case 5:
			printBook(head);
			break;
		case 6:
			printf("이용해주셔서 감사합니다.\n");
			writeFile(text, head);
			freeNode(head);
			free(head);
			return 0;
		default:
			printf("잘못된 입력입니다.\n");
		}
	}
}