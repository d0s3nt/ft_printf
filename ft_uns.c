/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-farg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:36:23 by mel-farg          #+#    #+#             */
/*   Updated: 2023/11/26 06:30:17 by mel-farg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uns_count(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_uns(unsigned int c)
{
	int				count;
	char			*str;
	int				i;
	unsigned int	num;

	i = 0;
	num = c;
	count = uns_count(num);
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	str[count] = 0;
	while (i < count)
	{
		str[count - i++ - 1] = num % 10 + '0';
		num = num / 10;
	}
	ft_putstr(str);
	free(str);
	return (count);
}
