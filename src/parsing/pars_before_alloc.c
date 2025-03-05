#include "../../inc/cub.h"

void	before_alloc(int ac, char **av)
{
	if (ac > 2 || ac < 2)
		error_ac();
	(void)av;
}
