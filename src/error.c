/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:10:02 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:10:07 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty_error(void)
{
	write(1, "Usage: ./fdf [map file]\n", 24);
	exit(EXIT_FAILURE);
}

void	bad_file_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	bad_map(void)
{
	write(1, "INVALID MAP\n", 12);
	exit(EXIT_FAILURE);
}
