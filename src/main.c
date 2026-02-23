#include <stdio.h>
#include <string.h>
#include "note2.h"

int main() {
	NOTE2 block[BLOCK_SIZE];
	char searchSurname[MAX_NAME_LEN];

	inputNotes(block);
	sortByFirstThreeNumberDigits(block);
	
	printf("Введите фамилию для поиска: ");
	fgets(searchSurname, MAX_NAME_LEN, stdin);
	size_t len = strlen(searchSurname);
	if (len > 0 && searchSurname[len - 1] == '\n') {
		searchSurname[len - 1] = '\0';
	}
	
	if (!findAndPrintBySurname(block, searchSurname)) {
		printf("\nЧеловек с фамилией %s не найден\n", searchSurname);
	}
	return 0;
}

