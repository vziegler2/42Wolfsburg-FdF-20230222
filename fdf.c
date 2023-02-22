/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:39:04 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/22 14:14:56 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		ft_print_error("Usage: ./fdf map.fdf");
	ft_input(argv[1]);
	data = malloc(sizeof(t_fdf));
	if (!data)
		ft_print_error("Malloc error.");
	ft_height(data, argv[1]);
	ft_fill(data, argv[1]);
	if (data->height > 500 || data->width > 500)
		ft_print_error("Map too big.");
	ft_settings(data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	data->img = mlx_new_image(data->mlx, 4096, 2160);
	data->addr = mlx_get_data_addr(data->img, &data->bp, &data->ll, &data->e);
	ft_dots(data, 0x00FFFFFF);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	mlx_mouse_hook(data->window, ft_escape, data);
	mlx_hook(data->window, 2, 53, ft_escape, data);
	mlx_hook(data->window, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
	return (0);
}

//Z. 35 -> Farbe