/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:10:18 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:10:25 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_event(int keycode)
{
	if (keycode == RSEVEN_KEY)
		rotation(RSEVEN_KEY);
	else if (keycode == REIGHT_KEY)
		rotation(REIGHT_KEY);
	else if (keycode == RFIVE_KEY)
		rotation(RFIVE_KEY);
	else if (keycode == RFOUR_KEY)
		rotation(RFOUR_KEY);
	else if (keycode == RONE_KEY)
		rotation(RONE_KEY);
	else if (keycode == RTWO_KEY)
		rotation(RTWO_KEY);
}

int		key_press(int keycode, void *param)
{
	param = NULL;
	rotation_event(keycode);
	if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (keycode == MINUS_KEY)
		multy(MINUS);
	else if (keycode == PLUS_KEY)
		multy(PlUS);
	else if (keycode == RIGHT_KEY || keycode == LEFT_KEY ||
			keycode == TOP_KEY || keycode == BOT_KEY)
		new_shift(keycode);
	return (0);
}
