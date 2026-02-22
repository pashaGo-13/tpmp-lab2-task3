#include <stdio.h>
#include <string.h>
#include "note2.h"

int main() {
	NOTE2 block[BLOCK_SIZE];
	char searchSurname[MAX_NAME_LEN];

	inputNotes(block);
	sortByFirstThreeNumberDigits(block);
	return 0;
}
