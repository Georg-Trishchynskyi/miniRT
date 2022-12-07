#ifndef MINIRT_H
#define MINIRT_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# include "vector.h"
# include "figures.h"
# include "libft.h"
# include "scene.h"

//ERRORS
int		print_error(char *str);
void	fatal_error(char *str);
void	exit_error(int code);

#endif