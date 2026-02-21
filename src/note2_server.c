#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "note2.h"

// Ввод данных
void inputNotes(NOTE2 block[]) {
	printf("Введите информацию о %d людях:\n", BLOCK_SIZE);
	
	for (int i = 0; i < BLOCK_SIZE; ++i) {
		printf("Запись №%d", i + 1);
		
		printf("Введите фамилию и инициалы: ");
		fgets(block[i].Name, MAX_NAME_LEN, stdin);
		size_t len = strlen(block[i].Name);
		if (len > 0 && block[i].Name[len - 1] == '\n') {
			block[i].Name[len - 1] = '\0';
		}
		
		printf("Введите номер телефона: ");
		fgets(block[i].TELE, MAX_PHONE_LEN, stdin);
		len = strlen(block[i].TELE);
		if (len > 0 && block[i].TELE[len - 1] == '\n') {
			block[i].TELE[len - 1] = '\0';
		}
		
		printf("Введите дату рождения (год месяц число): ");
		scanf("%d %d %d", &block[i].DATE.year, &block[i].DATE.month, &block[i].DATE.day);
		getchar();
	}
}

// Извлечение первых трех цифр номера
static int getFirstThreeDigits(const char *phone) {
	int digits = 0;
	int count = 0;
	for (int i = 0; phone[i] != '\0' && count < 3; i++) {
		if (isdigit(phone[i])) {
			digits = digits * 10 + (phone[i] - '0');
			count++;
		}
	}
	
	while (count < 3) {
		digits *= 10;
		count++;
	}
	return digits;
}
