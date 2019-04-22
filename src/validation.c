/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:13:36 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:42 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valid_map(const int fd)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i])
		{
			if ((line[i] == ' ' || (line[i] >= '0' ||
							line[i] <= 9) || line[i] == '-'))
				i++;
			else
				bad_map();
		}
		ft_strdel(&line);
	}
	return (1);
}
