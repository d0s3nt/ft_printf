/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-farg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:30:20 by mel-farg          #+#    #+#             */
/*   Updated: 2023/11/28 08:07:42 by mel-farg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char c, va_list ar)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(ar, int));
	else if (c == 's')
		len = ft_putstr(va_arg(ar, char *));
	else if (c == 'd' || c == 'i')
		len = ft_int(va_arg(ar, int));
	else if (c == 'u')
		len = ft_uns(va_arg(ar, unsigned int));
	else if (c == '%')
		len = ft_putchar('%');
	else if (c == 'p')
		len = ft_address(va_arg(ar, uintptr_t));
	else if (c == 'x' || c == 'X')
		len = ft_hexa(va_arg(ar, int), c);
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	ar;
	int		len;
	int		i;

	va_start(ar, string);
	len = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			len += check(string[i + 1], ar);
			i++;
		}
		else
			len += ft_putchar(string[i]);
		i++;
	}
	va_end(ar);
	return (len);
}
/*
int	main(void)
{
	//int i = 70000000000;
	//void *p = &i;
	//int d = ft_printf("%p\n", p);
	//printf("INTPTR_MAX : %ld", INTPTR_MAX);
	printf("   %kkjjh\n");
	ft_printf(" %kghgh");

	typedef struct {
	unsigned int gp_offset;
	unsigned int fp_offset;
	void *overflow_arg_area;
	void *reg_save_area;
    } va_list[1];
}*/