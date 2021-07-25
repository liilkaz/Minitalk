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
				ft_error("\033[0;31mNO SIGNAL");
		}
		else
		{
			if ((kill(pid, SIGUSR2)) == -1)
				ft_error("\033[0;31mNO SIGNAL");
		}
		dec >>= 1;
		usleep(100);
	}
}

void	deliverd(int signum)
{
	if (signum == SIGUSR1)
		write(1, "\033[0;32mMessage delivered\n", 26);
}

int	main (int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		i;

	i = -1;
	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		if (!pid)
			ft_error("\033[0;31mIncorrect PID");
		else
		{
			str = "\033[0;32mNEW MASSAGE: \033[0;35m";
			signal(SIGUSR1, deliverd);
			while (str[++i] != '\0')
				send_str(pid, str[i]);
			i = -1;
			while (argv[2][++i] != '\0')
				send_str(pid, argv[2][i]);
			write(1, "\033[0;33mMessage sent\n", 21);
			send_str(pid, '\n');
		}
	}
	else
		ft_error("\033[0;31mArgument error!");
}
