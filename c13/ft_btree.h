/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <maprunty@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:11:47 by maprunty          #+#    #+#             */
/*   Updated: 2025/09/02 18:11:54 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"
#include "includes/ft_list.h"
#include <stdlib.h>

typedef struct s_btree
{
	void			*data;
	struct s_btree	*right;
	struct s_btree	*left;

}	t_btree;

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);;
void	btree_level_list(t_btree *root, int level, t_list **lst);

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem));
void	btree_pprint_help(void *item, int current_level, int is_first_elem,
			int n_levels);
void	btree_level_list_null(t_btree *root, int level, t_list **lst);
void	btree_pprint(t_btree *root);
void	applyf(void *item, int level, int is_first);
