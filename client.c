#include "minitalk.h"

void	send_str(pid_t pid, char c)
{
	int	dec;

	dec = 128;
	while (dec > 0)
	{	
		if (c & dec)
		{
			if ((kill(pid, SIGUSR1)) == -1)
				ft_error("\033[0;31mNO SIGNAL\n");
		}
		else
		{
			if ((kill(pid, SIGUSR2)) == -1)
				ft_error("\033[0;31mNO SIGNAL\n");
		}
		dec /= 2;
		usleep(100);
	}
}

int	main (int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		if (pid == 0)
			ft_error("\033[0;31mIncorrect pid");
		else
		{
			str = argv[2];
			while (str[i] != '\0')
			{
				send_str(pid, str[i]);
				i++;
			}
			write(1, "\033[0;32mMessage sent\n", 22);
		}
	}
	else
		ft_error("\033[0;31mArgument error!");
}
