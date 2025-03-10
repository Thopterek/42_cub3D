#include "../inc/cub.h"

/*
	checking if information was saved
	int cc = 0;
	while (info->map[cc] != NULL)
	{
		ft_printf("%s\n", info->map[cc]);
		cc++;
	}
	ft_printf("flag is set to = %d\n", info->player->orient);
*/
int	main(int ac, char **av)
{
	t_info	*info;

	info = NULL;
	before_alloc(ac, av);
	initialization(av, &info);
	bin_malloc(-1);
	return (EXIT_SUCCESS);
}
