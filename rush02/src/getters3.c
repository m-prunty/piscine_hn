/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:58:37 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 23:06:25 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

bool	is_unit(const t_obj *obj)
{
	return (obj->type == OBJ_UNIT && obj->state == STATE_ALIVE);
}

bool	is_unit_own(const t_obj *obj)
{
	return (is_unit(obj) && obj->s_unit.team_id == game.my_team_id);
}

bool	is_unit_opponent(const t_obj *obj)
{
	return (is_unit(obj) && obj->s_unit.team_id != game.my_team_id);
}

t_obj	*ft_get_core_own(void)
{
	t_pos	pos;

	pos = (t_pos){0, 0};
	return (core_get_obj_customCondition_nearest(pos, is_core_own));
}

t_obj	*ft_get_core_opponent(void)
{
	t_pos	pos;

	pos = (t_pos){0, 0};
	return (core_get_obj_customCondition_nearest(pos, is_core_opponent));
}
