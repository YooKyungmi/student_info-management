#include <stdio.h>
#include <time.h>
#include "timeMgr.h"


void timeMgr(time_t ttt, int flag) {
	struct tm* tt;
	if (flag == 0) {
		tt = localtime(&ttt);
		printf("%d��", tt->tm_year + 1900);
		printf("%d��", tt->tm_mon + 1);
		printf("%d��", tt->tm_mday);
	}
	else {
		tt = gmtime(&ttt);
		printf("%d��", tt->tm_mday - 1);
	}
	printf("%d��", tt->tm_hour);
	printf("%d��", tt->tm_min);
	printf("%d��\n", tt->tm_sec);
	if (flag) printf("����Ǿ����ϴ�.\n");
}