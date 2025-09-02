#include "../ft.h"

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = 0;
	while (--length && tab++)
		if(f(*(tab - 1), *tab) > 0)
			return (0);
	return (1);
}

int ft_intcmp(int i, int j)
{
	return (i - j);
}

int main()
{
	int tab[8] = {1 ,4, 4, 67, 32424, 92183409, 23094, 32498};
	ft_putnbr(ft_is_sort(tab, 6, &ft_intcmp));

}
