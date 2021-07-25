#include "minitalk.h"
#include <stdio.h>

void	sig_handler(int signum)
{
	static char	c = 0;
	static int	dec = 128;

	if (dec > 0)
	{
		if (signum == SIGUSR1)
			c = c + dec;
		dec /= 2;
	}
	if (dec == 0)
	{
		write(1, &c, 1);
		c = 0;
		dec = 128;
	}
}

int	main(void)
{
	write(1, "\033[0;33mPID: \033[0;36m", 20);
	ft_putnbr(getpid());
	write(1, "\n\033[0;35m", 8);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
