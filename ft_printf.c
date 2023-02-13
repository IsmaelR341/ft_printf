/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireal-po <ireal-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:56 by ireal-po          #+#    #+#             */
/*   Updated: 2023/02/13 19:55:15 by ireal-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_printf.h"*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void	condition(char *p, va_list args, int *len)
{
	if (*p == 'c')
	{
		ft_putchar(va_arg(args, int), len);
	}
}

int	ft_printf(char const *f, ...)
{
	va_list		args;
	int			count;
	char		*p;

	count = 0;
	p = (char *)f;
	va_start(args, f);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			condition(p, args, &count);
		}
		else
			ft_putchar(*p, &count);
		p += 1;
	}
	va_end(args);
	return (count);
}

int	main()
{
	char	f;
	
	char buscar[]= "Buscando el string";
	ft_printf("\n%c\n. Cantidad de : %c", 'h', 'l');
	return(0);
}
