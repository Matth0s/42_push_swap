/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:44:26 by mmoreira          #+#    #+#             */
/*   Updated: 2021/07/22 03:50:40 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->n - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}

void	sorted_3(t_stack *a, t_stack *b)
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

void	sorted_5(t_stack *a, t_stack *b)
{
}

void	sorted_100(t_stack *a, t_stack *b)
{
}

void	sorted_500(t_stack *a, t_stack *b)
{
}
