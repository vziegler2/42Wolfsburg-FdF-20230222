/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:12 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/15 18:15:54 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_fill2(t_fdf *data, char **arr, char *ln, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		ln = get_next_line(fd);
		arr = ft_split(ln, ' ');
		data->mtrx[i] = malloc(sizeof(int) * data->width);
		if (!data->mtrx[i])
			ft_print_error("Malloc error.");
		while (j < data->width)
		{
			data->mtrx[i][j] = ft_atoi(arr[j]);
			j++;
		}
		i++;
		free(ln);
		ft_free_arr(arr);
	}
}
