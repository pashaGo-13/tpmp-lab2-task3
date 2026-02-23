#ifndef NOTE2_H
#define NOTE2_H

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define BLOCK_SIZE 7

typedef struct {
	char Name[MAX_NAME_LEN];
	char TELE[MAX_PHONE_LEN];
	struct {
		int year;
		int month;
		int day;
	} DATE;
} NOTE2;

void inputNotes(NOTE2 block[]);
void sortByFirstThreeNumberDigits(NOTE2 block[]);
void printPerson(const NOTE2 *note);
int findAndPrintBySurname(const NOTE2 block[], const char *surname);

#endif
