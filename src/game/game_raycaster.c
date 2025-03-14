#include "../../inc/cub.h"

void	raycaster(void	*param)
{
	int		cc;
	t_info	*info;

	cc = 0;
	info = (t_info *)param;
	ft_memset(info->main_img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	while (cc < WIDTH)
	{
		cc++;
	}
}