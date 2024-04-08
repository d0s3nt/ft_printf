#include "ft_printf.h"

static int	ft_count_hexa(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	ft_printhex(char *str, char c)
{
	int	i;

	i = 0;
	if (c == 'x')
	{
		while (str[i])
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			i++;
		}
	}
	ft_putstr(str);
	free(str);
}

int	ft_hexa(unsigned int num, char c)
{
	const char	*h;
	char		*str;
	int			i;
	int			count;

	if (!num)
		return (ft_putchar('0'));
	h = "0123456789ABCDEF";
	i = 0;
	count = ft_count_hexa(num);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	str[count] = 0;
	while (num != 0)
	{
		str[count - i - 1] = h[num % 16];
		num /= 16;
		i++;
	}
	ft_printhex(str, c);
	return (count);
}
