#include "../ft.h"

int	add(int i, int j)
{
	return (i + j);
}

int	sub(int i, int j)
{
	return (i - j);
}

int	mul(int i, int j)
{
	return (i * j);
}

int	div(int i, int j)
{
	return (i / j);
}

int	mod(int i, int j)
{
	return (i % j);
}

int	err(int i, int j)
{
	(void)i;
	(void)j;
	return (0);
}

typedef int (*do_op)(int, int);

do_op ops(char op)
{
	if (op == '+')
		return (add);
	else if (op == '-')
		return (sub);
	else if (op == '*')
		return (mul);
	else if (op == '/')
		return (div);
	else if (op == '%')
		return (mod);
	return (err);
 }

int	err_msg(char op)
{
	if (op == '/')
		ft_putstr("Stop : division by zero");
	else if (op == '%')
		ft_putstr("Stop : modulo by zero");
	return (1);
}

int	main(int ac, char **av)
{
	int 	val1;
	int 	val2;
	char	op;
	int		res;

	if (ac == 4)
	{
		val1 = ft_atoi(av[1]);
		val2 = ft_atoi(av[3]);
		op = *av[2];
		if (val2 == 0 && (op == '/' || op == '%'))
			return (err_msg(op));
		res = (ops(op)(val1, val2));
		ft_putnbr(res);
	}
	return (0);
}
