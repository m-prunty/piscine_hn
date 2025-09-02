#include "../ft.h"

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;

	i = 0;
	while (length--)
		if (f(*tab++))
			i++;
	return (i);
}


int main()
{
	char **tab = (char *[]){"jsahkjd", "","","","", 0};
	ft_putnum(ft_count_if(tab, 5, ft_strlen));
	//ft_foreach(tab, 7, &ft_putnbr);
}
