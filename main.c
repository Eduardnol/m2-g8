#include <stdio.h>
#include <stdlib.h>
#include "model/list/list.h"
#include "model/destination/destination.h"

#define PATH "data/mainDatabase.nymal"

int main() {
	int option;

	List l = create();

	destroy(&l);

	return 0;
}
