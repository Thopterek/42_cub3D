#include "../../inc/cub.h"

static int	check_format(char **av)
{
	int	cc;

	cc = 0;
	if (ft_strnstr(av[1], ".cub", ft_strlen(av[1])) == NULL)
		return (1);
	while (av[1][cc + 1] != '\0')
		cc++;
	if (av[1][cc] != 'b' && av[1][cc - 1] != 'u'
		&& av[1][cc - 2] != 'c' && av[1][cc - 3] != '.')
		return (2);
	return (EXIT_SUCCESS);
}

void	before_alloc(int ac, char **av)
{
	char	*path;
	int		fd;

	if (ac > 2 || ac < 2)
		error_ac();
	if (check_format(av) != 0)
		error_format(av);
	path = bin_strjoin("./map/", av[1]);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_path(path, av);
	close(fd);
	bin_malloc(-1);
}
