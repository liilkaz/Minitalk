#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	res;

	i = 0;
	m = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		m = -m;
		i++;
	}
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			res = res * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	return (res * m);
}

void	ft_putnbr(int n)
{
	char			i;
	unsigned int	V;

	if (n < 0)
	{
		V = n * -1;
		write(1, "-", 1);
	}
	else
		V = n;
	if (V >= 10)
		ft_putnbr(V / 10);
	i = (V % 10) + '0';
	write(1, &i, 1);
}

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
