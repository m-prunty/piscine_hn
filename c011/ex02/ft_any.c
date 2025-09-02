
#include "../ft.h"
int ft_any(char **tab, int(*f)(char*))
{
	while (*tab)
		if (f(*tab++))
			return (1);
	return (0);
}


int main()
{
	char **tab = (char *[]){"", "", 0};
	ft_putnum(ft_any(tab,ft_strlen));
	//ft_foreach(tab, 7, &ft_putnbr);
}
