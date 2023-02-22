/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:59:03 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/15 20:19:40 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_dots(t_fdf *data, int col)
{
	float	x;
	float	y;

	y = 0;
	data->dy = 0;
	data->col = col;
	while (y < data->height)
	{
		x = 0;
		data->dx = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_dots2(data, x + 1, y);
			if (y < data->height - 1)
				ft_dots2(data, x, y + 1);
			data->dx++;
			x++;
		}
		data->dy++;
		y++;
	}
}

//Z. 22, 25 -> dx/dy werden später für depth-Berechnung gebraucht
//Z. 30, 32 -> Verhindert, dass es über die Schlusslinie hinausgeht
// Die Funktion geht alle Mapwerte von links nach rechts durch