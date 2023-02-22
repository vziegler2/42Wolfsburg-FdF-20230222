/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:40:18 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/22 15:30:32 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../MiniLibX/mlx.h"

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bp;
	int		ll;
	int		e;
	int		x;
	int		y;
	int		z;
	int		**mtrx;
	int		dy;
	int		dx;
	double	zr;
	double	zn;
	double	xr;
	double	yr;
	double	xn;
	double	yn;
	int		col;
	double	shift;
	double	depth;
	char	*map;
	double	zoom;
}	t_fdf;

void	ft_print_error(char *s);
void	ft_height(t_fdf *data, char *map);
void	ft_free_arr(char **arr);
int		ft_close(t_fdf *data);
int		*ft_put(t_fdf *data, int x, int y, int color);
void	ft_dots(t_fdf *data, int col);
void	ft_fill(t_fdf *data, char *map);
int		ft_escape(int key);
void	ft_dots2(t_fdf *data, int x, int y);
void	ft_draw(t_fdf *data, double xw, double yw);
void	ft_settings(t_fdf *data);
void	ft_settings2(t_fdf *data, double zoom, double depth);
void	ft_input(char *argv);
void	ft_fill2(t_fdf *data, char **arr, char *ln, int fd);

#endif