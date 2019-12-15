#include <stdio.h>
#include <stdlib.h>
#include "model/list/list.h"
#include "model/destination/destination.h"

int main() {
	int option;

	List l = create();

	destroy(&l);

	return 0;
}
