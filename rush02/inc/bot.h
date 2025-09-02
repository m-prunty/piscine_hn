/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:02:35 by abalcu            #+#    #+#             */
/*   Updated: 2025/08/17 22:03:08 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_H
# define BOT_H

# include "core_lib.h"
# include <limits.h>
# include <math.h>

typedef struct s_delta
{
	int	x;
	int	y;
}		t_delta;

typedef struct s_unit_c
{
	int	count[3];
}		t_unit_c;

t_obj	*ft_get_core_own(void);
t_obj	*ft_get_core_opponent(void);
t_obj	*ft_get_resource_nearest(t_pos pos);
t_obj	*ft_get_money_nearest(t_pos pos);
t_obj	*ft_get_units_opponent_nearest(t_pos pos);
t_obj	**ft_get_units_own(void);
t_obj	**ft_get_units_opponent(void);
t_obj	*make_miner(void);
t_obj	*make_warrior(void);
t_obj	*make_carrier(void);
t_pos	*ft_step(t_pos *pos, t_obj *unit, t_delta delta);
t_delta	ft_delta(t_pos pos1, t_pos pos2);
int		ft_dist(t_delta pos);
void	ft_move(t_obj *unit, t_pos target_pos);
void	ft_move_carrier(t_obj *unit);
void	ft_move_miner(t_obj *unit);
void	ft_move_warrior(t_obj *unit);
void	ft_col_move(t_obj *unit, t_obj *dest, t_delta delta_p, t_pos *next_pos);
void	ft_collision_carrier(t_obj *unit, t_obj *dest, t_pos *next_pos);
void	ft_collision_miner(t_obj *unit, t_obj *dest, t_pos *next_pos);
void	ft_collision_warrior(t_obj *unit, t_obj *dest, t_pos *next_pos);
int		ft_dist(t_delta pos);
bool	is_core(const t_obj *obj);
bool	is_core_own(const t_obj *obj);
bool	is_core_opponent(const t_obj *obj);
bool	is_resource(const t_obj *obj);
bool	is_money(const t_obj *obj);
bool	is_unit(const t_obj *obj);
bool	is_unit_own(const t_obj *obj);
bool	is_unit_opponent(const t_obj *obj);

#endif /* BOT_H */
