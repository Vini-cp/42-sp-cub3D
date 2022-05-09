/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:10:46 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:46:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	char	define_char(char f, char c)
{
	if (f == 's')
		return ('s');
	else if (f == 'p')
		return ('p');
	else if (f == 'c' || f == '%')
		return ('c');
	else if (f == 'u')
		return ('u');
	return (c);
}

static	char	*define_str(char *str)
{
	if (str)
		return (str);
	return (ft_strdup("(null)\0"));
}

static	int	define_len(char *str)
{
	if (str)
		return (ft_strlen(str));
	return (0);
}

void	to_string(const char *f, va_list args, t_flags ***lst)
{
	(**lst)->c = ' ';
	if (*f == 'd' || *f == 'i')
		(**lst)->str = ft_itoa(va_arg(args, int));
	else if (*f == 'c')
		(**lst)->print_c = (char)va_arg(args, int);
	else if (*f == 's')
		(**lst)->str = va_arg(args, char *);
	else if (*f == 'u')
		(**lst)->str = ft_utoa(va_arg(args, unsigned int), 10, 0);
	else if (*f == 'x')
		(**lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 0);
	else if (*f == 'X')
		(**lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 1);
	else if (*f == 'p')
		(**lst)->str = ft_ptoa(va_arg(args, uintptr_t), (**lst)->prec);
	else if (*f == '%')
		(**lst)->print_c = (*f);
	(**lst)->c = define_char(*f, (**lst)->c);
	(**lst)->str = define_str((**lst)->str);
	(**lst)->s_len = define_len((**lst)->str);
}
