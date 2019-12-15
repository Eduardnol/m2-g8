#include "functions.h"
#include "../../model/destination/destination.h"
#include "../menu/menu.h"
#include <stdlib.h>

void readWholeFile(FILE * f, List * l) {
	int nDestinations, i;

	fscanf(f, "%d", &nDestinations);

	for (i = 0; i < nDestinations; i++) {
		Destination d = readFromFile(f);
		insert(l, d);
	}
}
