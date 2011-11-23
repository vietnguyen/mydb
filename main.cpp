#include "queryUtil.h"

int main() {
	std::list<Table*> tables;
	while(run(&tables)){};
	stop();
	return EXIT_SUCCESS;
}
