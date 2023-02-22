/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:59:14 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/22 13:48:11 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_draw(t_fdf *data, double xw, double yw)
{
	while ((((int)(data->xn - data->xr)) || ((int)(data->yn - data->yr))) \
			&& ((data->xr >= 0 && data->xr <= 1920)
			&& (data->yr >= 0 && data->yr <= 1080)))
	{
		ft_put(data, data->xr, data->yr, data->col);
		data->xr += xw;
		data->yr += yw;
	}
}

//Z. 23 -> Fensterbreite
//Z. 24 -> Fensterhöhe
//Z. 26 -> Parameter 2 und 3 sind ints
//      -> doubles werden abgerundet -> Pixel sind eindeutig adressiert
//Z. 32, 33 -> Erhöhung bis xr = xn und yr = yn bzw. Fensterrand erreicht