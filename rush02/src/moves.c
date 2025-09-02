/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:24:23 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 16:37:46 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "bot.h"

void	ft_home_run(t_obj *unit, t_pos next_pos,
	void (*fn_col)(t_obj *, t_obj *, t_pos *))
{
	t_delta	delta;

	delta = ft_delta(ft_get_core_own()->pos, unit->pos);
	ft_step(&next_pos, unit, delta);
	fn_col(unit, ft_get_core_own(), &next_pos);
	delta = ft_delta(ft_get_core_own()->pos, unit->pos);
	if (unit->s_unit.balance > 0 && ft_dist(delta) <= 1)
		core_action_transferMoney(unit, ft_get_core_own()->pos, 9999999);
	core_action_move(unit, next_pos);
}

void	ft_move_carrier(t_obj *unit)
{
	t_delta	delta;
	t_pos	next_pos;
	t_obj	*money;

	money = ft_get_money_nearest(unit->pos);
	if (money == NULL)
		money = ft_get_core_own();
	delta = ft_delta(money->pos, unit->pos);
	ft_step(&next_pos, unit, delta);
	if (unit->s_unit.unit_type == UNIT_CARRIER
		&& unit->s_unit.move_cooldown == 0)
	{
		if (unit->s_unit.balance <= 0)
		{
			ft_collision_carrier(unit, money, &next_pos);
			core_action_move(unit, next_pos);
		}
		else
			ft_home_run(unit, next_pos, ft_collision_carrier);
	}
}

void	ft_move_miner(t_obj *unit)
{
	t_delta	delta;
	t_pos	next_pos;
	t_obj	*resource;

	if (unit->s_unit.unit_type == UNIT_MINER && unit->s_unit.move_cooldown == 0 && unit->state == STATE_ALIVE)
	{
		resource = ft_get_resource_nearest(unit->pos);
		if (!resource)
			resource = ft_get_units_opponent_nearest(unit->pos);
		delta = ft_delta(resource->pos, unit->pos);
		ft_step(&next_pos, unit, delta);
		if (abs(delta.x) + abs(delta.y) > 1 && unit->s_unit.balance == 0)
		{
			ft_collision_miner(unit, resource, &next_pos);
			core_action_move(unit, next_pos);
		}
		else if (unit->s_unit.balance > 0)
			ft_home_run(unit, next_pos, ft_collision_miner);
		else
			core_action_attack(unit, next_pos);
	}
}

t_obj *get_warrior_target(t_obj *unit)
{
	t_obj *target;

	target = ft_get_units_opponent_nearest(unit->pos);
	if (target && (ft_dist(ft_delta(target->pos, unit->pos)) < 3))
		return (target);
	else
		return (ft_get_core_opponent());
}

void ft_move_warrior(t_obj *unit)
{
	t_delta delta;
	t_pos next_pos;
	t_obj *target;

	if (unit->s_unit.unit_type == UNIT_WARRIOR && unit->s_unit.move_cooldown == 0 && unit->state == STATE_ALIVE)
	{
		target = get_warrior_target(unit);
		delta = ft_delta(target->pos, unit->pos);
		ft_step(&next_pos, unit, delta);
		if (ft_dist(delta) > 1 && unit->s_unit.balance == 0)
		{
			ft_collision_warrior(unit, target, &next_pos);
			core_action_move(unit, next_pos);
		}
		else if (unit->s_unit.balance > 0)
			ft_home_run(unit, next_pos, ft_collision_warrior);
		else
			core_action_attack(unit, next_pos);
	}
}
