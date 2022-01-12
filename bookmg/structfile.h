#ifndef structfile
#define structfile

#define ON 1
#define OFF 0
typedef struct code {
	union {
		struct {
			unsigned kubun : 2; // 0:동양,1:영어권,2:스페인권,3:러시아권
			unsigned type : 3; // 0:문학,1:경제,2:정치,3:정보,4:군사,5:교육,6:철학,7:체육
			unsigned null : 3;
			unsigned number : 24;
		}cc;
		unsigned bcode;
	};
}code;

typedef struct borrow {
	time_t dateOfBorrowing; // 대출 날짜
	time_t dateOfReturning; // 도서 반납날짜. char bookBorrower[20];
	char borrower[20];
	int borrow; // 도서 대출 여부 0: 대출가능, 1:대출중
} brPart;

typedef struct element {
	code cd;
	char bk_name[40];
	char bk_author[20];
	int bk_cost;
	brPart br;
}element;

typedef struct books {
	element data;
	struct books* link;
} books;

#endif