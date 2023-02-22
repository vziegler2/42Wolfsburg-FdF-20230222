/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:07:42 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/15 20:56:11 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_settings(t_fdf *data)
{
	double	size;

	size = data->width * data->height;
	if (size <= 625)
		ft_settings2(data, 50, 1.5);
	else if (size <= 2500)
		ft_settings2(data, 30, 1.5);
	else if (size <= 10000)
		ft_settings2(data, 15, 0.5);
	else if (size <= 40000)
		ft_settings2(data, 8, 0.3);
	else
		ft_settings2(data, 3, 0.2);
}
