#ifndef structfile
#define structfile

#define ON 1
#define OFF 0
typedef struct code {
	union {
		struct {
			unsigned kubun : 2; // 0:����,1:�����,2:�����α�,3:���þƱ�
			unsigned type : 3; // 0:����,1:����,2:��ġ,3:����,4:����,5:����,6:ö��,7:ü��
			unsigned null : 3;
			unsigned number : 24;
		}cc;
		unsigned bcode;
	};
}code;

typedef struct borrow {
	time_t dateOfBorrowing; // ���� ��¥
	time_t dateOfReturning; // ���� �ݳ���¥. char bookBorrower[20];
	char borrower[20];
	int borrow; // ���� ���� ���� 0: ���Ⱑ��, 1:������
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