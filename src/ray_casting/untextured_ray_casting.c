#include "../../inc/cub.h"
#include <stdbool.h>

#define MAPWIDTH 24
#define MAPHEIGHT 24
#define TEXWIDTH 64
#define TEXHEIGHT 64
#define FLOOR 0x808080FF
#define CEILING 0x0000FFFF

int	worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	draw_pixels(int x, int y, int color, t_play *play)
{
	if (x >= 0 && x < SCREENWIDTH && y >= 0 && y < SCREENHEIGHT)
		mlx_put_pixel(play->img, x, y, color);
}

void draw_buffer(t_play *play, uint32_t buffer[SCREENHEIGHT][SCREENWIDTH])
{
    // Iterate over every pixel in the buffer
    for (int y = 0; y < SCREENHEIGHT; y++)
    {
        for (int x = 0; x < SCREENWIDTH; x++)
        {
            uint32_t color = buffer[y][x]; // Read color from buffer
            int pixel_index = (y * SCREENWIDTH + x) * 4; // 4 bytes per pixel (RGBA)
            play->img->pixels[pixel_index] = (color >> 16) & 0xFF;      // Red
            play->img->pixels[pixel_index + 1] = (color >> 8) & 0xFF;   // Green
            play->img->pixels[pixel_index + 2] = color & 0xFF;          // Blue
            play->img->pixels[pixel_index + 3] = 255;                   // Alpha (fully opaque)
        }
    }

    // Display the updated image
    mlx_image_to_window(play->mlx, play->img, 0, 0);
}

void	render(void *param)
{
	t_play	*play;

	play = (t_play *)param;
	ft_memset(play->img->pixels, 0,
		SCREENWIDTH * SCREENHEIGHT * sizeof(uint32_t));
	for (int y = 0; y < SCREENHEIGHT; y++)
	{
		for (int x = 0; x < SCREENWIDTH; x++)
		{
			if (y < SCREENHEIGHT / 2)
				play->buffer[y][x] = CEILING;
			else
				play->buffer[y][x] = FLOOR;
		}
	}
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
		int line_height = (int)(SCREENHEIGHT / perp_wall_dist);
		int	draw_start = -line_height / 2 + SCREENHEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREENHEIGHT / 2;
		if (draw_end >= SCREENHEIGHT)
			draw_end = SCREENHEIGHT - 1;
		/*
		int color;
		if (side == 0)
			color = 0x00FF00FF;
		else
			color = 0xFFFFFFFF;
		for (int y = draw_start; y < draw_end; y++)
			draw_pixels(x, y, color, play);*/
		// int tex_num = worldMap[map_x][map_y] - 1;
		// if (tex_num < 0 || tex_num >= 8) // Ensure tex_num is within valid range
		// 	tex_num = 0;
		int tex_num;
		if (side == 0)
		{
			if (ray_dir_x > 0)
				tex_num = WEST;
			else
				tex_num = EAST;
		}
		else
		{
			if (ray_dir_y > 0)
				tex_num = SOUTH;
			else
				tex_num = NORTH;
		}
		double wall_x;
		if (side == 0)
			wall_x = play->pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = play->pos_x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		int tex_x = (int)(wall_x * (double)TEXWIDTH);
		if (side == 0 && ray_dir_x > 0)
			tex_x = TEXWIDTH - tex_x - 1;
		if (side == 1 && ray_dir_y < 0)
			tex_x = TEXWIDTH - tex_x - 1;
		double step = 1.0 * TEXHEIGHT / line_height;
		double tex_pos = (draw_start - SCREENHEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			int tex_y = (int)tex_pos & (TEXHEIGHT - 1);
			tex_pos += step;
			uint32_t *pixel_data = (uint32_t*)play->texture[tex_num]->pixels;
			uint32_t color = pixel_data[tex_y * TEXWIDTH + tex_x];
			// uint32_t color = play->texture[tex_num]->pixels[tex_y * TEXWIDTH + tex_x];
			if (side == 1)
				color = (color >> 1) & 8355711;
			play->buffer[y][x] = color;
		}
	}
	draw_buffer(play, play->buffer);
	ft_memset(play->buffer, 0, sizeof(play->buffer));
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_play *play;

	play = (t_play *)param;
	double move_speed = 0.5;
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
	play->graphic = malloc(sizeof(t_graphic));
	play->graphic->north_path = ft_strdup("tex/north.png");
	play->graphic->east_path = ft_strdup("tex/east.png");
	play->graphic->west_path = ft_strdup("tex/west.png");
	play->graphic->south_path = ft_strdup("tex/south.png");
	play->texture[0] = mlx_load_png(play->graphic->north_path);
	play->texture[1] = mlx_load_png(play->graphic->west_path);
	play->texture[2] = mlx_load_png(play->graphic->east_path);
	play->texture[3] = mlx_load_png(play->graphic->south_path);
	for (int i = 0; i < 4; i++)
	{
		if (!play->texture[i])
		{
			fprintf(stderr, "Error: Failed to load texture %d\n", i);
			exit(EXIT_FAILURE);
		}
		printf("Texture %d: width = %d, height = %d\n", i, play->texture[i]->width, play->texture[i]->height);
	}
	// for (int x = 0; x < TEXWIDTH; x++)
	// {
	// 	for (int y = 0; y < TEXHEIGHT; y++)
	// 	{
	// 		int xorcolor = (x * 256 / TEXWIDTH) ^ (y * 256 / TEXHEIGHT);
	// 		int	ycolor = y * 256 / TEXHEIGHT;
	// 		int	xycolor = y * 128 / TEXHEIGHT + x * 128 / TEXWIDTH;
	// 		play->texture[0][TEXWIDTH * y + x] = 65536 * 254 * (x != y && x != TEXWIDTH - y);
	// 		play->texture[1][TEXWIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
	// 		play->texture[2][TEXWIDTH * y + x] = 256 * xycolor + 65536 * xycolor;
	// 		play->texture[3][TEXWIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
	// 		play->texture[4][TEXWIDTH * y + x] = 256 * xorcolor;
	// 		play->texture[5][TEXWIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16);
	// 		play->texture[6][TEXWIDTH * y + x] = 65536 * ycolor;
	// 		play->texture[7][TEXWIDTH * y + x] = 128 + 256 * 128 + 65536 * 128;
	// 	}
	// }
}

int	main(void)
{
	t_play		play;

	init_play(&play);
	mlx_loop_hook(play.mlx, render, &play);
	mlx_key_hook(play.mlx, key_hook, &play);
	mlx_loop(play.mlx);
	mlx_terminate(play.mlx);
	return (0);
}

