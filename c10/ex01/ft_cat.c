#include <unistd.h>
#include <fcntl.h>
#include "../ft.h" 

int ft_putsterr(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	ft_display_file(int fd)
{
	int	rd;
	char buf[10 + 1];

	rd = 1;
	while (rd)
	{
		rd = read(fd, buf, 10);
		buf[rd] = '\0';
		ft_putstr(buf);
	}
}
/*
int ft_read_stdin(void)
{

}
*/
int main(int ac, char **av)
{
	if (ac >= 2)
	{
		while (*++av)
		{
			if (**av == '-')
				ft_display_file(0);
			else
				ft_display_file(open(*av, O_RDONLY));
		}
	}	
	return (0);
}
