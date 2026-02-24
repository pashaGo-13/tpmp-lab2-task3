// pashaGo
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "note2.h"

// Ввод данных
void inputNotes(NOTE2 block[]) {
	printf("Введите информацию о %d людях:\n", BLOCK_SIZE);
	
	for (int i = 0; i < BLOCK_SIZE; ++i) {
		printf("\nЗапись №%d\n", i + 1);
		
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
		if (isdigit((unsigned char)phone[i])) {
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

// Сортировка по первым трем цифрам номера
void sortByFirstThreeNumberDigits(NOTE2 block[]) {
	for (int i = 0; i < BLOCK_SIZE - 1; i++) {
		for (int j = 0; j < BLOCK_SIZE - i - 1; j++) {
			int firstDigits1 = getFirstThreeDigits(block[j].TELE);
			int firstDigits2 = getFirstThreeDigits(block[j + 1].TELE);
 			if (firstDigits1 > firstDigits2) {
				NOTE2 temp = block[j];
				block[j] = block[j + 1];
				block[j + 1] = temp;
			}
		}
	}
}

// Вывод информации о человеке
void printPerson(const NOTE2 *note) {
	printf("Фамилия и инициалы: %s\n", note->Name);
	printf("Номер телефона: %s\n", note->TELE);
	printf("Дата рождения: %04d-%02d-%02d\n", note->DATE.year, note->DATE.month, note->DATE.day);
}

// Поиск по фамилии и вывод
int findAndPrintBySurname(const NOTE2 block[], const char *surname) {
	int found = 0;
	for (int i = 0; i < BLOCK_SIZE; i++) {
		if (strncmp(block[i].Name, surname, strlen(surname)) == 0) {
			if (!found) {
				printf("\nНайдено:\n");
				found = 1;
			}
			printPerson(&block[i]);
		}
	}
	return found;
}
