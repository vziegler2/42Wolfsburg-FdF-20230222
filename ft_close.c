/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:00:11 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/13 21:23:50 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

int	ft_close(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->mtrx[i++]);
	free(data->mtrx);
	free(data);
	exit(1);
}
