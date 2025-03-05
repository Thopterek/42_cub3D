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
*/
typedef enum e_errors
{
	PARSING = 1
}	t_errors;

/*
			Parsing
	checking & saving the map
*/
void	before_alloc(int ac, char **av);

/*
	Parsing error handling
	- not enough arguments
*/
void	error_ac(void);
void	error_format(char **av);

#endif