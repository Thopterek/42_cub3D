#include "../inc/cub.h"

/*
	checking if information was saved
	getting the mlx with the command:
	git submodule update --init --recursive
	int cc = 0;
	while (info.map[cc] != NULL)
	{
		ft_printf("%s\n", info.map[cc]);
		cc++;
	}
	ft_printf("flag is set to = %d\n", info.player->orient);
	ft_printf("east path is '%s'\n", info.graphic->east_path);
	ft_printf("blue for floor is '%d'\n", info.graphic->floor_blue);
*/
int	main(int ac, char **av)
{
	t_info	info;

	before_alloc(ac, av);
	initialization(av, &info);
	mlx_terminate(info.mlx);
	bin_malloc(-1);
	return (EXIT_SUCCESS);
}
