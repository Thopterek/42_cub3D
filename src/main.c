#include "../inc/cub.h"

int	main(int ac, char **av)
{
	before_alloc(ac, av);
	initialization(av);
	bin_malloc(-1);
	return (EXIT_SUCCESS);
}
