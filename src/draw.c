/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:09:45 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:09:51 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	liney(t_point start, t_point end, t_fdf *fdf, int color)
{
	t_hello_norm norm;

	fdf = NULL;
	norm.deltax = abs(end.x - start.x);
	norm.deltay = abs(end.y - start.y);
	norm.error = 0;
	norm.deltaerr = norm.deltax;
	norm.p = start.x;
	norm.diry = end.x - start.x;
	if (norm.diry > 0)
		norm.diry = 1;
	if (norm.diry < 0)
		norm.diry = -1;
	put_y(norm, color, start, end);
}

static void	linex(t_point start, t_point end, t_fdf *fdf, int color)
{
	t_hello_norm norm;

	fdf = NULL;
	norm.deltax = abs(end.x - start.x);
	norm.deltay = abs(end.y - start.y);
	norm.error = 0;
	norm.deltaerr = norm.deltay;
	norm.p = start.y;
	norm.diry = end.y - start.y;
	if (norm.diry > 0)
		norm.diry = 1;
	if (norm.diry < 0)
		norm.diry = -1;
	put_x(norm, color, start, end);
}

static void	line(t_point start, t_point end, t_fdf *fdf, int color)
{
	int y;
	int x;

	x = abs(end.x - start.x);
	y = abs(end.y - start.y);
	if (x - y >= 0)
		linex(start, end, fdf, color);
	else
		liney(start, end, fdf, color);
}

void		draw_map(t_vector *vec)
{
	while (vec)
	{
		line(*(vec->start), *(vec->end), fdf_instance(), vec->color);
		vec = vec->next;
	}
}
