#include <stdlib.h>
#include "../ft.h"

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int	*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * length);
	while (length--)
		res[i++] = f(*tab++);
	return (res);
}

int	opp_sign(int n)
{
	return (-n);
}

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	while (length--)
		f(*tab++);
}


int main()
{
	int tab[7] = {1 ,4,67,32424, 92183409,23094, 32498};
	int *tdelta;
	
	tdelta = ft_map(tab, 7, &opp_sign);
	ft_foreach(tdelta, 7 , &ft_putnbr);
}
