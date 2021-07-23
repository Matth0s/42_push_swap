/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_sorting_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:44:26 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/23 19:04:21 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_stack *stack, int inv)
{
	int	i;

	i = -1;
	while (++i < stack->n - 1)
	{
		if (!(inv) && stack->array[i] > stack->array[i + 1])
			return (0);
		if (inv && stack->array[i] < stack->array[i + 1])
			return (0);
	}
	return (1);
}

void	micro_sorting(t_stack *a, t_stack *b)
{
	if (check_sorting(a, 0))
		return ;
	else if (a->n == 2)
		sm(a, b, 'a');
	else
	{
		if (a->array[0] < a->array[1])
		{
			rrm(a, b, 'a');
			if (a->array[0] > a->array[1])
				sm(a, b, 'a');
		}
		else
		{
			if (a->array[0] < a->array[2])
				sm(a, b, 'a');
			else
			{
				rm(a, b, 'a');
				if (a->array[0] > a->array[1])
					sm(a, b, 'a');
			}
		}
	}
}

void	little_sorting(t_stack *a, t_stack *b)
{
	int	little;
	int	i;
	int	j;

	i = 0;
	little = get_little(a);
	while (a->n != 3 && ++little && ++i)
	{
		j = 0;
		while (a->array[j] != little - 1)
			j++;
		if (j <= a->n / 2)
			while (j--)
				rm(a, b, 'a');
		else
			while (j++ < a->n)
				rrm(a, b, 'a');
		pm(a, b, 'b');
	}
	micro_sorting(a, b);
	while (i--)
		pm(a, b, 'a');
}
