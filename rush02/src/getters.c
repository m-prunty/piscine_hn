/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:43:37 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 22:59:59 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

t_obj	*ft_get_resource_nearest(t_pos pos)
{
	return (core_get_obj_customCondition_nearest(pos, is_resource));
}

t_obj	*ft_get_money_nearest(t_pos pos)
{
	return (core_get_obj_customCondition_nearest(pos, is_money));
}

t_obj	**ft_get_units_own(void)
{
	return (core_get_objs_customCondition(is_unit_own));
}

t_obj	**ft_get_units_opponent(void)
{
	return (core_get_objs_customCondition(is_unit_opponent));
}

t_obj	*ft_get_units_opponent_nearest(t_pos pos)
{
	return (core_get_obj_customCondition_nearest(pos, is_unit_opponent));
}
