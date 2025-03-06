#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/lib_pri_get/ft_printf.h"
# include "../lib/bin_malloc/bin_malloc.h"

/*
	enums for error handling
	setting the exit codes
	and flags for checking
*/
typedef enum e_errors
{
	PNG = -1,
	MAP = 0,
	PARSING = 1
}	t_errors;

/*
			Parsing
	checking & saving the map
	- before making allocation
	- helper function to get fd
*/
void	before_alloc(int ac, char **av);
int		open_again(char *path, int flag, char *actual);

/*
	Parsing error handling
	- not enough arguments
	- wrong map format
	- access denied for map
	- missing indetifier
	- access denied for png
*/
void	error_ac(void);
void	error_format(char **av);
void	error_path(char *path);
void	error_element(char *line, char *element);
void	error_png(char *line, char *actual);

#endif