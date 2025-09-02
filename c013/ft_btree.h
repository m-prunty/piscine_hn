#include "ft.h"

typedef struct s_btree 
{
	void *data;
	struct s_btree *right;
	struct s_btree *left;

}	t_btree;
