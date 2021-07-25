#include "minitalk.h"

void	sigac(int signum, siginfo_t *sig, void *nothing)
{
	static char	c = 0;
	static int	dec = 128;

	(void)nothing;
	if (dec > 0)
	{
		if (signum == SIGUSR1)
			c = c + dec;
		dec >>= 1;
	}
	if (dec == 0)
	{
		if (c == '\n')
			kill(sig->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		dec = 128;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	write(1, "\033[0;33mPID: \033[0;36m", 20);
	ft_putnbr(getpid());
	write(1, "\n\033[0;35m", 8);
	sig.sa_sigaction = sigac;
	while (1)
	{
		sigaction (SIGUSR1, &sig, NULL);
		sigaction (SIGUSR2, &sig, NULL);
		pause();
	}
}
