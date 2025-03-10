#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/lib_pri_get/ft_printf.h"
# include "../lib/bin_malloc/bin_malloc.h"
# include "pars.h"
# include "init.h"

/*
	enums for error handling
	setting the exit codes
*/
typedef enum e_errors
{
	PARSING = 1,
	INITIAL = 2
}	t_errors;

#endif