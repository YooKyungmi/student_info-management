#ifndef B_ADMIN
#define B_ADMIN


void menu(int a);
void readFile(books* list, char text[20]);
void writeFile(char text[20], books* head);
void freeNode(books* head);
void addBook(books* list, char text[20]);
books* searchBook(books* list);
void deleteBook(books* list);
void printBook(books* list);
void borrowBook(books* list);
void returnBook(books* list);
#endif
