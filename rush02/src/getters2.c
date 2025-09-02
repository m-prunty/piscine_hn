/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:57:26 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 23:06:17 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

bool	is_core(const t_obj *obj)
{
	return (obj->type == OBJ_CORE && obj->state == STATE_ALIVE);
}

bool	is_core_own(const t_obj *obj)
{
	return (is_core(obj) && obj->s_core.team_id == game.my_team_id);
}

bool	is_core_opponent(const t_obj *obj)
{
	return (is_core(obj) && obj->s_core.team_id != game.my_team_id);
}

bool	is_resource(const t_obj *obj)
{
	return (obj->type == OBJ_RESOURCE && obj->state == STATE_ALIVE);
}

bool	is_money(const t_obj *obj)
{
	return (obj->type == OBJ_MONEY && obj->state == STATE_ALIVE);
}
