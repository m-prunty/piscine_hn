
void    rush(int x, int y);
void    ft_putchar(char c);

extern int	g_rushn;

int	main(int ac, char *av)
{
	
	if (ac == 2)
		g_rushn = av[1] + 48;
	else
		g_rushn = 3;
	rush(5000000000000000, 300000000000);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	rush(0, 0);
}
