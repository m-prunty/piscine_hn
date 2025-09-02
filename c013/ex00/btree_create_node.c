#include "../ft.h"
#include "../ft_btree.h"
#include "../ft_list.h"
#include <stdlib.h>

t_btree *btree_create_node(void *item)
{
	t_btree	*bt;

	bt = (t_btree *)malloc(sizeof(t_btree));
	if (!bt || !item)
		return (NULL);
	bt->data = item;
	bt->left = NULL;
	bt->right = NULL;
	return (bt);
}

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		applyf(root->data);
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
	}
}
void btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		btree_apply_infix(root->left, applyf);
		applyf(root->data);
		btree_apply_infix(root->right, applyf);
	}
}

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		btree_apply_suffix(root->left, applyf);
		btree_apply_suffix(root->right, applyf);
		applyf(root->data);
	}

}


void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!root || !*root || !item)
	{
		if (item && root)
			(*root) = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->data) < 0)
	{
		if((*root)->left)
			btree_insert_data(&(*root)->left, item, cmpf);
		else 
			(*root)->left = btree_create_node(item);
	}
	else
	{
		if((*root)->right)
			btree_insert_data(&(*root)->right, item, cmpf);
		else 
			(*root)->right = btree_create_node(item);
	}


}
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	int cmp;

	cmp = cmpf(data_ref, (root)->data);
	if ( !root || cmp == 0)
		return (root);
	else if (cmp > 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	else if (cmp < 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	return (NULL);
}

int btree_level_count(t_btree *root)
{
	int		li;
	int		ri;

	if (!root)
		return (0);
	li = btree_level_count(root->left);
	ri = btree_level_count(root->right);
	if (ri > li)
		return (++ri);
	return (++li);
};

void	btree_level_list(t_btree *root, int level, t_list **lst)
{
	if (!root)
		return ;
	ft_list_push_back(&(lst[level]), root);
	btree_level_list(root->left, level + 1, lst);
	btree_level_list(root->right, level + 1, lst);
}



void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	**lst;
	t_list	*cur;
	int		levels;
	int		i;
	int		is_first;


	levels = btree_level_count(root);
	lst = (t_list **)malloc(sizeof(t_list *) * (levels + 1));
	if (!lst)
		return ;
	i = -1;
	while (++i < levels)
		lst[i] = NULL;
	btree_level_list(root, 0, lst);
	i = -1;
	while (lst[++i])
	{	cur = lst[i];
		is_first = 1;
		while (cur)
		{
			applyf(((t_btree *)cur->data)->data, i,is_first );
			cur = cur->next;
			is_first = 0;
		}
	}
}

void btree_pprint_help(void *item, int current_level, int is_first_elem, int n_levels)
{
	if (is_first_elem)
	{
		ft_putstr("\nLevel "); 
		ft_putnbr(current_level);
		ft_putstr(": ");
		while(n_levels-- )
			ft_putstr("    ");
		if (current_level % 2)
			ft_putstr("  ");

	}
	if (item)
		ft_putstr((char *)((t_btree *)item)->data);
	ft_putstr(",    "); 
	
}

void	btree_level_list_null(t_btree *root, int level, t_list **lst)
{
	ft_list_push_back(&(lst[level]), root);
	if (!root)
		return ;
	btree_level_list_null(root->left, level + 1, lst);
	btree_level_list_null(root->right, level + 1, lst);
}
void btree_pprint(t_btree *root)
{
	t_list	**lst;
	t_list	*cur;
	int		levels;
	int		i;
	int		is_first;


	levels = btree_level_count(root) + 1;
	lst = (t_list **)malloc(sizeof(t_list *) * (levels));
	if (!lst)
		return ;
	i = -1;
	while (++i < levels)
		lst[i] = NULL;
	btree_level_list(root, 0, lst);
	i = -1;
	while (lst[++i] && --levels)
	{	cur = lst[i];
		is_first = 1;
		while (cur)
		{
			btree_pprint_help(((t_btree *)cur->data), i,is_first , levels);
			cur = cur->next;
			is_first = 0;
		}
	}
	
}

void applyf(void *item, int level, int is_first)
{
	if (is_first)
	{
		ft_putstr("\nLevel "); 
		ft_putnbr(level);
		ft_putstr(": "); 
	}
	ft_putstr((char *)item);
	ft_putstr(","); 
/*
	ft_putstr("Level "); 
	ft_putnbr(level);
	ft_putstr(": "); 
	ft_putnum(is_first); 
	ft_putstr(": "); 
	ft_putstr((char *)item);
	ft_putstr("\n"); 
*/
	//*(char *)item += level;
}

int main()
{
	t_btree *node1 = btree_create_node("1");
	t_btree *node2 = btree_create_node("2");
	t_btree	*node3 = btree_create_node("3");
	t_btree *node4 = btree_create_node("4");
	t_btree *node5 = btree_create_node("5");
	t_btree *node6 = btree_create_node("6");
	t_btree *node7 = btree_create_node("7");
	t_btree *node8 = btree_create_node("8");

	t_btree	*root = btree_create_node("1");
	root->left = btree_create_node("2");
	root->right = btree_create_node("3");
	root->left->left = btree_create_node("4");
	root->left->right = btree_create_node("5");
	root->right->right = btree_create_node("6");
	/*
	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node4->left = node8;
	node4->right = NULL;
*/
	btree_apply_prefix(root, ft_putstr);
	ft_putstr("\n");
	btree_apply_infix(root, ft_putstr);
	ft_putstr("\n");
	btree_apply_suffix(root, ft_putstr);
	/*
		char i;

		i = 47;
		while (++i < '9')
		{

			btree_insert_data(&node5, (char *)&i, ft_strcmp);
		}
*/
	btree_insert_data(&node5, "1", ft_strcmp);
	btree_insert_data(&node5, "4", ft_strcmp);
	btree_insert_data(&node5, "1", ft_strcmp);
	btree_insert_data(&node5, "1", ft_strcmp);
	btree_insert_data(&node5, "6", ft_strcmp);
	btree_insert_data(&node5, "4", ft_strcmp);
	btree_insert_data(&node5, "4", ft_strcmp);
	btree_insert_data(&node5, "9", ft_strcmp);
	btree_insert_data(&node5, "4", ft_strcmp);
	btree_insert_data(&node5, "9", ft_strcmp);
	btree_insert_data(&node5, "7", ft_strcmp);
	ft_putstr("\n");
	btree_apply_infix(node5, ft_putstr);

	ft_putstr("\n");
	btree_apply_infix((btree_search_item(node5, "6", ft_strcmp)), ft_putstr);

	ft_putstr("\n");
	t_list *lst;

	lst = ft_create_elem(node1);
	ft_putnbr(btree_level_count(node5));
	btree_apply_by_level(node5, applyf);
	btree_pprint(node5);

}
