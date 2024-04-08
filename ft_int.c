#include "ft_printf.h"

static int	counter(long n, int *sign)
{
	int	count;

	*sign = 0;
	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
		*sign = 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_norm(char *str, int count)
{
	ft_putstr(str);
	free(str);
	return (count);
}

int	ft_int(int c)
{
	int		count;
	char	*str;
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = c;
	count = counter(num, &sign);
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	str[count] = 0;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (i < count - sign)
	{
		str[count - i++ - 1] = num % 10 + '0';
		num = num / 10;
	}
	return (ft_norm(str, count));
}
