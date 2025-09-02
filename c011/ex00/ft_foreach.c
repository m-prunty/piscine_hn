#include "../ft.h"

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	while (length--)
		f(*tab++);
}

int main()
{
	int tab[7] = {1 ,4,67,32424, 92183409,23094, 32498};
	ft_foreach(tab, 7, &ft_putnbr);
}
