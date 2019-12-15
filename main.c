#include <stdio.h>
#include <stdlib.h>
#include "model/functions/functions.h"
#include "model/list/list.h"
#include "model/destination/destination.h"

#define PATH "data/mainDatabase.nymal"

int main() {
	int option;

	FILE* f = fopen(PATH, "r");

	if (f = NULL) {
		return -1;
	}

	List l = create();

	readWholeFile(f, &l);

	destroy(&l);

	return 0;
}
