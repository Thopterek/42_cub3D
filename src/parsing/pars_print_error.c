#include "../../inc/cub.h"

void	error_ac(void)
{
	ft_printf("Error: wrong number of arguments\n");
	ft_printf("usage: ./cub3D [file in map].cub\n");
	exit(PARSING);
}

void	error_format(char **av)
{
	ft_printf("Error: wrong format of the map\n");
	ft_printf(".cub in '%s' not found\n", av[1]);
	exit(PARSING);
}

void	error_path(char *path, char **av)
{
	ft_printf("Error: can't access the map file\n");
	ft_printf("path: '%s' failed\n", path);
	ft_printf("check: '%s' look for any typos\n", av[1]);
	bin_malloc(-1);
	exit(PARSING);
}
