/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:04:10 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 22:04:13 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

void	ft_col_move(t_obj *unit, t_obj *dest, t_delta delta_p, t_pos *next_pos)
{
	unsigned long	g_size;

	g_size = game.config.gridSize;
	if (abs(delta_p.x) != 0)
	{
		next_pos->x = unit->pos.x;
		if (dest->pos.y - unit->pos.y >= 0 && unit->pos.y < g_size - 1)
			next_pos->y = unit->pos.y + 1;
		else
			next_pos->y = unit->pos.y - 1;
	}
	else if (abs(delta_p.y) != 0)
	{
		next_pos->y = unit->pos.y;
		if (dest->pos.x - unit->pos.x >= 0 && unit->pos.x < g_size - 1)
			next_pos->x = unit->pos.x + 1;
		else
			next_pos->x = unit->pos.x - 1;
	}
}

void	ft_collision_carrier(t_obj *unit, t_obj *dest, t_pos *next_pos)
{
	t_obj	*next_obg;
	t_delta	delta_p;

	delta_p = ft_delta(*next_pos, unit->pos);
	next_obg = core_get_obj_from_pos(*next_pos);
	if (next_obg != NULL && next_obg->type != OBJ_MONEY)
		ft_col_move(unit, dest, delta_p, next_pos);
}

void	ft_collision_miner(t_obj *unit, t_obj *dest, t_pos *next_pos)
{
	t_obj	*next_obg;
	t_delta	delta_p;

	delta_p = ft_delta(*next_pos, unit->pos);
	next_obg = core_get_obj_from_pos(*next_pos);
	if (next_obg != NULL && (next_obg->type != OBJ_RESOURCE
			|| next_obg->type == OBJ_MONEY || (next_obg->type == OBJ_UNIT
				&& next_obg->id == game.my_team_id)))
		ft_col_move(unit, dest, delta_p, next_pos);
}

void	ft_collision_warrior(t_obj *unit, t_obj *dest, t_pos *next_pos)
{
	t_obj	*next_obg;
	t_delta	delta_p;

	delta_p = ft_delta(*next_pos, unit->pos);
	next_obg = core_get_obj_from_pos(*next_pos);
	if (next_obg != NULL && (next_obg->type != OBJ_CORE
			|| next_obg->type == OBJ_MONEY || (next_obg->type == OBJ_UNIT
				&& next_obg->id == game.my_team_id)))
		ft_col_move(unit, dest, delta_p, next_pos);
}
