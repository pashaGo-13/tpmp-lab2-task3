#indef NOTE2_H
#define NOTE2_H

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_BLOCK_SIZE 7

typedef struct {
	char Name[MAX_NAME_LEN];
	char TELE[MAX_PHONE_LEN];
	struct {
		int year;
		int month;
		int day;
	} Date;
} NOTE2;

#endif
