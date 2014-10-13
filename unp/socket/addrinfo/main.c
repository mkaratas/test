#include <stdio.h>
#include "fm_rcs.h"

int main(int argc, char **argv)
{
	fm_rcs *server = get_recs_instance();
	server->setup();

	return 0;
}
