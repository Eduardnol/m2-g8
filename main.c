#include "model/list/list.h"
#include "model/destination/destination.h"

int main() {
	List l = create();

	destroy(&l);

	return 0;
}
