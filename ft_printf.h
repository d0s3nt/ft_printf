#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_int(int c);
int	ft_uns(unsigned int c);
int	ft_hexa(unsigned int num, char c);
int	ft_address(uintptr_t p);

#endif
