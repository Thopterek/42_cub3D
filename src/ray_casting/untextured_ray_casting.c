#include "../../inc/cub.h"
#include <stdbool.h>

#define MAPWIDTH 24
#define MAPHEIGHT 24
#define SCREENWIDTH 640
#define SCREENHEIGHT 480

int	worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	draw_pixels(int x, int y, int color, t_play *play)
{
	if (x >= 0 && x < SCREENWIDTH && y >= 0 && y < SCREENHEIGHT)
		mlx_put_pixel(play->img, x, y, color);
}

void	render(void *param)
{
	t_play	*play;

	play = (t_play *)param;
	ft_memset(play->img->pixels, 0,
		SCREENWIDTH * SCREENHEIGHT * sizeof(uint32_t));
	for (int x = 0; x < SCREENWIDTH; x++)
	{
		double camera_x = 2 * x / (double) SCREENWIDTH - 1;
		double ray_dir_x = play->dir_x + play->plane_x * camera_x;
		double ray_dir_y = play->dir_y + play->plane_y * camera_x;
		int map_x = (int)play->pos_x;
		int	map_y = (int)play->pos_y;
		double side_dist_x;
		double side_dist_y;
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;
		int step_x;
		int step_y;
		int hit = 0;
		int side;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (play->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - play->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (play->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - play->pos_y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (worldMap[map_y][map_x] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;
		int line_height = (int) SCREENHEIGHT / perp_wall_dist;
		int	draw_start = -line_height / 2 + SCREENHEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREENHEIGHT / 2;
		if (draw_end >= SCREENHEIGHT)
			draw_end = SCREENHEIGHT - 1;
		int color;
		if (side == 0)
			color = 0x00FF00FF;
		else
			color = 0xFFFFFFFF;
		for (int y = draw_start; y < draw_end; y++)
			draw_pixels(x, y, color, play);
	}	
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_play *play;

	play = (t_play *)param;
	double move_speed = 0.1;
	double rot_speed = 0.05;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		//if (worldMap[(int)(play->pos_x + play->dir_x * move_speed)][(int)play->pos_y] == false)
			play->pos_x += play->dir_x * move_speed;
		//if (worldMap[(int)play->pos_x][(int)(play->pos_y + play->dir_y * move_speed)] == false)
			play->pos_y += play->dir_y * move_speed;
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		//if (worldMap[(int)(play->pos_x - play->dir_x * move_speed)][(int)play->pos_y] == false)
			play->pos_x -= play->dir_x * move_speed;
		//if (worldMap[(int)play->pos_x][(int)(play->pos_y - play->dir_y * move_speed)] == false)
			play->pos_y -= play->dir_y * move_speed;
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		double old_dir_x = play->dir_x;
		play->dir_x = play->dir_x * cos(-rot_speed) - play->dir_y * sin(-rot_speed);
		play->dir_y = old_dir_x * sin(-rot_speed) + play->dir_y * cos(-rot_speed);
		double old_plane_x = play->plane_x;
		play->plane_x = play->plane_x * cos(-rot_speed) - play->plane_y * sin(-rot_speed);
		play->plane_y = old_plane_x * sin(-rot_speed) + play->plane_y * cos(-rot_speed);
	}
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		double old_dir_x = play->dir_x;
		play->dir_x = play->dir_x * cos(rot_speed) - play->dir_y * sin(rot_speed);
		play->dir_y = old_dir_x * sin(rot_speed) + play->dir_y * cos(rot_speed);
		double old_plane_x = play->plane_x;
		play->plane_x = play->plane_x * cos(rot_speed) - play->plane_y * sin(rot_speed);
		play->plane_y = old_plane_x * sin(rot_speed) + play->plane_y * cos(rot_speed);
	}
}
void	init_play(t_play *play)
{
	play->pos_x = 22;
	play->pos_y = 12;
	play->dir_x = -1;
	play->dir_y = 0;
	play->plane_x = 0;
	play->plane_y = 0.66;
	play->time = 0;
	play->oldtime = 0;
	play->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "RAYCASTER", false);
	play->img = mlx_new_image(play->mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx_image_to_window(play->mlx, play->img, 0, 0);
}

int	main(void)
{
	t_play	play;

	init_play(&play);
	mlx_loop_hook(play.mlx, render, &play);
	mlx_key_hook(play.mlx, key_hook, &play);
	mlx_loop(play.mlx);
	mlx_terminate(play.mlx);
	return (0);
}
