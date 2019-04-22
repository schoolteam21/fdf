/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:11:48 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:11:55 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_hello_norm	norma(t_hello_norm norm)
{
	norm.p = norm.p + norm.diry;
	norm.error = norm.error - norm.deltay;
	return (norm);
}

t_hello_norm	norma2(t_hello_norm norm)
{
	norm.p = norm.p + norm.diry;
	norm.error = norm.error - norm.deltax;
	return (norm);
}

void			put_y(t_hello_norm norm, int color, t_point start, t_point end)
{
	int		y;
	t_fdf	*fdf;

	fdf = fdf_instance();
	y = start.y <= end.y ? start.y - 1 : start.y + 1;
	if (start.y <= end.y)
		while (++y <= end.y)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, norm.p, y, color);
			norm.error = norm.error + norm.deltaerr;
			if (2 * norm.error >= norm.deltay)
				norm = norma(norm);
		}
	else
		while (--y >= end.y)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, norm.p, y, color);
			norm.error = norm.error + norm.deltaerr;
			if (2 * norm.error >= norm.deltay)
			{
				norm.p = norm.p + norm.diry;
				norm.error = norm.error - norm.deltay;
			}
		}
}

void			put_x(t_hello_norm norm, int color, t_point start, t_point end)
{
	int		x;
	t_fdf	*fdf;

	fdf = fdf_instance();
	x = start.x <= end.x ? start.x - 1 : start.x + 1;
	if (start.x <= end.x)
		while (++x <= end.x)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, norm.p, color);
			norm.error = norm.error + norm.deltaerr;
			if (2 * norm.error >= norm.deltax)
			{
				norm.p = norm.p + norm.diry;
				norm.error = norm.error - norm.deltax;
			}
		}
	else
		while (--x >= end.x)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x, norm.p, color);
			norm.error = norm.error + norm.deltaerr;
			if (2 * norm.error >= norm.deltax)
				norm = norma2(norm);
		}
}
