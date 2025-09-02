#include <unistd.h>
#include <fcntl.h>
#include "../ft.h" 

int ft_putsterr(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	main(int ac, char **av)
{
	int	fd;
	int	rd;
	char buf[10 + 1];

	rd = 1;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (rd)
		{
			rd = read(fd, buf, 10);
			buf[rd] = '\0';
			ft_putstr(buf);
		}
	}
	else if (ac < 2)
		return (ft_putsterr("File name missing."));
	else
		return(ft_putsterr("Too many arguments."));
}
