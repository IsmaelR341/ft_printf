/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireal-po <ireal-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:56 by ireal-po          #+#    #+#             */
/*   Updated: 2023/02/14 17:41:40 by ireal-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

static void	condition(char *p, va_list args, int *len)
{
	if (*p == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*p == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*p == '%')
		ft_putchar(va_arg(args, int), len);
}

int	ft_printf(char const *f, ...)
{
	va_list		args;
	int			count;
	char		*p;

	count = 0;
	p = (char *)f;
	va_start(args, f);
	//p = (char *)f;
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

int	main(void)
{
	char	caracter;
	char	frase[50] = "Hola caracola";
	int		contorig;
	int		mifunc;

	caracter = 'a';

	contorig = printf("caracteres: %c\n", caracter);
	printf("%i\n", contorig);

	mifunc = ft_printf("caracteres: %c\n", caracter);
	printf("%i\n", mifunc);

	mifunc = ft_printf("caracteres: %s\n", frase);
	printf("%i\n", mifunc);

	mifunc = ft_printf("caracteres: %\n", caracter);

	return (0);
}
