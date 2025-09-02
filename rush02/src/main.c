/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:11:48 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 23:02:02 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

void		ft_on_tick(unsigned long tick);

int	main(int argc, char **argv)
{
	return (core_startGame("pvijayku", argc, argv, ft_on_tick, false));
}

t_unit_c	*count_units(t_unit_c *unit_count, t_obj **units)
{
	int	i;

	i = -1;
	while (++i < 3)
		unit_count->count[i] = 0;
	i = 0;
	while (units && units[i])
	{
		if (units[i]->s_unit.unit_type == UNIT_CARRIER)
			unit_count->count[UNIT_CARRIER] += 1;
		else if (units[i]->s_unit.unit_type == UNIT_MINER)
			unit_count->count[UNIT_MINER] += 1;
		else
			unit_count->count[UNIT_WARRIOR] += 1;
		i++;
	}
	return (unit_count);
}

void	ft_on_tick(unsigned long tick)
{
	int			i;
	t_obj		*obj;
	t_unit_c	unit_count[1];
	t_obj		**units;

	i = -1;
	(void)tick;
	units = ft_get_units_own();
	count_units(unit_count, units);
	if (unit_count->count[UNIT_CARRIER] < 1)
		make_carrier();
	else if (unit_count->count[UNIT_MINER] < 2)
		make_miner();
	else
		make_warrior();
	while (units && units[++i])
	{
		obj = units[i];
		if (obj->state != STATE_ALIVE)
			continue ;
		ft_move_carrier(obj);
		ft_move_miner(obj);
		ft_move_warrior(obj);
	}
	free(units);
}
