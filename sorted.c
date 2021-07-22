/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:44:26 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 14:22:34 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->n - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}

void	micro_sorting(t_stack *a, t_stack *b)
{
	if (a->n == 2)
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
	int little;
	int i;

	little = 0;
	while (a->n != 3 && ++little)
	{
		i = 0;
		while (a->array[i] != little)
			i++;
		if (i <= a->n/2)
			while (i--)
				rm(a, b, 'a');
		else
			while (i++ < a->n)
				rrm(a, b, 'a');
		pm(a, b, 'b');
	}
 	micro_sorted(a, b);
	while (little--)
		pm(a, b, 'a');
}

void	medium_sorting(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	return;
}

void	big_sorting(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	return;
}
