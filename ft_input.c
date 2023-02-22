/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:42:03 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/13 21:31:45 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_input(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'f' || argv[i - 2] != 'd' || argv[i - 3] != 'f')
		ft_print_error("Wrong input file.");
}
