/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:04:23 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 22:04:24 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

t_delta	ft_delta(t_pos pos1, t_pos pos2)
{
	t_delta	delta;

	delta.x = pos1.x - pos2.x;
	delta.y = pos1.y - pos2.y;
	return (delta);
}

int	ft_dist(t_delta pos)
{
	return (abs(pos.x) + abs(pos.y));
}

t_pos	*ft_step(t_pos *pos, t_obj *unit, t_delta delta)
{
	(*pos).x = unit->pos.x;
	(*pos).y = unit->pos.y;
	if (abs((delta.x)) > abs(delta.y))
	{
		if (delta.x > 0)
			(*pos).x += 1;
		else if (delta.x < 0)
			(*pos).x -= 1;
	}
	else
	{
		if (delta.y > 0)
			(*pos).y += 1;
		else if (delta.y < 0)
			(*pos).y -= 1;
	}
	return (pos);
}
