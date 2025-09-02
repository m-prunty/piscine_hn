/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:37:55 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 13:42:54 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bot.h"

t_obj	*make_miner(void)
{
	unsigned long	miner_cost;
	t_obj			*miner;

	miner_cost = core_get_unitConfig(UNIT_MINER)->cost;
	if (ft_get_core_own() && ft_get_core_own()->s_core.balance >= miner_cost)
		miner = core_action_createUnit(UNIT_MINER);
	return (miner);
}

t_obj	*make_warrior(void)
{
	unsigned long	warrior_cost;
	t_obj			*warrior;

	warrior_cost = core_get_unitConfig(UNIT_WARRIOR)->cost;
	if (ft_get_core_own() && ft_get_core_own()->s_core.balance >= warrior_cost)
		warrior = core_action_createUnit(UNIT_WARRIOR);
	return (warrior);
}

t_obj	*make_carrier(void)
{
	unsigned long	carrier_cost;
	t_obj			*carrier;

	carrier_cost = core_get_unitConfig(UNIT_CARRIER)->cost;
	if (ft_get_core_own() && ft_get_core_own()->s_core.balance >= carrier_cost)
		carrier = core_action_createUnit(UNIT_CARRIER);
	return (carrier);
}
