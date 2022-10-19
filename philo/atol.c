/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:21:38 by xle-boul          #+#    #+#             */
/*   Updated: 2022/10/09 22:50:00 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#define LL_MAX 9223372036854775807

typedef struct s_atoi
{
	int						i;	
	long long				lln;
	char					*str_bis;
	int						sign;
}				t_atoi;
/* converts a string to corresponding integer */

static char	*ft_trim_string(const char *str, t_atoi *n)
{
	n->sign = 0;
	n->i = 1;
	if (!str)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n->sign++;
		str++;
	}
	if (n->sign % 2 != 0)
		n->i = -1;
	return ((char *)str);
}

long	ft_atol(const char *str)
{
	t_atoi	n;

	n.lln = 0;
	n.str_bis = ft_trim_string(str, &n);
	if (!n.str_bis)
		return (0);
	while (48 <= *n.str_bis && *n.str_bis <= 57)
	{
		if (n.i == 1 && (n.lln * 10 + (*n.str_bis - 48)) < n.lln)
			return (-1);
		if (n.i == -1 && (n.lln * 10 + (*n.str_bis - 48)) < n.lln)
			return (0);
		n.lln = n.lln * 10 + (*n.str_bis - 48);
		if (n.i == 1 && n.lln > LL_MAX)
			return (-1);
		else if (n.i == -1 && (unsigned long long)n.lln > (LL_MAX))
			return (0);
		n.str_bis++;
	}
	return (n.lln * n.i);
}
