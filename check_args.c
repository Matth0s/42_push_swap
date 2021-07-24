/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:56:34 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 20:59:22 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnumbs(int n, char **str)
{
	int		i;
	int		j;

	i = 0;
	while (++i < n)
	{
		j = -1;
		if (*(*(str + i)) == '-' || *(*(str + i)) == '+')
			j++;
		while (*(*(str + i) + ++j))
			if (!(ft_isdigit(*(*(str + i) + j))))
				return (1);
	}
	return (0);
}

static int	isints(int n, char **str, t_stack *stack)
{
	double	num;
	int		i;

	i = 0;
	while (++i < n)
	{
		num = ft_atod(*(str + i));
		if (num < -2147483648 || num > 2147483647)
			return (1);
		stack->array[i - 1] = (int)num;
	}
	return (0);
}

static int	isrepeated(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++i < a->n)
	{
		k = -1;
		while (++k < j)
			if (a->array[i] == b->array[k])
				return (1);
		b->array[j] = a->array[i];
		j++;
	}
	return (0);
}

static void	replace_numbs(t_stack *a, t_stack *b)
{
	int	cont;
	int	i;
	int	j;

	i = -1;
	while (++i < a->n)
	{
		j = -1;
		cont = 0;
		while (++j < a->n)
			if (a->array[i] > a->array[j])
				cont++;
		b->array[i] = cont + 1;
	}
	i = -1;
	while (++i < a->n)
		a->array[i] = b->array[i];
}

int	check_args(int n, char **args, t_stack *a, t_stack *b)
{
	if (isnumbs(n, args))
		return (1);
	if (isints(n, args, a))
		return (1);
	if (isrepeated(a, b))
		return (1);
	replace_numbs(a, b);
	return (0);
}
